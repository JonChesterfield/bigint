#include "arith.lexer.h"
#include "arith.parser.h"
#include "arith.productions.h"

#define EXPLICIT_SPACING 1

#if EXPLICIT_SPACING
#define SPACE(X) token s##X,
#define NEWLINE(X) , token s##X
#define VOID(X) (void)s##X
#else
#define SPACE(X)
#define NEWLINE(X)
#define VOID(X)
#endif

proto arith_custom_production_FromInteger(struct arith_parse_state* parse_ctx,
                                          token /*INTEGER*/ x1)
{
  proto_context ctx = arith_parse_state_get_tree_context(parse_ctx);

  size_t width = token_width(x1);
  const char* bytes = token_value(x1);

  return proto_from_base10(ctx, bytes, width);
}

proto arith_custom_production_BinaryOp(struct arith_parse_state* parse_ctx,
                                       proto (*func)(proto_context, proto,
                                                     proto),
                                       proto /*expr*/ x2, proto /*expr*/ x3)
{
  proto_context ctx = arith_parse_state_get_tree_context(parse_ctx);
  proto res = func(ctx, x2, x3);
  proto_destroy(ctx, x2);
  proto_destroy(ctx, x3);
  return res;
}

proto arith_custom_production_UnaryOp(struct arith_parse_state* parse_ctx,
                                      proto (*func)(proto_context, proto),
                                      proto /*expr*/ x2)
{
  proto_context ctx = arith_parse_state_get_tree_context(parse_ctx);
  proto res = func(ctx, x2);
  proto_destroy(ctx, x2);
  return res;
}

proto arith_custom_production_BinOpPlus(struct arith_parse_state* parse_ctx,
                                        token /*PLUS*/ x1,
                                        SPACE(0) proto /*expr*/ x2,
                                        SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_add, x2, x3);
}

// CustomProduction BinOpMinus -> arith_grouping_expr
proto arith_custom_production_BinOpMinus(struct arith_parse_state* parse_ctx,
                                         token /*MINUS*/ x1,
                                         SPACE(0) proto /*expr*/ x2,
                                         SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_sub, x2, x3);
}

// CustomProduction BinOpTimes -> arith_grouping_expr
proto arith_custom_production_BinOpTimes(struct arith_parse_state* parse_ctx,
                                         token /*TIMES*/ x1,
                                         SPACE(0) proto /*expr*/ x2,
                                         SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_mul, x2, x3);
}

// CustomProduction BinOpDivide -> arith_grouping_expr
proto arith_custom_production_BinOpDivide(struct arith_parse_state* parse_ctx,
                                          token /*DIVIDE*/ x1,
                                          SPACE(0) proto /*expr*/ x2,
                                          SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_div, x2, x3);
}

// CustomProduction BinOpModulo -> arith_grouping_expr
proto arith_custom_production_BinOpRemainder(
    struct arith_parse_state* parse_ctx, token /*REMAINDER*/ x1,
    SPACE(0) proto /*expr*/ x2, SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_rem, x2, x3);
}

proto arith_custom_production_BinOpBitOr(struct arith_parse_state* parse_ctx,
                                         token /*BITOR*/ x1,
                                         SPACE(0) proto /*expr*/ x2,
                                         SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_or, x2, x3);
}

proto arith_custom_production_BinOpBitAnd(struct arith_parse_state* parse_ctx,
                                          token /*BITAND*/ x1,
                                          SPACE(0) proto /*expr*/ x2,
                                          SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_and, x2, x3);
}

proto arith_custom_production_BinOpBitXor(struct arith_parse_state* parse_ctx,
                                          token /*BITXOR*/ x1,
                                          SPACE(0) proto /*expr*/ x2,
                                          SPACE(1) proto /*expr*/ x3 NEWLINE(2))
{
  (void)x1;
  VOID(0);
  VOID(1);
  VOID(2);
  return arith_custom_production_BinaryOp(parse_ctx, proto_xor, x2, x3);
}

proto arith_custom_production_UnOpAbsolute(struct arith_parse_state* parse_ctx,
                                           token /*ABSOLUTE*/ x1,
                                           SPACE(0)
                                               proto /*expr*/ x2 NEWLINE(1))
{
  (void)x1;
  VOID(0);
  VOID(1);
  return arith_custom_production_UnaryOp(parse_ctx, proto_abs, x2);
}

proto arith_custom_production_UnOpNegate(struct arith_parse_state* parse_ctx,
                                         token /*NEGATE*/ x1,
                                         SPACE(0) proto /*expr*/ x2 NEWLINE(1))
{
  (void)x1;
  VOID(0);
  VOID(1);
  return arith_custom_production_UnaryOp(parse_ctx, proto_neg, x2);
}

