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
  arith_token_BITOR = 6,
  arith_token_BITAND = 7,
  arith_token_BITXOR = 8,
  arith_token_ABSOLUTE = 9,
  arith_token_NEGATE = 10,
  arith_token_INCREMENT = 11,
  arith_token_DECREMENT = 12,
  arith_token_INTEGER = 13,
  arith_token_LPAREN = 14,
  arith_token_RPAREN = 15,
  arith_token_WHITESPACE = 16,
};
enum { arith_token_count = 17 };


#endif // ARITH_TOKEN_T_INCLUDED
