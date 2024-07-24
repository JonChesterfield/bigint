#include "../vendor/EvilUnit/EvilUnit.h"

#include "calc.h"

#include "arith.h"
#include "arith.lexer.h"
#include "arith.parser.h"

#include "arith.parser_lemon.h"
#include "arith.parser_lemon.t"

static int print_token(lexer_token_t s)
{
  if (s.id < arith_token_count)
    {
      bool discard = arith_lexer_discard_token(s.id);
      fprintf(stderr, "<LexerToken = \"%s\" discard=\"%s\" value = \"",
              arith_token_names[s.id], (discard ? "true" : "false"));
    }
  else
    {
      fprintf(stderr, "<LexerToken = invalid:\"%lu\" value = \"", s.id);
    }

  const char *c = s.value;
  size_t w = s.width;
  for (size_t i = 0; i < w; i++)
    {
      fprintf(stderr, "%c", *c++);
    }

  fprintf(stderr, "\" />\n");
  return 0;
}

static bool sequence_known_control_block(const uint8_t *bytes, size_t N)
{
  lexer_t lexer = arith_lexer_create();
  if (!arith_lexer_valid(lexer))
    {
      return false;
    }

  bool res = true;

  lexer_iterator_t lexer_iterator =
      lexer_iterator_t_create((const char *)bytes, N);

  if (lexer_iterator_t_empty(lexer_iterator))
    {
      res = false;
      goto done;
    }
  lexer_token_t control_token =
      arith_lexer_iterator_step(lexer, &lexer_iterator);
  if (control_token.id != arith_token_CONTROL)
    {
      res = false;
      goto done;
    }

  if (lexer_iterator_t_empty(lexer_iterator))
    {
      res = false;
      goto done;
    }
  lexer_token_t space_token = arith_lexer_iterator_step(lexer, &lexer_iterator);
  if (space_token.id != arith_token_SPACE)
    {
      res = false;
      goto done;
    }

  res = true;

done:
  arith_lexer_destroy(lexer);
  return res;
}

