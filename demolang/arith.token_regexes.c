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
  [arith_token_CMP] = "cmp",
  [arith_token_ABSOLUTE] = "abs",
  [arith_token_NEGATE] = "neg",
  [arith_token_INCREMENT] = "incr",
  [arith_token_DECREMENT] = "decr",
  [arith_token_INTEGER] = "[\x30]\x7c[-]\x3f[\x31-\x39][\x30-\x39]*",
  [arith_token_SPACE] = "[\x20\x5c\x66\x5c\x72\x5c\x74\x5c\x76]+",
  [arith_token_NEWLINE] = "[\x20\x5c\x66\x5c\x6e\x5c\x72\x5c\x74\x5c\x76]*[\x5c\x6e]",
  [arith_token_CONTROL] = "[\x40\x41-\x5a\x21\x23\x24\x25\x26]+",
};
