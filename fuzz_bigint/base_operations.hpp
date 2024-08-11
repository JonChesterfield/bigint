#ifndef BIGINT_BASE_OPERATIONS_HPP_INCLUDED
#define BIGINT_BASE_OPERATIONS_HPP_INCLUDED

#include <stddef.h>
#include <stdint.h>

namespace bigint
{

template <typename IntType>
struct base_operations
{
  using mp_int = IntType;
  using mp_digit = uint32_t;
  using mp_word = uint64_t;
  using mp_count = size_t;

  // Allocate size digits of storage, true on success
  static bool create(mp_int *a, mp_count size);

  // Increase digits of storage to size, true on success
  static bool grow(mp_int *a, mp_count size);

  // Deallocate storage
  static void destroy(mp_int *a);

  // Create a sentinel, used to indicate failures
  static void create_invalid(mp_int *a);

  // Test whether this instance is a sentinel
  static bool is_invalid(const mp_int*);

  // Number of digits available, the high ones may be zero
  static mp_count get_storage_count(const mp_int*);

  // Number of digits containing a non-zero value
  static mp_count get_nonzero_count(const mp_int*);

  // The sign bit, i.e. true for negative, false for zero or positive
  static bool get_sign(const mp_int*);

  // Record that the low count are known non-zero
  static void set_nonzero_count(mp_int*, mp_count);

  // Change sign bit
  static void set_sign(mp_int*, bool);

  // Read or write the ith digit
  static mp_digit get_digit(const mp_int*, mp_count);
  static void set_digit(mp_int*, mp_count, mp_digit);

  // Temporary. Tommath uses pointers into storage to define some of the
  // algorithms. This interferes with bounds checking and somewhat violates
  // const-correctneess. Uses can all be replaced with an iterator and the
  // above calls but haven't been at present.
  static mp_digit * get_digit_iter(const mp_int*);
};

}

#endif
