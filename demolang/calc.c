#include "arith.h"
#include "arith.lexer.h"
#include "arith.parser.h"

// #include "arith.parse_state.h"

#include "arith.parser_lemon.h"
#include "arith.parser_lemon.t"

#include "../tools/io_buffer.h"

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

int calclib(const uint8_t *bytes, size_t N, bool verbose)
{
  {
    // Reject some strings with no chance of parsing before
    // allocating the parser instance
    lexer_summarise_res_t summary =
        arith_lexer_summarise_string((const char *)bytes, N);
    if ((summary.unknown != 0) || (summary.known == 0))
      {
        return 1;
      }
  }

  lexer_t lexer = arith_lexer_create();
  if (!arith_lexer_valid(lexer))
    {
      if (verbose) fprintf(stderr, "Failed to construct lexer\n");
      return 2;
    }

  arith_parser_lemon_state parser;
  arith_parser_lemon_initialize(&parser);
  struct arith_parse_state parse_state_lemon;
  parse_state_lemon.stored = proto_sentinel();

  for (lexer_iterator_t lexer_iterator =
           lexer_iterator_t_create((const char *)bytes, N);
       !lexer_iterator_t_empty(lexer_iterator);)
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
      proto_dump(lemon_res);
    }

  arith_parser_lemon_finalize(&parser);
  arith_lexer_destroy(lexer);

  return 0;
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

int calc_main(void)
{
  io_buffer *in = file_to_io_buffer(stdin);
  if (!in)
    {
      fprintf(stderr, "Failed to read stdin\n");
      return 1;
    }

  int rc = calclib((const unsigned char *)&in->data[0], in->N, true);

  free(in);

  return rc;
}

#if 0
int main(void) { return calc_main(); }
#endif