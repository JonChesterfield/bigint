#include "bigint.hpp"
#include "base_operations.hpp"

#include "bigint_tommath.hpp"

#include "simple_via_tommath.hpp"

#include "interpreter.hpp"
#include "lexer.h"

#include <stdint.h>
#include <stdlib.h>

struct bigint_data
{
  int used = 0;
  int alloc = 0;
  bool sign = true;
  bool valid = false;
  uint32_t* dp = 0;
};

namespace bigint
{
template <>
struct base_operations<bigint_data>
{
  using mp_int = bigint_data;
  using mp_digit = uint32_t;
  using mp_word = uint64_t;
  using mp_count = int;

  static bool create(mp_int* a, mp_count size)
  {
    a->dp = static_cast<mp_digit*>(malloc(size * sizeof(mp_digit)));
    if (a->dp)
      {
        a->alloc = size;
        a->used = 0;
        a->sign = false;
        a->valid = true;
        for (mp_count i = 0; i < size; i++)
          {
            a->dp[i] = 0;
          }
        return true;
      }
    return false;
  }

  static bool grow(mp_int* a, mp_count size)
  {
    const mp_count before = a->alloc;
    mp_digit* p =
        static_cast<mp_digit*>(realloc(a->dp, size * sizeof(mp_digit)));
    if (p)
      {
        a->dp = p;
        a->alloc = size;
        for (mp_count i = before; i < size; i++)
          {
            a->dp[i] = 0;
          }

        return true;
      }
    return false;
  }

  static void destroy(mp_int* a) { free(a->dp); }

  static void create_invalid(mp_int* a) { a->valid = false; }

  static bool is_invalid(const mp_int* a) { return !a->valid; }

  static mp_count get_storage_count(const mp_int* a) { return a->alloc; }

  static mp_count get_nonzero_count(const mp_int* a) { return a->used; }

  static bool get_sign(const mp_int* a) { return a->sign; }

  static void set_nonzero_count(mp_int* a, mp_count n) { a->used = n; }

  static void set_sign(mp_int* a, bool s) { a->sign = s; }
  static mp_digit get_digit(const mp_int* a, mp_count i) { return a->dp[i]; }
  static void set_digit(mp_int* a, mp_count i, mp_digit d) { a->dp[i] = d; }

  static mp_digit* get_digit_iter(const mp_int* a) { return a->dp; }
};
}  // namespace bigint

extern "C"
{
  int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
  {
    const char* str = (const char*)Data;
    const char* lim = str + Size;
    if (!parses(str, lim))
      {
        return -1;
      }

    bigint_data res = bigint::interp<bigint_data>(str, lim);

    bigint::base_operations<bigint_data>::destroy(&res);

    return 0;  // accept
  }
}

#if 0
int main()
{
  bigint_data x = bigint::interp_cstr<bigint_data>("sub 4 15");

  bigint_data y = bigint::abs(x);
}
#endif
