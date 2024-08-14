#include "bigint.hpp"
#include "base_operations.hpp"

#include "bigint_tommath.hpp"

#include "interpreter.hpp"
#include "lexer.h"

#include <stdint.h>
#include <stdlib.h>

#include <array>
#include <iostream>
#include <iterator>
#include <vector>

struct bigint_data
{
  int used = 0;
  int alloc = 0;
  bool sign = true;
  bool valid = false;
  bool is_fixed = true;
  int64_t fixed = 0;
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

  static bool create_fixed(mp_int* a, int32_t v)
  {
    return create_fixed(a, (int64_t)v);
  }

  static bool create_fixed(mp_int* a, int64_t v) {
    a->used = 0;
    a->alloc = 0;
    a->sign = v < 0;
    a->valid = true;
    a->is_fixed = true;
    a->fixed = v;
    a->dp = 0;
    return true;
  }

  static bool open_fixed(mp_int* a, int64_t* out)
  {
    if (a->is_fixed)
      {
        *out = a->fixed;
        return true;
      }
    else
      {
        *out = 0;
        return false;
      }
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

const constexpr bigint::vtable<bigint_data> vtab =
    bigint::create_vtable<bigint_data>();

extern "C"
{
  int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
  {
    const char* str = (const char*)Data;
    const char* lim = str + Size;

    parse_result p = parse(str, lim);
    if ((p.op < bigint_lexer_first_function) ||
        (p.op > bigint_lexer_last_function))
      {
        // If parse failed or was a single number, discard it
        return -1;
      }

    bigint_data res = bigint::interp<bigint_data>(vtab, str, lim);

    bigint::base_operations<bigint_data>::destroy(&res);

    return 0;  // accept
  }
}

const std::size_t INIT_BUFFER_SIZE = 1024;

__attribute__((weak)) int main()
{
  std::vector<char> input;

  {
    std::freopen(nullptr, "rb", stdin);

    if(std::ferror(stdin)) return 1;

    std::size_t len;
    std::array<char, INIT_BUFFER_SIZE> buf;

    while((len = std::fread(buf.data(), sizeof(buf[0]), buf.size(), stdin)) > 0)
      {
        if(std::ferror(stdin) && !std::feof(stdin)) return 2;

        input.insert(input.end(), buf.data(), buf.data() + len); // append to vector
      }
  }

  input.push_back('\0');


  const char * d = input.data();
  size_t w = input.size();

  bigint_data res = bigint::interp<bigint_data>(vtab, d, d + w);

  if (!bigint::is_invalid(res))
    {
      size_t len = bigint::decimal_length(res);
      // printf("Parsed %s, result uses %zu bytes\n", d, len);

      if (len != SIZE_MAX)
        {
          input.clear();
          input.reserve(len);

          size_t r = bigint::to_decimal(res, input.data(), input.capacity());
          if (r == SIZE_MAX)
            {
              fprintf(stderr, "to_decimal failed, gave it %zu bytes\n",
                      input.capacity());
            }
          else if (r != len)
            {
              fprintf(stderr,
                      "internal consistency error, length claimed %zu but "
                      "to_decimal wrote %zu\n",
                      len, r);
            }
          else
            {
              // success
              printf("%.*s\n", (int)r, input.data());
            }
        }
    }
  else
    {
      fprintf(stderr, "Rejected %s\n", d);
    }

  bigint::base_operations<bigint_data>::destroy(&res);

  return 0;
}
