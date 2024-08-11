#ifndef BIGINT_FIXNUM_HPP_INCLUDED
#define BIGINT_FIXNUM_HPP_INCLUDED

#include "base_operations.hpp"

namespace bigint
{
namespace fixnum
{

// base operations has "digit" and "word" which are
// roughly the right thing here, but the key thing is
// having the result be twice the width of the arguments

// loose plan for fixnums can be:
// - do the real operation, get the real result without loss
// - see if that can be stored back into the dynamic type
// - turn it into a bigint if it doesn't fit

// don't return an int32_t and a bool to say whether it worked,
// return the whole thing and test whether it can be truncated
// without loss (e.g. truncate it then sign extend and check for
// equality)

// When the digit is a uint64_t, this still works with either
// uint128_t or a pair of uint64_t's and handwriting the pieces
// Ideally handwriting the pieces would optimise to the direct op
// but that might need patches to instcombine

// The other code path is bigint op fixnum -> bigint, possibly
// followed by truncation.
template <typename IntType>
int64_t open_i64(IntType x, bool *all_exact)
{
  using ops = typename bigint::base_operations<IntType>;
  int64_t tmp;
  *all_exact &= ops::open_fixed(&x, &tmp);
  return tmp;
}

template <typename IntType>
IntType create_i64(int64_t x)
{
  using ops = typename bigint::base_operations<IntType>;
  IntType tmp;
  if (!ops::create_fixed(&tmp, x))
    {
      ops::create_invalid(&tmp);
    }
  return tmp;
}

static int64_t add_checked(int64_t xf, int64_t yf, bool *all_exact)
{
  int64_t rf;
  *all_exact &= !__builtin_add_overflow(xf, yf, &rf);
  return rf;
}
static int64_t sub_checked(int64_t xf, int64_t yf, bool *all_exact)
{
  int64_t rf;
  *all_exact &= !__builtin_sub_overflow(xf, yf, &rf);
  return rf;
}
static int64_t mul_checked(int64_t xf, int64_t yf, bool *all_exact)
{
  int64_t rf;
  *all_exact &= !__builtin_mul_overflow(xf, yf, &rf);
  return rf;
}

static int64_t xor_checked(int64_t xf, int64_t yf, bool *all_exact)
{
  (void)all_exact;
  return xf ^ yf;
}

static int64_t or_checked(int64_t xf, int64_t yf, bool *all_exact)
{
  (void)all_exact;
  return xf | yf;
}

static int64_t and_checked(int64_t xf, int64_t yf, bool *all_exact)
{
  (void)all_exact;
  return xf & yf;
}

// This is pretty good at hitting the both-small case
// but doesn't do very well at one for one of them being a bigint
// where the result happens to fit in a word anyway

template <typename IntType, int64_t (*Op)(int64_t, int64_t, bool *)>
static IntType op_via_checked(IntType x, IntType y)
{
  using ops = typename bigint::base_operations<IntType>;
  bool exact = true;
  int64_t xf = open_i64(x, &exact);
  int64_t yf = open_i64(y, &exact);
  int64_t rf = Op(xf, yf, &exact);
  return exact ? create_i64<IntType>(rf) : create_invalid<IntType>();
}

static_assert(INT64_MAX * -1 == INT64_MIN + 1);
static_assert(((INT64_MIN + 1) * -1) == INT64_MAX);
static_assert(INT64_MAX * -1 == (INT64_MIN + 1), "");

template <typename IntType>
IntType abs(IntType x)
{
  using ops = typename bigint::base_operations<IntType>;
  bool exact = true;
  int64_t xf = open_i64(x, &exact);
  if (xf < 0)
    {
      if (xf == INT64_MIN)
        {
          exact = false;
        }
      else
        {
          xf *= -1;
        }
    }

  return exact ? create_i64<IntType>(xf) : create_invalid<IntType>();
}

template <typename IntType>
IntType neg(IntType x)
{
  using ops = typename bigint::base_operations<IntType>;
  bool exact = true;
  int64_t xf = open_i64(x, &exact);

  if (xf == INT64_MIN)
    {
      exact = false;
    }

  xf *= -1;

  return exact ? create_i64<IntType>(xf) : create_invalid<IntType>();
}

template <typename IntType>
IntType incr(IntType x)
{
  using ops = typename bigint::base_operations<IntType>;
  bool exact = true;
  int64_t xf = open_i64(x, &exact);
  if (xf == INT64_MAX)
    {
      exact = false;
    }
  else
    {
      xf++;
    }

  return exact ? create_i64<IntType>(xf) : create_invalid<IntType>();
}

template <typename IntType>
IntType decr(IntType x)
{
  using ops = typename bigint::base_operations<IntType>;
  bool exact = true;
  int64_t xf = open_i64(x, &exact);
  if (xf == INT64_MIN)
    {
      exact = false;
    }
  else
    {
      xf--;
    }
  return exact ? create_i64<IntType>(xf) : create_invalid<IntType>();
}

template <typename IntType>
static IntType add(IntType x, IntType y)
{
  return op_via_checked<IntType, add_checked>(x, y);
}
template <typename IntType>
static IntType sub(IntType x, IntType y)
{
  return op_via_checked<IntType, sub_checked>(x, y);
}
template <typename IntType>
static IntType mul(IntType x, IntType y)
{
  return op_via_checked<IntType, mul_checked>(x, y);
}

template <typename IntType>
static IntType div(IntType x, IntType y)
{
  return create_invalid<IntType>();
}

template <typename IntType>
static IntType rem(IntType x, IntType y)
{
  return create_invalid<IntType>();
}

template <typename IntType>
static IntType lsh(IntType x, IntType y)
{
  return create_invalid<IntType>();
}

template <typename IntType>
static IntType rsh(IntType x, IntType y)
{
  return create_invalid<IntType>();
}

template <typename IntType>
static IntType bitwise_not(IntType x)
{
  return create_invalid<IntType>();
}

template <typename IntType>
static IntType bitwise_or(IntType x, IntType y)
{
  return op_via_checked<IntType, or_checked>(x, y);
}

template <typename IntType>
static IntType bitwise_and(IntType x, IntType y)
{
  return op_via_checked<IntType, and_checked>(x, y);
}

template <typename IntType>
static IntType bitwise_xor(IntType x, IntType y)
{
  return op_via_checked<IntType, xor_checked>(x, y);
}

template <typename IntType>
static bool equal(IntType x, IntType y)
{
  return false;
}

template <typename IntType>
static int cmp(IntType x, IntType y)
{
  return -2;
}

} // namespace fixnum
} // namespace bigint
#endif
