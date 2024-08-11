#ifndef SIMPLE_VIA_TOMMATH_HPP_INCLUDED
#define SIMPLE_VIA_TOMMATH_HPP_INCLUDED

// Implement the interface declared in bigint by
// calling into functions defined in bigint_tommath

#include "bigint.hpp"
#include "bigint_tommath.hpp"

namespace bigint
{

template <typename IntType>
IntType simple<IntType>::from_decimal(const char* start, const char *end)
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


template <typename IntType>
IntType simple<IntType>::abs(IntType arg0)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_abs(&arg0, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::neg(IntType arg0)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_neg(&arg0, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::incr(IntType arg0)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_add_one(&arg0, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::decr(IntType arg0)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_sub_one(&arg0, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::add(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_add(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::sub(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_sub(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::mul(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_mul(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::div(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_div_no_rem(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::rem(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_div_only_rem(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::lsh(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_lsh(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::rsh(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_rsh(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::bitwise_not(IntType arg0)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_complement(&arg0, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::bitwise_or(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_or(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::bitwise_and(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_and(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
IntType simple<IntType>::bitwise_xor(IntType arg0 ,IntType arg1)
{
  using TM = tommath<IntType>;
  IntType result;
  typename TM::mp_err r = TM::mp_init(&result);
  if (r != TM::MP_OKAY) { return create_invalid<IntType>(); }
  typename TM::mp_err e = TM::mp_xor(&arg0, &arg1, &result);
  if (e == TM::MP_OKAY)
  { return result; }
  else
  { return create_invalid<IntType>(); }
}
template <typename IntType>
bool simple<IntType>::equal(IntType arg0 ,IntType arg1)
{
// non-trivial impl not yet written
}
template <typename IntType>
int simple<IntType>::cmp(IntType arg0 ,IntType arg1)
{
// non-trivial impl not yet written
}
}
#endif // SIMPLE_VIA_TOMMATH_HPP_INCLUDED
