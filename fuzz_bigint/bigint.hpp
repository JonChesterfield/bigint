#ifndef BIGINT_HPP_INCLUDED
#define BIGINT_HPP_INCLUDED

#include "base_operations.hpp"

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
class simple;

template <typename IntType>
IntType from_decimal(const char* start, const char *end)
{
  return simple<IntType>::from_decimal(start, end);
}

template <typename IntType>
IntType abs(IntType arg0)
{
  return simple<IntType>::abs(arg0);
}

template <typename IntType>
IntType neg(IntType arg0)
{
  return simple<IntType>::neg(arg0);
}

template <typename IntType>
IntType incr(IntType arg0)
{
  return simple<IntType>::incr(arg0);
}

template <typename IntType>
IntType decr(IntType arg0)
{
  return simple<IntType>::decr(arg0);
}

template <typename IntType>
IntType add(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::add(arg0 ,arg1);
}

template <typename IntType>
IntType sub(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::sub(arg0 ,arg1);
}

template <typename IntType>
IntType mul(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::mul(arg0 ,arg1);
}

template <typename IntType>
IntType div(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::div(arg0 ,arg1);
}

template <typename IntType>
IntType rem(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::rem(arg0 ,arg1);
}

template <typename IntType>
IntType lsh(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::lsh(arg0 ,arg1);
}

template <typename IntType>
IntType rsh(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::rsh(arg0 ,arg1);
}

template <typename IntType>
IntType bitwise_not(IntType arg0)
{
  return simple<IntType>::bitwise_not(arg0);
}

template <typename IntType>
IntType bitwise_or(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::bitwise_or(arg0 ,arg1);
}

template <typename IntType>
IntType bitwise_and(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::bitwise_and(arg0 ,arg1);
}

template <typename IntType>
IntType bitwise_xor(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::bitwise_xor(arg0 ,arg1);
}

template <typename IntType>
bool equal(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::equal(arg0 ,arg1);
}

template <typename IntType>
int cmp(IntType arg0 ,IntType arg1)
{
  return simple<IntType>::cmp(arg0 ,arg1);
}

template <typename IntType>
class simple
{
public:
  static IntType from_decimal(const char* start, const char *end);
  static IntType abs(IntType);
  static IntType neg(IntType);
  static IntType incr(IntType);
  static IntType decr(IntType);
  static IntType add(IntType, IntType);
  static IntType sub(IntType, IntType);
  static IntType mul(IntType, IntType);
  static IntType div(IntType, IntType);
  static IntType rem(IntType, IntType);
  static IntType lsh(IntType, IntType);
  static IntType rsh(IntType, IntType);
  static IntType bitwise_not(IntType);
  static IntType bitwise_or(IntType, IntType);
  static IntType bitwise_and(IntType, IntType);
  static IntType bitwise_xor(IntType, IntType);
  static bool equal(IntType, IntType);
  static int cmp(IntType, IntType);
};


} // namespace bigint
#endif // BIGINT_HPP_INCLUDED
