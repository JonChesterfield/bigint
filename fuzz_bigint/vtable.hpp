#ifndef VTABLE_HPP_INCLUDED
#define VTABLE_HPP_INCLUDED

namespace bigint
{

template <typename IntTypeT>
struct vtable
{
  using IntType = IntTypeT;
  IntType (* const create_invalid)();
  bool    (* const is_invalid)(IntType);
  void    (* const destroy)(IntType);
  IntType (* const from_decimal)(const char*, const char*);
  IntType (* const absolute)(IntType);
  IntType (* const negate)(IntType);
  IntType (* const incr)(IntType);
  IntType (* const decr)(IntType);
  IntType (* const add)(IntType, IntType);
  IntType (* const sub)(IntType, IntType);
  IntType (* const mul)(IntType, IntType);
  IntType (* const div)(IntType, IntType);
  IntType (* const rem)(IntType, IntType);
  IntType (* const shift_left)(IntType, IntType);
  IntType (* const shift_right)(IntType, IntType);
  IntType (* const bitwise_not)(IntType);
  IntType (* const bitwise_or)(IntType, IntType);
  IntType (* const bitwise_and)(IntType, IntType);
  IntType (* const bitwise_xor)(IntType, IntType);
  IntType (* const equal)(IntType, IntType);
  IntType (* const cmp)(IntType, IntType);
};
} // namespace bigint
#endif
