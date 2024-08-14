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
IntType from_i64(int64_t x)
{
  using ops = typename bigint::base_operations<IntType>;
  IntType tmp;
  if (!ops::create_fixed(&tmp, x))
    {
      ops::create_invalid(&tmp);
    }
  return tmp;
}

template <typename IntType>
int64_t trunc_i64(IntType x, bool *all_exact)
{
  bool exact = true;
  return open_i64(x, &exact);
}

template <typename IntType>
size_t decimal_length(IntType x)
{
  // This has an off by one look to it
  bool exact = true;
  int64_t xf = open_i64(x, &exact);
  if (!exact) return SIZE_MAX;

  size_t res = 0;
  if (xf < 0)
    {
      res++;
      xf *= -1;
    }

  if (xf == 0) { return 1; }
  
  while (xf != 0)
    {
      xf /= 10;
      res++;
    }

  return res;
}

template <typename IntType>
size_t to_decimal(IntType x, char *buffer, size_t buffer_available)
{
  bool exact = true;
  int64_t xf = open_i64(x, &exact);
  if (!exact || (buffer_available < 1) ) return SIZE_MAX;
  
  if (xf == 0) {    
    buffer[0] = '0';
    return 1;
  }

  // bignum works a digit at a time then reverses
  // divide int64_t by ten should be cheap though
  size_t len = decimal_length(x);
  
  size_t written = 0;
  if (xf < 0)
    {
      buffer[0] = '-';
      written++;
      buffer++;
      buffer_available--;
      xf *= -1;
    }
  
  
  for (size_t i = len; i --> 0;)
    {
      buffer[i] = (xf % 10) + '0';
      xf /= 10;      
    }

  return written + len;  
}

template <typename IntType>
bool boolean_equal(IntType x, IntType y)
{
  // Hazard here in exact handling
  bool exact = true;
  int64_t xf = open_i64(x, &exact);
  int64_t yf = open_i64(y, &exact);
  return (xf == yf) && exact;
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
  return exact ? from_i64<IntType>(rf) : create_invalid<IntType>();
}

static_assert(INT64_MAX * -1 == INT64_MIN + 1);
static_assert(((INT64_MIN + 1) * -1) == INT64_MAX);
static_assert(INT64_MAX * -1 == (INT64_MIN + 1), "");

template <typename IntType>
IntType absolute(IntType x)
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

  return exact ? from_i64<IntType>(xf) : create_invalid<IntType>();
}

template <typename IntType>
IntType negate(IntType x)
{
  using ops = typename bigint::base_operations<IntType>;
  bool exact = true;
  int64_t xf = open_i64(x, &exact);

  if (xf == INT64_MIN)
    {
      exact = false;
    }

  xf *= -1;

  return exact ? from_i64<IntType>(xf) : create_invalid<IntType>();
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

  return exact ? from_i64<IntType>(xf) : create_invalid<IntType>();
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
  return exact ? from_i64<IntType>(xf) : create_invalid<IntType>();
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
static IntType shift_left(IntType x, IntType y)
{
  return create_invalid<IntType>();
}

template <typename IntType>
static IntType shift_right(IntType x, IntType y)
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
static IntType equal(IntType x, IntType y)
{
  return from_i64<IntType>(0);  // false
}

template <typename IntType>
static IntType cmp(IntType x, IntType y)
{
  return from_i64<IntType>(-2);  // nonsense
}

}  // namespace fixnum
}  // namespace bigint
#endif
