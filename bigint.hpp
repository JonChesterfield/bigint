#ifndef BIGINT_HPP_INCLUDED
#define BIGINT_HPP_INCLUDED

// Declare methods on an arbitrary precision type

template <typename IntType>
class bigint
{
 public:
  static IntType abs(IntType arg0);
  static IntType neg(IntType arg0);
  static IntType incr(IntType arg0);
  static IntType decr(IntType arg0);
  static IntType add(IntType arg0, IntType arg1);
  static IntType sub(IntType arg0, IntType arg1);
  static IntType mul(IntType arg0, IntType arg1);
  static IntType div(IntType arg0, IntType arg1);
  static IntType rem(IntType arg0, IntType arg1);
  static IntType lsh(IntType arg0, IntType arg1);
  static IntType rsh(IntType arg0, IntType arg1);
  static IntType ash(IntType arg0, IntType arg1);
  static IntType bitwise_not(IntType arg0);
  static IntType bitwise_or(IntType arg0, IntType arg1);
  static IntType bitwise_and(IntType arg0, IntType arg1);
  static IntType bitwise_xor(IntType arg0, IntType arg1);
  static bool equal(IntType arg0, IntType arg1);
  static int cmp(IntType arg0, IntType arg1);
};

#endif  // BIGINT_HPP_INCLUDED
