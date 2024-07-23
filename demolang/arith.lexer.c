#include "arith.lexer.h"

#if ARITH_LEXER_POSIX_ENABLE
#include "../tools/lexer.posix.h"
#endif
#if ARITH_LEXER_RE2_ENABLE
#include "../tools/lexer.re2.h"
#endif
#if ARITH_LEXER_RE2C_ENABLE
#include "../tools/lexer.re2c.h"
#endif
#if ARITH_LEXER_INTERP_ENABLE
#include "../tools/lexer.interp.h"
#endif
#if ARITH_LEXER_A2PI_ENABLE
#include "../tools/lexer.a2pi.h"
#endif

enum arith_token
arith_lexer_try_string_to_token(const lexer_function_table_t *tab, lexer_t lexer, const char * bytes, size_t N)
{
  enum arith_token res = arith_token_UNKNOWN;

  if (!tab->valid(lexer))
  {
    return res;
  }

  lexer_iterator_t iter = lexer_iterator_t_create(bytes, N);
  if (!lexer_iterator_t_empty(iter))
  {
    lexer_token_t tok = tab->iterator_step(lexer, &iter);
    if (tok.width == N &&tok.value == bytes)
    {
      if (arith_lexer_identifier_valid_token(tok.id))
      {
        res = tok.id;
      }
    }
#if 0
    else
    {
      printf("(tok.width == N && tok.value == bytes) = (%lu == %lu && %u),\n",tok.width, N, tok.value == bytes);
    }
#endif
  }

  return res;
}

bool arith_lexer_string_lexes_to_token(const char *cstr, enum arith_token req)
{
  lexer_t lexer = arith_lexer_create();
  if (!arith_lexer_valid(lexer))
  {
    return false;
  }
  size_t N = __builtin_strlen(cstr);

  enum arith_token tok = arith_lexer_try_string_to_token(&arith_lexer_table, lexer, cstr, N);

  arith_lexer_destroy(lexer);
  return tok == req;
}

lexer_summarise_res_t arith_lexer_summarise_string(const char * bytes, size_t N)

{
  lexer_summarise_res_t res = {0, 0, 0};
  lexer_t lexer = arith_lexer_create();
  if (!arith_lexer_valid(lexer))
  {
    return res;
  }

  lexer_iterator_t iter = lexer_iterator_t_create(bytes, N);
  while (!lexer_iterator_t_empty(iter))
  {
    lexer_token_t tok = arith_lexer_iterator_step(lexer, &iter);
    if (arith_lexer_identifier_valid_token(tok.id))
    {
      res.known++;
    }
    else if (arith_lexer_discard_token(tok.id))
    {
      res.discard++;
    }
    else
    {
      res.unknown++;
    }
  }
  arith_lexer_destroy(lexer);

  return res;
}


// Names table
// Moved to arith.token_names.c

// Regex table
// Moved to arith.token_regexes.c

// Language regex table
static __attribute__((unused))const char*arith_language_regexes[arith_token_count] = {
  [arith_token_UNKNOWN] = ".|[\\x0a]",
  [arith_token_PLUS] = 0,
  [arith_token_MINUS] = 0,
  [arith_token_TIMES] = 0,
  [arith_token_DIVIDE] = 0,
  [arith_token_REMAINDER] = 0,
  [arith_token_BITOR] = 0,
  [arith_token_BITAND] = 0,
  [arith_token_BITXOR] = 0,
  [arith_token_ABSOLUTE] = 0,
  [arith_token_NEGATE] = 0,
  [arith_token_INCREMENT] = 0,
  [arith_token_DECREMENT] = 0,
  [arith_token_INTEGER] = "[-]\x3f[\x30-\x39]+",
  [arith_token_SPACE] = 0,
  [arith_token_NEWLINE] = 0,
  [arith_token_CONTROL] = "[\x40\x41-\x5a\x21\x23\x24\x25\x26]+",
};
// Language literals table
static __attribute__((unused))const char*arith_language_literals[arith_token_count] = {
  [arith_token_UNKNOWN] = 0,
  [arith_token_PLUS] = "add",
  [arith_token_MINUS] = "sub",
  [arith_token_TIMES] = "mul",
  [arith_token_DIVIDE] = "div",
  [arith_token_REMAINDER] = "rem",
  [arith_token_BITOR] = "or",
  [arith_token_BITAND] = "and",
  [arith_token_BITXOR] = "xor",
  [arith_token_ABSOLUTE] = "abs",
  [arith_token_NEGATE] = "neg",
  [arith_token_INCREMENT] = "incr",
  [arith_token_DECREMENT] = "decr",
  [arith_token_INTEGER] = 0,
  [arith_token_SPACE] = 0,
  [arith_token_NEWLINE] = 0,
  [arith_token_CONTROL] = 0,
};

