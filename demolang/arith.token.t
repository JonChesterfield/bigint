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
  arith_token_INTEGER = 6,
  arith_token_LPAREN = 7,
  arith_token_RPAREN = 8,
  arith_token_WHITESPACE = 9,
};
enum { arith_token_count = 10 };


#endif // ARITH_TOKEN_T_INCLUDED
