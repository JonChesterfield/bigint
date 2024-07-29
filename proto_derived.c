#include "proto.h"
#include <stdio.h>

// reference allocates much more than fast+move
// current test suite (moving target, it's whatever is in the fuzz dir) has:

// both:
// 31m
// total heap usage: 819,654,466 allocs, 114,534,478,024 bytes allocated

// ref:
// 30m19
// 818,128,671 allocs, 114,351,220,544 bytes allocated

// fast_move:
// 3m57
// heap usage: 3,032,951 allocs, 543,236,824 bytes allocated

#define WITH_REF 0   // simple code path
#define WITH_FAST 1  // use uint32_t values instead of bigint everywhere
#define WITH_MOVE 1  // avoids more allocations by mutating in place

static uint32_t next_n(const char *bytes, size_t N, bool *bad)
{
  // todo, 64 bit
  uint32_t cursor = 0;
  for (size_t i = 0; i < N; i++)
    {
      char b = (bytes[i] - '0');
      if (b < 0 || b > 9) *bad = true;
      cursor *= 10;
      cursor += (unsigned)b;
    }
  return cursor;
}

static proto muladd32_move(proto_context ctx, proto acc, uint32_t mul,
                           uint32_t cursor)
{
  // destroys acc
#if WITH_MOVE
  acc = proto_mul_u32_move(ctx, acc, mul);
  return proto_valid(ctx, acc) ? proto_add_u32_move(ctx, acc, cursor)
                               : proto_create_invalid();
#else
  proto tmp0 = proto_mul_u32(ctx, acc, mul);
  if (proto_valid(ctx, tmp0))
    {
      proto res = proto_add_u32(ctx, tmp0, cursor);
      proto_destroy(ctx, tmp0);
      proto_destroy(ctx, acc);
      return res;
    }
  else
    {
      proto_destroy(ctx, acc);
      return proto_create_invalid();
    }
#endif
}

static proto proto_from_base10_faster(proto_context ctx, const char *bytes,
                                      size_t width)
{
  if (width == 0)
    {
      return proto_create_invalid();
    }

  bool neg = bytes[0] == '-';
  if (neg)
    {
      if (width == 1)
        {
          return proto_create_invalid();
        }
      bytes++;
      width--;
    }

  // trim leading '0' here?

  bool bad = false;
  size_t lim = width < 8 ? width : 8;

  uint32_t cur = next_n(bytes, lim, &bad);
  if (bad)
    {
      return proto_create_invalid();
    }

#if WITH_MOVE
    // Move means adding to zero is cheap, can control the allocation size
    // size is in base ten, can use the number of base ten values stored in a
    // digit to get an overestimate of the storage needed

#if 1
  const uint32_t base_ten_per =
      proto_base_ten_per_digit(ctx);  // todo, make this compile time?
  size_t est = (width + base_ten_per - 1) / base_ten_per;
#else
  size_t est = 1;
#endif

  proto acc = proto_create(ctx, est);
  if (!proto_valid(ctx, acc))
    {
      return proto_create_invalid();
    }
  acc = proto_add_u32_move(ctx, acc, cur);
  // known valid, allocated at least one digit and cursor fits in that
#else
  proto acc = proto_from_u32(ctx, cur);
  if (!proto_valid(ctx, acc))
    {
      return proto_create_invalid();
    }

#endif

  bytes += lim;
  width -= lim;

  if (width == 0)
    {
      if (neg)
        {
#if WITH_MOVE
          acc = proto_neg_move(ctx, acc);
#else
          proto tmp1 = proto_neg(ctx, acc);
          proto_destroy(ctx, acc);
          acc = tmp1;
#endif
        }

      return acc;
    }

  if (!proto_valid(ctx, acc)) return acc;

  uint32_t mul = 100000000;

  while (width >= 8)
    {
      uint32_t cursor = next_n(bytes, 8, &bad);
      bytes += 8;
      width -= 8;

      if (bad)
        {
          proto_destroy(ctx, acc);
          return proto_create_invalid();
        }

      acc = muladd32_move(ctx, acc, mul, cursor);

      if (!proto_valid(ctx, acc))
        {
          return proto_create_invalid();
        }
    }

  {
    if (width != 0)
      {
        uint32_t mulby = 1;
        for (size_t i = 0; i < width; i++) mulby *= 10;

        mul = mulby;

        uint32_t cursor = next_n(bytes, width, &bad);
        if (bad)
          {
            proto_destroy(ctx, acc);
            return proto_create_invalid();
          }

        acc = muladd32_move(ctx, acc, mul, cursor);

        if (!proto_valid(ctx, acc))
          {
            return proto_create_invalid();
          }
      }

    if (neg)
      {
#if WITH_MOVE
        acc = proto_neg_move(ctx, acc);
#else
        proto tmp1 = proto_neg(ctx, acc);
        proto_destroy(ctx, acc);
        acc = tmp1;
#endif
      }

    return acc;
  }
}

