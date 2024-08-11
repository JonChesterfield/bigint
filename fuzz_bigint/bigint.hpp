#ifndef BIGINT_HPP_INCLUDED
#define BIGINT_HPP_INCLUDED

#include "base_operations.hpp"
#include "bigint_tommath.hpp"

namespace bigint
{
  using bigint::tommath::from_decimal;
  using bigint::tommath::abs;
  using bigint::tommath::neg;
  using bigint::tommath::incr;
  using bigint::tommath::decr;
  using bigint::tommath::add;
  using bigint::tommath::sub;
  using bigint::tommath::mul;
  using bigint::tommath::div;
  using bigint::tommath::rem;
  using bigint::tommath::lsh;
  using bigint::tommath::rsh;
  using bigint::tommath::bitwise_not;
  using bigint::tommath::bitwise_or;
  using bigint::tommath::bitwise_and;
  using bigint::tommath::bitwise_xor;
  using bigint::tommath::equal;
  using bigint::tommath::cmp;

} // namespace bigint
#endif // BIGINT_HPP_INCLUDED
