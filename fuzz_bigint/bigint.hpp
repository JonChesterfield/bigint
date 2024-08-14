#ifndef BIGINT_HPP_INCLUDED
#define BIGINT_HPP_INCLUDED

#include "base_operations.hpp"
#include "bigint_tommath.hpp"
#include "fixnum.hpp"
#include "vtable.hpp"

#ifndef BIGINT_IMPL
#define BIGINT_IMPL tommath
#endif


namespace bigint
{

  // using bigint:: BIGINT_IMPL ::from_decimal;
  // There is a bigint::tommath::from_decimal
  // This function is written in terms of the bigint::BIGINT_IMPL interface
  // and will presently have overhead - needs mul(IntType&&, int64_t) to get
  // back to the tommath specialisation
  template <typename IntType>
  IntType from_decimal(const char* start, const char *end);

  template <typename IntType>
  bool is_negative(IntType x)
  {
    using ops = base_operations<IntType>;
    bool sign = ops::get_sign(&x);
    return sign == true;
  }

  template <typename IntType>
  bool is_non_negative(IntType x)
  {
    return !is_negative<IntType>(x);
  }

  using bigint:: BIGINT_IMPL ::from_i64;
  using bigint:: BIGINT_IMPL ::trunc_i64;
  using bigint:: BIGINT_IMPL ::decimal_length;
  using bigint:: BIGINT_IMPL ::to_decimal;

  // equal returns a bigint
  using bigint:: BIGINT_IMPL ::boolean_equal;

  using bigint:: BIGINT_IMPL ::absolute;
  using bigint:: BIGINT_IMPL ::negate;
  using bigint:: BIGINT_IMPL ::incr;
  using bigint:: BIGINT_IMPL ::decr;
  using bigint:: BIGINT_IMPL ::add;
  using bigint:: BIGINT_IMPL ::sub;
  using bigint:: BIGINT_IMPL ::mul;
  using bigint:: BIGINT_IMPL ::div;
  using bigint:: BIGINT_IMPL ::rem;
  using bigint:: BIGINT_IMPL ::shift_left;
  using bigint:: BIGINT_IMPL ::shift_right;
  using bigint:: BIGINT_IMPL ::bitwise_not;
  using bigint:: BIGINT_IMPL ::bitwise_or;
  using bigint:: BIGINT_IMPL ::bitwise_and;
  using bigint:: BIGINT_IMPL ::bitwise_xor;
  using bigint:: BIGINT_IMPL ::equal;
  using bigint:: BIGINT_IMPL ::cmp;

template <typename IntType>
IntType from_decimal(const char* start, const char *end)
{
    size_t width = end - start;
    if (width == 0) return create_invalid<IntType>();

    bool neg = start[0] == '-';
    if (neg)
    {
      if (width == 1)
      {
          return create_invalid<IntType>();
      }
      start++;
      width--;
    }

    IntType acc = from_i64<IntType>(0);
    if (is_invalid(acc)) goto fail;
    
    for (size_t i = 0; i < width; i++)
    {
      char b = (start[i] - '0');
      if (b < 0 || b > 9)
      {
        return create_invalid<IntType>();
      }

      // Might be useful to have this leave ten in a state where destroy
      // can be called on it, or equivalently have to return a create_invalid directly
      IntType ten = from_i64<IntType>(10);
      if (is_invalid(ten)) goto fail;

      acc = mul(acc, ten);
      if (is_invalid(acc)) goto fail;
      

      IntType inc = from_i64<IntType>(b);
      if (is_invalid(inc)) goto fail;


      acc = add(acc, inc);
      if (is_invalid(acc)) goto fail;      
    }

    if (neg)
    {
      acc = bigint::negate(acc);
      if (is_invalid(acc)) goto fail;      
    }
  
    return acc;


 fail:
    return create_invalid<IntType>();

}





template <typename IntType>
constexpr vtable<IntType> create_vtable()
{
  return {
    create_invalid<IntType>,
    is_invalid<IntType>,
    destroy<IntType>,
    from_decimal<IntType>,
    absolute<IntType>,
    negate<IntType>,
    incr<IntType>,
    decr<IntType>,
    add<IntType>,
    sub<IntType>,
    mul<IntType>,
    div<IntType>,
    rem<IntType>,
    shift_left<IntType>,
    shift_right<IntType>,
    bitwise_not<IntType>,
    bitwise_or<IntType>,
    bitwise_and<IntType>,
    bitwise_xor<IntType>,
    equal<IntType>,
    cmp<IntType>,
  };
}

} // namespace bigint
#endif // BIGINT_HPP_INCLUDED