int calclib_repeat(const uint8_t *bytes, size_t N, bool verbose,
                   bool on_second_try)
{
  // Reject strings with no chance of parsing before allocating the parser
  // instance
  if (!arith_lexer_bytes_are_lexeme_stream((const char *)bytes, N))
    {
      return 1;
    }

  lexer_t lexer = arith_lexer_create();
  if (!arith_lexer_valid(lexer))
    {
      if (verbose) fprintf(stderr, "Failed to construct lexer\n");
      return 2;
    }

  const bool have_control = sequence_known_control_block(bytes, N);

  arith_parser_lemon_state parser;
  arith_parser_lemon_initialize(&parser);
  struct arith_parse_state parse_state_lemon;
  parse_state_lemon.stored = proto_sentinel();

  uint64_t malloc_state = UINT64_MAX;
  parse_state_lemon.context = (proto_context){.malloc_state = &malloc_state};

  lexer_iterator_t lexer_iterator =
      lexer_iterator_t_create((const char *)bytes, N);

  if (on_second_try)
    {
      if (!have_control)
        {
          return 6;
        }
      // First time around we ran out of memory. That limit is encoded
      // in the first two tokens. Throw those away to see if the case would
      // have been interesting if we didn't run out of memory
      arith_lexer_iterator_step(lexer, &lexer_iterator);
      arith_lexer_iterator_step(lexer, &lexer_iterator);
    }

  while (!lexer_iterator_t_empty(lexer_iterator))
    {
      lexer_token_t lexer_token =
          arith_lexer_iterator_step(lexer, &lexer_iterator);

      if (arith_lexer_discard_token(lexer_token.id))
        {
          continue;
        }

      if (!arith_lexer_identifier_valid_token(lexer_token.id))
        {
          if (verbose)
            {
              fprintf(stderr, "Invalid token\n");
              print_token(lexer_token);
            }
          arith_parser_lemon_finalize(&parser);
          arith_lexer_destroy(lexer);
          return 3;
        }

      token lemon_token = token_create(arith_token_names[lexer_token.id],
                                       lexer_token.value, lexer_token.width);

      bool lemon_parse_ok = arith_parser_lemon_parse(
          &parse_state_lemon, &parser, (int)lexer_token.id, lemon_token);
      if (lemon_parse_ok)
        {
          if (verbose) print_token(lexer_token);
        }
      else
        {
          if (verbose)
            {
              fprintf(stderr, "parser rejected token\n");
              print_token(lexer_token);
            }
          arith_parser_lemon_finalize(&parser);
          arith_lexer_destroy(lexer);
          return 4;
        }
    }

  proto lemon_res = arith_parser_lemon_tree(&parse_state_lemon, &parser);
  if (verbose)
    {
      proto_dump(parse_state_lemon.context, lemon_res);
    }

  bool parse_success = proto_valid(parse_state_lemon.context, lemon_res);
  bool hit_oom = (malloc_state == 0);

  proto_destroy(parse_state_lemon.context, lemon_res);
  arith_parser_lemon_finalize(&parser);
  arith_lexer_destroy(lexer);

  if (hit_oom)
    {
      // Ran out of memory, would it have been interesting if we didn't run out?
      if (!on_second_try)
        {
          int res = calclib_repeat(bytes, N, verbose, true);
          if (res == 0)
            {
              // It parses correctly without the control block, good oom case
              return 0;
            }
          else
            {
              // Hit oom, but would have died anyway
              return res;
            }
        }

      // Hit oom with the control block disabled? Shouldn't be possible, keep
      // the case
      return 0;
    }

  if (!hit_oom && have_control)
    {
      // have a control block which didn't take effect, uninteresting
      return 5;
    }

  if (parse_success && !have_control)
    {
      // no control block, expression correct, keep it
      return 0;
    }

  return 6;
}

int calclib(const uint8_t *bytes, size_t N, bool verbose)
{
  return calclib_repeat(bytes, N, verbose, false);
}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
  int rc = calclib(Data, Size, false);
  if (rc == 0)
    {
      return 0;  // accept
    }
  else
    {
      return -1;  // reject
    }
}

static uint32_t step_rand(uint64_t *seed)
{
  uint64_t tmp = 6364136223846793005ULL * (*seed) + 1;
  uint32_t res = tmp >> 32u;
  *seed = tmp;
  return res;
}

static uint32_t rand_below(uint64_t *seed, uint32_t N)
{
  const uint32_t rand_max = UINT32_MAX;

  // a large range which is evenly divisable by N
  const uint32_t range = (rand_max - rand_max % N);

  // get a random number in said range without further biasing it
  uint32_t x;
  do
    {
      x = step_rand(seed);
    }
  while (x >= range);

  return x % N;
}

static size_t bytes_from(lexer_t lexer, lexer_iterator_t iter)
{
  if (lexer_iterator_t_empty(iter))
    {
      return 0;
    }
  lexer_match_t m = arith_lexer_sequence_regex_bytes_matching(lexer, iter);
  if (m.regex_id == arith_token_count) return 0;
  return m.bytes_count;
}

static void step_iter(lexer_iterator_t *iter, size_t by) { iter->cursor += by; }

