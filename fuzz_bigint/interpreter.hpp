#ifndef BIGINT_INTERPRETER_H_INCLUDED
#define BIGINT_INTERPRETER_H_INCLUDED

#include "lexer.h"
#include "bigint.hpp"

namespace bigint
{
template <typename IntType>
IntType interp(const char *str, const char *lim);

template <typename IntType>
IntType interp_cstr(const char *str)
{
  return interp<IntType>(str, str + __builtin_strlen(str));
}

template <typename IntType>
IntType interp(const char *str, const char *lim)
{
  parse_result p = parse(str, lim);

  unsigned char arity = bigint_lexer_arity[p.op];
  IntType args[bigint_lexer_arity_maximum];
  for (unsigned i = 0; i < arity; i++)
  {
    args[i] = bigint::from_decimal<IntType>(p.args[i].start, p.args[i].start + p.args[i].width);
  }

  IntType res;
  switch(p.op)
  {
    default:
    case bigint_lexer_unknown:
    case bigint_lexer_number: // might let this be valid
    case bigint_lexer_whitespace:
    {
     res = bigint::create_invalid<IntType>();
     break;
    }
    case bigint_lexer_abs: { res = bigint::abs(args[0]); }
    case bigint_lexer_neg: { res = bigint::neg(args[0]); }
    case bigint_lexer_incr: { res = bigint::incr(args[0]); }
    case bigint_lexer_decr: { res = bigint::decr(args[0]); }
    case bigint_lexer_add: { res = bigint::add(args[0] ,args[1]); }
    case bigint_lexer_sub: { res = bigint::sub(args[0] ,args[1]); }
    case bigint_lexer_mul: { res = bigint::mul(args[0] ,args[1]); }
    case bigint_lexer_div: { res = bigint::div(args[0] ,args[1]); }
    case bigint_lexer_rem: { res = bigint::rem(args[0] ,args[1]); }
    case bigint_lexer_lsh: { res = bigint::lsh(args[0] ,args[1]); }
    case bigint_lexer_rsh: { res = bigint::rsh(args[0] ,args[1]); }
    case bigint_lexer_bitwise_not: { res = bigint::bitwise_not(args[0]); }
    case bigint_lexer_bitwise_or: { res = bigint::bitwise_or(args[0] ,args[1]); }
    case bigint_lexer_bitwise_and: { res = bigint::bitwise_and(args[0] ,args[1]); }
    case bigint_lexer_bitwise_xor: { res = bigint::bitwise_xor(args[0] ,args[1]); }
    // todo: equal
    // todo: cmp
  }

  for (unsigned i = 0; i < arity; i++)
  {
     // deallocate?
  }

  return res;
}

}
#endif // BIGINT_INTERPRETER_H_INCLUDED

