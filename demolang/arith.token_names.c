#include "arith.token.t"

// Names table
const char*arith_token_names[arith_token_count] = {
  [arith_token_UNKNOWN] = "UNKNOWN",
  [arith_token_PLUS] = "PLUS",
  [arith_token_MINUS] = "MINUS",
  [arith_token_TIMES] = "TIMES",
  [arith_token_DIVIDE] = "DIVIDE",
  [arith_token_REMAINDER] = "REMAINDER",
  [arith_token_INTEGER] = "INTEGER",
  [arith_token_LPAREN] = "LPAREN",
  [arith_token_RPAREN] = "RPAREN",
  [arith_token_WHITESPACE] = "WHITESPACE",
};