// Language hex literals table
static __attribute__((unused))const char*arith_language_hex_literals[arith_token_count] = {
  [arith_token_UNKNOWN] = 0,
  [arith_token_PLUS] = 0,
  [arith_token_MINUS] = 0,
  [arith_token_TIMES] = 0,
  [arith_token_DIVIDE] = 0,
  [arith_token_REMAINDER] = 0,
  [arith_token_BITOR] = 0,
  [arith_token_BITAND] = 0,
  [arith_token_BITXOR] = 0,
  [arith_token_ABSOLUTE] = 0,
  [arith_token_NEGATE] = 0,
  [arith_token_INCREMENT] = 0,
  [arith_token_DECREMENT] = 0,
  [arith_token_INTEGER] = 0,
  [arith_token_SPACE] = "\\x20",
  [arith_token_NEWLINE] = "\\x0a",
  [arith_token_CONTROL] = 0,
};

// Lexer instantiations
#if ARITH_LEXER_POSIX_ENABLE
lexer_t arith_lexer_posix_create(void)
{
  return lexer_posix_create(arith_token_count, arith_token_regexes);
}

void arith_lexer_posix_destroy(lexer_t lex)
{
  lexer_posix_destroy(lex);
}

bool arith_lexer_posix_valid(lexer_t lex)
{
  return lexer_posix_valid(lex);
}

size_t arith_lexer_posix_regex_count(lexer_t lex)
{
  (void)lex;
  return arith_token_count;
}

lexer_match_t arith_lexer_posix_single_regex_bytes_matching(lexer_t lex, size_t regex_idx, lexer_iterator_t iter)
{
  return lexer_posix_single_regex_bytes_matching(lex, regex_idx, iter);
}

lexer_match_t arith_lexer_posix_sequence_regex_bytes_matching(lexer_t lex, lexer_iterator_t iter)
{
  return lexer_posix_sequence_regex_bytes_matching(lex, iter);
}

lexer_token_t arith_lexer_posix_iterator_step(lexer_t lex, lexer_iterator_t *iter)
{
  return lexer_posix_iterator_step(lex, iter);
}

#endif

#if ARITH_LEXER_RE2_ENABLE
lexer_t arith_lexer_re2_create(void)
{
  return lexer_re2_create(arith_token_count, arith_token_regexes);
}

void arith_lexer_re2_destroy(lexer_t lex)
{
  lexer_re2_destroy(lex);
}

bool arith_lexer_re2_valid(lexer_t lex)
{
  return lexer_re2_valid(lex);
}

size_t arith_lexer_re2_regex_count(lexer_t lex)
{
  (void)lex;
  return arith_token_count;
}

lexer_match_t arith_lexer_re2_single_regex_bytes_matching(lexer_t lex, size_t regex_idx, lexer_iterator_t iter)
{
  return lexer_re2_single_regex_bytes_matching(lex, regex_idx, iter);
}

lexer_match_t arith_lexer_re2_sequence_regex_bytes_matching(lexer_t lex, lexer_iterator_t iter)
{
  return lexer_re2_sequence_regex_bytes_matching(lex, iter);
}

lexer_token_t arith_lexer_re2_iterator_step(lexer_t lex, lexer_iterator_t *iter)
{
  return lexer_re2_iterator_step(lex, iter);
}

#endif

#if ARITH_LEXER_RE2C_ENABLE
lexer_t arith_lexer_re2c_create(void)
{
  return lexer_re2c_create(arith_token_count, arith_token_regexes);
}

