#ifndef BIGINT_HPP_INCLUDED
#define BIGINT_HPP_INCLUDED

#include "base_operations.hpp"
#include "bigint_tommath.hpp"

namespace bigint
{

template <typename IntType>
IntType create_invalid()
{
  using ops = base_operations<IntType>;
  IntType result;
  ops::create_invalid(&result);
  return result;
}

template <typename IntType>
bool is_invalid(IntType x)
{
  using ops = base_operations<IntType>;
  return ops::is_invalid(&x);
}

template <typename IntType>
IntType from_decimal(const char* start, const char *end)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_from_decimal(start, end, &result);
  if (e == TM::MP_OKAY) { return result;}
  TM::mp_clear(&result);
  return create_invalid<IntType>();
}

namespace dispatch
{
template <typename IntType,
          typename tommath<IntType>::mp_err (*Op)(const IntType*, IntType*)>
IntType unary(IntType arg0)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = Op(&arg0, &result);
  if (e == TM::MP_OKAY)
  { return result; }

  TM::mp_clear(&result);
  return create_invalid<IntType>();
}

template <typename IntType,
          typename tommath<IntType>::mp_err (*Op)(const IntType*, const IntType*, IntType*)>
IntType binary(IntType arg0, IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = Op(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }

  TM::mp_clear(&result);
  return create_invalid<IntType>();
}

}

template <typename IntType>
IntType abs(IntType arg0)
{
  return dispatch::unary<IntType, tommath<IntType>::mp_abs>(arg0);
}

template <typename IntType>
IntType neg(IntType arg0)
{
  return dispatch::unary<IntType, tommath<IntType>::mp_neg>(arg0);
}

template <typename IntType>
IntType incr(IntType arg0)
{
  return dispatch::unary<IntType, tommath<IntType>::mp_add_one>(arg0);
}

template <typename IntType>
IntType decr(IntType arg0)
{
  return dispatch::unary<IntType, tommath<IntType>::mp_sub_one>(arg0);
}

template <typename IntType>
IntType add(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_add>(arg0 ,arg1);
}

template <typename IntType>
IntType sub(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_sub>(arg0 ,arg1);
}

template <typename IntType>
IntType mul(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_mul>(arg0 ,arg1);
}

template <typename IntType>
IntType div(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_div_no_rem>(arg0 ,arg1);
}

template <typename IntType>
IntType rem(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_div_only_rem>(arg0 ,arg1);
}

template <typename IntType>
IntType lsh(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_lsh>(arg0 ,arg1);
}

template <typename IntType>
IntType rsh(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_rsh>(arg0 ,arg1);
}

template <typename IntType>
IntType bitwise_not(IntType arg0)
{
  return dispatch::unary<IntType, tommath<IntType>::mp_complement>(arg0);
}

template <typename IntType>
IntType bitwise_or(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_or>(arg0 ,arg1);
}

template <typename IntType>
IntType bitwise_and(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_and>(arg0 ,arg1);
}

template <typename IntType>
IntType bitwise_xor(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_xor>(arg0 ,arg1);
}

template <typename IntType>
bool equal(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_equal>(arg0 ,arg1);
}

template <typename IntType>
int cmp(IntType arg0 ,IntType arg1)
{
  return dispatch::binary<IntType, tommath<IntType>::mp_cmp>(arg0 ,arg1);
}

} // namespace bigint
#endif // BIGINT_HPP_INCLUDED
