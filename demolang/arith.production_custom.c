#include "arith.lexer.h"
#include "arith.parser.h"
#include "arith.productions.h"

proto arith_custom_production_FromInteger(struct arith_parse_state* ctx,
                                          token /*INTEGER*/ x1)
{
  (void)ctx;

  size_t width = token_width(x1);
  const char* bytes = token_value(x1);
  if (width == 0)
    {
      proto_create_invalid();
    }

  bool neg = bytes[0] == '-';
  if (neg)
    {
      if (width == 1)
        {
          proto_create_invalid();
        }
      bytes++;
      width--;
    }

  proto acc = proto_create(1);
  if (!proto_is_zero(acc)) return proto_create_invalid();

  proto ten = proto_from_u32(10);
  if (!proto_valid(ten))
    {
      return proto_create_invalid();
    }
  for (size_t i = 0; i < width; i++)
    {
      char b = (bytes[i] - '0');
      if (b < 0 || b > 9)
        {
          proto_destroy(acc);
          proto_destroy(ten);
          return proto_create_invalid();
        }

      {
        proto tmp = proto_mul(acc, ten);
        if (!proto_valid(tmp)) return proto_create_invalid();
        proto_destroy(acc);
        acc = tmp;
      }

      {
        proto addend = proto_from_u32((unsigned)b);
        if (!proto_valid(addend)) return proto_create_invalid();
        proto tmp = proto_add(acc, addend);
        if (!proto_valid(tmp)) return proto_create_invalid();
        proto_destroy(addend);
        proto_destroy(acc);
        acc = tmp;
      }
    }

  proto_destroy(ten);

  if (neg)
    {
      proto tmp = proto_neg(acc);
      proto_destroy(acc);
      acc = tmp;
    }

  return acc;
}

proto arith_custom_production_BinOpPlus(struct arith_parse_state* ctx,
                                        token /*PLUS*/ x1, proto /*expr*/ x2,
                                        proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_add(x2, x3);
}

// CustomProduction BinOpMinus -> arith_grouping_expr
proto arith_custom_production_BinOpMinus(struct arith_parse_state* ctx,
                                         token /*MINUS*/ x1, proto /*expr*/ x2,
                                         proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_sub(x2, x3);
}

// CustomProduction BinOpTimes -> arith_grouping_expr
proto arith_custom_production_BinOpTimes(struct arith_parse_state* ctx,
                                         token /*TIMES*/ x1, proto /*expr*/ x2,
                                         proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_mul(x2, x3);
}

// CustomProduction BinOpDivide -> arith_grouping_expr
proto arith_custom_production_BinOpDivide(struct arith_parse_state* ctx,
                                          token /*DIVIDE*/ x1,
                                          proto /*expr*/ x2, proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_div(x2, x3);
}

// CustomProduction BinOpModulo -> arith_grouping_expr
proto arith_custom_production_BinOpRemainder(struct arith_parse_state* ctx,
                                             token /*REMAINDER*/ x1,
                                             proto /*expr*/ x2,
                                             proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_rem(x2, x3);
}

proto arith_custom_production_BinOpBitOr(struct arith_parse_state* ctx,
                                         token /*BITOR*/ x1, proto /*expr*/ x2,
                                         proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_or(x2, x3);
}

proto arith_custom_production_BinOpBitAnd(struct arith_parse_state* ctx,
                                         token /*BITAND*/ x1, proto /*expr*/ x2,
                                         proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_and(x2, x3);
}

proto arith_custom_production_BinOpBitXor(struct arith_parse_state* ctx,
                                         token /*BITXOR*/ x1, proto /*expr*/ x2,
                                         proto /*expr*/ x3)
{
  (void)ctx;
  (void)x1;
  return proto_xor(x2, x3);
}


proto arith_custom_production_UnOpAbsolute(struct arith_parse_state* ctx,
                                        token /*ABSOLUTE*/ x1, proto /*expr*/ x2)
{
  (void)ctx;
  (void)x1;
  return proto_abs(x2);
}

proto arith_custom_production_UnOpNegate(struct arith_parse_state* ctx,
                                        token /*NEGATE*/ x1, proto /*expr*/ x2)
{
  (void)ctx;
  (void)x1;
  return proto_neg(x2);
}

proto arith_custom_production_UnOpIncrement(struct arith_parse_state* ctx,
                                        token /*INCREMENT*/ x1, proto /*expr*/ x2)
{
  (void)ctx;
  (void)x1;
  return proto_incr(x2);
}

proto arith_custom_production_UnOpDecrement(struct arith_parse_state* ctx,
                                        token /*DECREMENT*/ x1, proto /*expr*/ x2)
{
  (void)ctx;
  (void)x1;
  return proto_decr(x2);
}

