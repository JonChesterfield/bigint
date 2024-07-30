#ifndef ARITH_TOKEN_T_INCLUDED
#define ARITH_TOKEN_T_INCLUDED

// This header should probably declare the arith_token_names vars, not the lexer
// Enumeration
enum arith_token {
  arith_token_UNKNOWN = 0,
  arith_token_PLUS = 1,
  arith_token_MINUS = 2,
  arith_token_TIMES = 3,
  arith_token_DIVIDE = 4,
  arith_token_REMAINDER = 5,
  arith_token_ASH = 6,
  arith_token_LSH = 7,
  arith_token_RSH = 8,
  arith_token_BITNOT = 9,
  arith_token_BITOR = 10,
  arith_token_BITAND = 11,
  arith_token_BITXOR = 12,
  arith_token_CMP = 13,
  arith_token_ABSOLUTE = 14,
  arith_token_NEGATE = 15,
  arith_token_INCREMENT = 16,
  arith_token_DECREMENT = 17,
  arith_token_INTEGER = 18,
  arith_token_SPACE = 19,
  arith_token_NEWLINE = 20,
  arith_token_CONTROL = 21,
};
enum { arith_token_count = 22 };


#endif // ARITH_TOKEN_T_INCLUDED