static size_t Inner_LLVMFuzzerCustomCrossOver(
    const uint8_t *Data1, size_t Size1, const uint8_t *Data2, size_t Size2,
    uint8_t *Out, size_t MaxOutSize, unsigned int SeedIn)
{
  uint64_t rand_state = SeedIn;

  lexer_t lexer = arith_lexer_create();
  lexer_iterator_t iter1 = lexer_iterator_t_create((const char *)Data1, Size1);
  lexer_iterator_t iter2 = lexer_iterator_t_create((const char *)Data2, Size2);

  enum choices
  {
    copy_from_1 = 0,
    copy_from_2,
    skip_1,
    skip_2,
    copy_then_move_1,
    copy_then_move_2,

    choices_below = copy_then_move_2 + 1,
  };

  size_t bytes_written = 0;

  struct
  {
    size_t Data1;
    size_t Data2;
    size_t Out;
  } count = {0};

  uint32_t C = 0;
  while (true)
    {
      C = rand_below(&rand_state, choices_below);
    hack:;

      switch (C)
        {
          default:
            continue;

          case copy_from_1:
          case copy_from_2:
            {
              bool is_one = C == copy_from_1;
              lexer_iterator_t *iter = is_one ? &iter1 : &iter2;

              size_t N = bytes_from(lexer, *iter);
              if (N == 0) goto no_more_lexemes;
              if (N > MaxOutSize) return bytes_written;
              memcpy(Out, iter->cursor, N);
              Out += N;
              MaxOutSize -= N;
              bytes_written += N;
              count.Out++;
              is_one ? count.Data1++ : count.Data2++;
            }

          case skip_1:
          case skip_2:
            {
              bool is_one = C == skip_1;
              lexer_iterator_t *iter = is_one ? &iter1 : &iter2;
              size_t N = bytes_from(lexer, *iter);
              if (N == 0) goto no_more_lexemes;
              step_iter(iter, N);
              is_one ? count.Data1++ : count.Data2++;
              break;
            }

          case copy_then_move_1:
          case copy_then_move_2:
            {
              bool is_one = C == copy_then_move_1;
              lexer_iterator_t *iter = is_one ? &iter1 : &iter2;

              size_t N = bytes_from(lexer, *iter);
              if (N == 0) goto no_more_lexemes;
              if (N > MaxOutSize) return bytes_written;
              memcpy(Out, iter->cursor, N);
              Out += N;
              MaxOutSize -= N;
              bytes_written += N;

              step_iter(iter, N);

              count.Out++;
              is_one ? count.Data1++ : count.Data2++;
              break;
            }
        }
    }

no_more_lexemes:;

  // If we have at least as many tokens as we've taken from the output, all good
  if (count.Out >= (count.Data1 + count.Data2))
    {
      return bytes_written;
    }

  size_t avail1 = bytes_from(lexer, iter1);
  size_t avail2 = bytes_from(lexer, iter2);

  // Otherwise copy from whichever stream is not yet exhausted
  if ((avail1 == 0) && (avail2 == 0))
    {
      return bytes_written;
    }

  C = (avail1 != 0) ? copy_then_move_1 : copy_then_move_2;
  goto hack;
}

size_t LLVMFuzzerCustomCrossOver(const uint8_t *Data1, size_t Size1,
                                 const uint8_t *Data2, size_t Size2,
                                 uint8_t *Out, size_t MaxOutSize,
                                 unsigned int SeedIn)
{
  bool initial_valid =
      arith_lexer_bytes_are_lexeme_stream((const char *)Data1, Size1) &&
      arith_lexer_bytes_are_lexeme_stream((const char *)Data2, Size2);

  size_t res = Inner_LLVMFuzzerCustomCrossOver(Data1, Size1, Data2, Size2, Out,
                                               MaxOutSize, SeedIn);
  
  assert(res <= MaxOutSize);
  if (initial_valid)
    {
      assert(arith_lexer_bytes_are_lexeme_stream((const char *)Out, res));
    }

  return res;
}

EVILUNIT_MODULE(calc)
{
  TEST("passing cases")
  {
    const char *cases[] = {
        "add 3 4\n",
        "9 add 4 5\n",
        "4 sub 10 6\n",
        "ABC 10 add 5 5\n",
    };
    size_t N = sizeof(cases) / sizeof(cases[0]);
    for (size_t i = 0; i < N; i++)
      {
        CHECK(0 == calclib((const unsigned char *)cases[i],
                           __builtin_strlen(cases[i]), false));
      }
  }
}