void arith_lexer_re2c_destroy(lexer_t lex)
{
  lexer_re2c_destroy(lex);
}

bool arith_lexer_re2c_valid(lexer_t lex)
{
  return lexer_re2c_valid(lex);
}

size_t arith_lexer_re2c_regex_count(lexer_t lex)
{
  (void)lex;
  return arith_token_count;
}
#include "arith.lexer_re2c_iterator.data"
#endif

#if ARITH_LEXER_INTERP_ENABLE
lexer_t arith_lexer_interp_create(void)
{
  return lexer_interp_create(arith_token_count, arith_token_regexes);
}

void arith_lexer_interp_destroy(lexer_t lex)
{
  lexer_interp_destroy(lex);
}

bool arith_lexer_interp_valid(lexer_t lex)
{
  return lexer_interp_valid(lex);
}

size_t arith_lexer_interp_regex_count(lexer_t lex)
{
  (void)lex;
  return arith_token_count;
}

lexer_match_t arith_lexer_interp_single_regex_bytes_matching(lexer_t lex, size_t regex_idx, lexer_iterator_t iter)
{
  return lexer_interp_single_regex_bytes_matching(lex, regex_idx, iter);
}

lexer_match_t arith_lexer_interp_sequence_regex_bytes_matching(lexer_t lex, lexer_iterator_t iter)
{
  return lexer_interp_sequence_regex_bytes_matching(lex, iter);
}

lexer_token_t arith_lexer_interp_iterator_step(lexer_t lex, lexer_iterator_t *iter)
{
  return lexer_interp_iterator_step(lex, iter);
}

#endif

#if ARITH_LEXER_A2PI_ENABLE
lexer_t arith_lexer_a2pi_create(void)
{
  return lexer_a2pi_create(arith_token_count, arith_token_prefix_regexes);
}

void arith_lexer_a2pi_destroy(lexer_t lex)
{
  lexer_a2pi_destroy(lex);
}

bool arith_lexer_a2pi_valid(lexer_t lex)
{
  return lexer_a2pi_valid(lex);
}

size_t arith_lexer_a2pi_regex_count(lexer_t lex)
{
  (void)lex;
  return arith_token_count;
}

lexer_match_t arith_lexer_a2pi_single_regex_bytes_matching(lexer_t lex, size_t regex_idx, lexer_iterator_t iter)
{
  return lexer_a2pi_single_regex_bytes_matching(lex, regex_idx, iter);
}

lexer_match_t arith_lexer_a2pi_sequence_regex_bytes_matching(lexer_t lex, lexer_iterator_t iter)
{
  return lexer_a2pi_sequence_regex_bytes_matching(lex, iter);
}

lexer_token_t arith_lexer_a2pi_iterator_step(lexer_t lex, lexer_iterator_t *iter)
{
  return lexer_a2pi_iterator_step(lex, iter);
}

#endif


// Lexer using engine a2pc
#if !ARITH_LEXER_A2PC_ENABLE
#error "Default arith engine a2pc is not enabled"
#endif
lexer_t arith_lexer_create(void) { return arith_lexer_a2pc_create(); }
void arith_lexer_destroy(lexer_t lex) { arith_lexer_a2pc_destroy(lex); }
bool arith_lexer_valid(lexer_t lex) { return arith_lexer_a2pc_valid(lex); }
size_t arith_lexer_regex_count(lexer_t lex) { return arith_lexer_a2pc_regex_count(lex); }
lexer_match_t arith_lexer_single_regex_bytes_matching(lexer_t lex, size_t regex_id, lexer_iterator_t iter) { return arith_lexer_a2pc_single_regex_bytes_matching(lex, regex_id, iter); }
lexer_match_t arith_lexer_sequence_regex_bytes_matching(lexer_t lex, lexer_iterator_t iter) { return arith_lexer_a2pc_sequence_regex_bytes_matching(lex, iter); }
lexer_token_t arith_lexer_iterator_step(lexer_t lex, lexer_iterator_t *iter) { return arith_lexer_a2pc_iterator_step(lex, iter); }

// No tokens are discarded, define the symbol anyway
bool arith_lexer_discard_token(enum arith_token id)
{
  (void)id;
  return false;
}
