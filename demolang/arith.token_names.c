#include "arith.token.t"

// Names table
const char*arith_token_names[arith_token_count] = {
  [arith_token_UNKNOWN] = "UNKNOWN",
  [arith_token_PLUS] = "PLUS",
  [arith_token_MINUS] = "MINUS",
  [arith_token_TIMES] = "TIMES",
  [arith_token_DIVIDE] = "DIVIDE",
  [arith_token_REMAINDER] = "REMAINDER",
  [arith_token_BITOR] = "BITOR",
  [arith_token_BITAND] = "BITAND",
  [arith_token_BITXOR] = "BITXOR",
  [arith_token_CMP] = "CMP",
  [arith_token_ABSOLUTE] = "ABSOLUTE",
  [arith_token_NEGATE] = "NEGATE",
  [arith_token_INCREMENT] = "INCREMENT",
  [arith_token_DECREMENT] = "DECREMENT",
  [arith_token_INTEGER] = "INTEGER",
  [arith_token_SPACE] = "SPACE",
  [arith_token_NEWLINE] = "NEWLINE",
  [arith_token_CONTROL] = "CONTROL",
};