static proto proto_from_base10_reference(proto_context ctx, const char *bytes,
                                         size_t width)
{
  // leaks pretty badly on the failure paths at present

  if (width == 0)
    {
      return proto_create_invalid();
    }

  bool neg = bytes[0] == '-';
  if (neg)
    {
      if (width == 1)
        {
          return proto_create_invalid();
        }
      bytes++;
      width--;
    }

  proto acc = proto_create(ctx, 1);
  if (!proto_valid(ctx, acc)) return proto_create_invalid();
  if (!proto_is_zero(ctx, acc))
    {
      proto_destroy(ctx, acc);
      return proto_create_invalid();
    }

  proto ten = proto_from_u32(ctx, 10);
  if (!proto_valid(ctx, ten))
    {
      proto_destroy(ctx, acc);
      return proto_create_invalid();
    }

  for (size_t i = 0; i < width; i++)
    {
      char b = (bytes[i] - '0');
      if (b < 0 || b > 9)
        {
          proto_destroy(ctx, acc);
          proto_destroy(ctx, ten);
          return proto_create_invalid();
        }

      {
        proto tmp = proto_mul(ctx, acc, ten);
        if (!proto_valid(ctx, tmp))
          {
            proto_destroy(ctx, acc);
            proto_destroy(ctx, ten);
            return proto_create_invalid();
          }
        proto_destroy(ctx, acc);
        acc = tmp;
      }

      {
        proto addend = proto_from_u32(ctx, (unsigned)b);
        if (!proto_valid(ctx, addend)) return proto_create_invalid();
        proto tmp = proto_add(ctx, acc, addend);
        if (!proto_valid(ctx, tmp)) return proto_create_invalid();
        proto_destroy(ctx, addend);
        proto_destroy(ctx, acc);
        acc = tmp;
      }
    }

  proto_destroy(ctx, ten);

  if (neg)
    {
      proto tmp = proto_neg(ctx, acc);
      proto_destroy(ctx, acc);
      acc = tmp;
    }

  return acc;
}

proto proto_from_base10(proto_context ctx, const char *bytes, size_t width)
{
#if WITH_REF
  proto res = proto_from_base10_reference(ctx, bytes, width);
#endif
#if WITH_FAST
  proto f = proto_from_base10_faster(ctx, bytes, width);
#endif

#if (WITH_REF & WITH_FAST)
  if (!proto_equal(ctx, res, f))
    {
      fprintf(stdout, "proto from base 10 internal error! width %zu %s\n",
              width, bytes);
      proto_dump(ctx, res);
      proto_dump(ctx, f);
      fflush(stdout);
    }

  proto_destroy(ctx, f);
  return res;
#else

#if WITH_REF
  return res;
#else
  return f;
#endif
#endif
}

static proto proto_from_enum(proto_context ctx, proto_cmp_res e)
{
  switch (e)
    {
      case proto_cmp_res_lt:
        return proto_neg_move(ctx, proto_from_u32(ctx, 1));
      case proto_cmp_res_eq:
        return proto_from_u32(ctx, 0);
      case proto_cmp_res_gt:
        return proto_from_u32(ctx, 1);
      default:
        return proto_create_invalid();
    }
}

proto proto_cmp(proto_context ctx, proto x, proto y)
{
  return proto_from_enum(ctx, proto_cmp_enum(ctx, x, y));
}

proto proto_cmp_u32(proto_context ctx, proto x, uint32_t y)
{
  return proto_from_enum(ctx, proto_cmp_enum_u32(ctx, x, y));
}
