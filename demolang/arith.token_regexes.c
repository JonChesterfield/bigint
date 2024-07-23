#include "arith.token.t"

// Regex table
const char*arith_token_regexes[arith_token_count] = {
  [arith_token_UNKNOWN] = ".|[\\x0a]",
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
  [arith_token_INCREMENT] = "inc",
  [arith_token_DECREMENT] = "dec",
  [arith_token_INTEGER] = "[-]\x3f[\x30-\x39]+",
  [arith_token_LPAREN] = "\\(",
  [arith_token_RPAREN] = "\\)",
  [arith_token_WHITESPACE] = "[\x20\x5c\x66\x5c\x6e\x5c\x72\x5c\x74\x5c\x76]+",
};