proto arith_custom_production_UnOpIncrement(struct arith_parse_state* parse_ctx,
                                            token /*INCREMENT*/ x1,
                                            SPACE(0)
                                                proto /*expr*/ x2 NEWLINE(1))
{
  (void)x1;
  VOID(0);
  VOID(1);
  return arith_custom_production_UnaryOp(parse_ctx, proto_incr, x2);
}

proto arith_custom_production_UnOpDecrement(struct arith_parse_state* parse_ctx,
                                            token /*DECREMENT*/ x1,
                                            SPACE(0)
                                                proto /*expr*/ x2 NEWLINE(1))
{
  (void)x1;
  VOID(0);
  VOID(1);
  return arith_custom_production_UnaryOp(parse_ctx, proto_decr, x2);
}

static uint32_t base32_decode(char c)
{
  // base 32 in 26 UPPERCASE and six printable chars
  // specific decoding pattern doesn't matter very much
  _Static_assert('!' == 0x21, "");
  _Static_assert('#' == 0x23, "");
  _Static_assert('$' == 0x24, "");
  _Static_assert('%' == 0x25, "");
  _Static_assert('&' == 0x26, "");
  _Static_assert('@' == 0x40, "");

  _Static_assert('A' == 0x41, "");
  _Static_assert('Z' == 0x5a, "");

  if (c >= 'A' && c <= 'Z')
    {
      return c - 'A';
    }

  switch (c)
    {
      case '@':
        return 26;
      case '!':
        return 27;
      case '#':
        return 28;
      case '$':
        return 29;
      case '%':
        return 30;
      case '&':
        return 31;
      default:
        return UINT32_MAX;
    }
}

proto arith_custom_production_FromControl(struct arith_parse_state* parse_ctx,
                                          token /*CONTROL*/ x1)
{
  // base 32 is five bits per character
  // lets say 60 bit maximum is sufficient

  size_t width = token_width(x1);
  const char* bytes = token_value(x1);
  if (width == 0 || width > 12)
    {
      return proto_create_invalid();
    }

  uint64_t value = 0;

  for (size_t i = 0; i < width; i++)
    {
      uint32_t digit = base32_decode(bytes[i]);
      if (digit >= 32)
        {
          return proto_create_invalid();
        }

      value *= 32;
      value += digit;
    }

  // fprintf(stderr, "Setting malloc state to %lu\n", value);

  proto_context ctx = arith_parse_state_get_tree_context(parse_ctx);
  proto_context_set_fuel_value(ctx, value);

  // This operation sets the state, doesn't otherwise affect the parse tree
  return proto_from_u32(ctx, 0);
}

// The leading control block doesn't affect the tree. Check it holds !valid()
// and otherwise tail call into the next handler.
proto arith_custom_production_control_expr_to_program(
    struct arith_parse_state* parse_ctx, proto /*control_block*/ x1,
    token /*SPACE*/ x2, proto /*expr*/ x3)
{
  proto_context ctx = arith_parse_state_get_tree_context(parse_ctx);
  proto_destroy(ctx, x1);
  return x3;
}

proto arith_custom_production_control_result_expr_to_program(
    struct arith_parse_state* parse_ctx, proto /*control_block*/ x1,
    token /*SPACE*/ x2, proto /*integer*/ x3, token /*SPACE*/ x4,
    proto /*expr*/ x5)
{
  proto_context ctx = arith_parse_state_get_tree_context(parse_ctx);
  proto_destroy(ctx, x1);
  return arith_custom_production_result_expr_to_program(parse_ctx, x3, x4, x5);
}

proto arith_custom_production_result_expr_to_program(
    struct arith_parse_state* parse_ctx, proto /*integer*/ x1,
    token /*SPACE*/ x2, proto /*expr*/ x3)
{
  proto_context ctx = arith_parse_state_get_tree_context(parse_ctx);

  if (!proto_valid(ctx, x1) || !proto_valid(ctx, x3))
    {
      if (proto_valid(ctx, x1))
        {
          proto_destroy(ctx, x1);
        }
      if (proto_valid(ctx, x3))
        {
          proto_destroy(ctx, x3);
        }
      return proto_create_invalid();
    }

  if (!proto_equal(ctx, x1, x3))
    {
#if 0
      fprintf(stderr, "Not equal\n");
      proto_dump(ctx,x1);
      proto_dump(ctx,x3);
#endif

      proto_destroy(ctx, x1);
      proto_destroy(ctx, x3);

      return proto_create_invalid();
    }

  proto_destroy(ctx, x1);
  return x3;
}
