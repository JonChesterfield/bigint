#ifndef BIGINT_INTERPRETER_H_INCLUDED
#define BIGINT_INTERPRETER_H_INCLUDED

#include "lexer.h"
#include "vtable.hpp"

namespace bigint
{
template <typename IntType>
IntType interp(vtable<IntType> const& vtab, const char *str, const char *lim);

template <typename IntType>
IntType interp_cstr(vtable<IntType> const& vtab, const char *str)
{
  return interp<IntType>(vtab, str, str + __builtin_strlen(str));
}

template <typename IntType>
IntType interp(vtable<IntType> const& vtab, const char *str, const char *lim)
{
  parse_result p = parse(str, lim);

  unsigned char arity = bigint_lexer_arity[p.op];
  IntType args[bigint_lexer_arity_maximum];
  for (unsigned i = 0; i < arity; i++)
  {
    args[i] = vtab.from_decimal(p.args[i].start, p.args[i].start + p.args[i].width);
    if (vtab.is_invalid(args[i]))
    {
      for (unsigned j = 0; j < i; j++)
      {
        vtab.destroy(args[j]);
      }
      return vtab.create_invalid();
    }
  }

  IntType res;
  switch(p.op)
  {
    default:
    case bigint_lexer_unknown:
    case bigint_lexer_whitespace:
    {
      res = vtab.create_invalid();
      break;
    }
    case bigint_lexer_number:
    {
      // number's opcode claims to have arity 1 so this is the only
      // element in args
      return args[0];
    }
    case bigint_lexer_absolute:
    {
      res = vtab.absolute
        ? vtab.absolute(args[0])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_negate:
    {
      res = vtab.negate
        ? vtab.negate(args[0])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_incr:
    {
      res = vtab.incr
        ? vtab.incr(args[0])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_decr:
    {
      res = vtab.decr
        ? vtab.decr(args[0])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_add:
    {
      res = vtab.add
        ? vtab.add(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_sub:
    {
      res = vtab.sub
        ? vtab.sub(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_mul:
    {
      res = vtab.mul
        ? vtab.mul(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_div:
    {
      res = vtab.div
        ? vtab.div(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_rem:
    {
      res = vtab.rem
        ? vtab.rem(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_shift_left:
    {
      res = vtab.shift_left
        ? vtab.shift_left(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_shift_right:
    {
      res = vtab.shift_right
        ? vtab.shift_right(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_bitwise_not:
    {
      res = vtab.bitwise_not
        ? vtab.bitwise_not(args[0])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_bitwise_or:
    {
      res = vtab.bitwise_or
        ? vtab.bitwise_or(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_bitwise_and:
    {
      res = vtab.bitwise_and
        ? vtab.bitwise_and(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_bitwise_xor:
    {
      res = vtab.bitwise_xor
        ? vtab.bitwise_xor(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_equal:
    {
      res = vtab.equal
        ? vtab.equal(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
    case bigint_lexer_cmp:
    {
      res = vtab.cmp
        ? vtab.cmp(args[0], args[1])
        : vtab.create_invalid();
      break;
    }
  }

  for (unsigned i = 0; i < arity; i++)
  {
    vtab.destroy(args[i]);
  }

  return res;
}

}
#endif // BIGINT_INTERPRETER_H_INCLUDED

