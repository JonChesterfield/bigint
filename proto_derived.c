#include "proto.h"
#include <stdio.h>

// Rough timings on this under valgrind
#if 0
fast
1m53
27,439,426 allocs, 27,439,426 frees, 4,345,449,904 bytes allocated

ref
12m24
215,283,256 allocs, 215,283,256 frees, 33,950,723,344 bytes allocated

both
13m52
242,232,141 allocs, 242,232,141 frees, 38,210,842,144 bytes allocated

  
fast and also THIN_MUL
1m19
21,950,266 allocs, 21,950,266 frees, 4,128,120,784 bytes allocated
#endif

#define WITH_REF 0
#define WITH_FAST 1

#define THIN_MUL 1

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

static proto muladd32(proto_context ctx, proto acc, uint32_t mul,
                      uint32_t cursor)
{
  proto tmp0 = proto_mul_u32(ctx, acc, mul);
  if (proto_valid(ctx, tmp0))
    {
      proto res = proto_add_u32(ctx, tmp0, cursor);
      proto_destroy(ctx, tmp0);
      return res;
    }
  else
    {
      return proto_create_invalid();
    }
}

static proto muladd(proto_context ctx, proto acc, proto mul, uint32_t cursor)
{
  proto tmp0 = proto_from_u32(ctx, cursor);
  proto tmp1 = proto_mul(ctx, acc, mul);

  bool ok = proto_valid(ctx, tmp0) && proto_valid(ctx, tmp1);

  proto tmp2 = ok ? proto_add(ctx, tmp0, tmp1) : proto_create_invalid();

  if (proto_valid(ctx, tmp0)) proto_destroy(ctx, tmp0);
  if (proto_valid(ctx, tmp1)) proto_destroy(ctx, tmp1);

  return tmp2;
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

  bool bad = false;
  size_t lim = width < 8 ? width : 8;

  proto acc = bad ? proto_create_invalid()
                  : proto_from_u32(ctx, next_n(bytes, lim, &bad));

  bytes += lim;
  width -= lim;

  if (width == 0)
    {
      if (neg)
        {
          proto tmp1 = proto_neg(ctx, acc);
          proto_destroy(ctx, acc);
          acc = tmp1;
        }

      return acc;
    }

  if (!proto_valid(ctx, acc)) return acc;

#if THIN_MUL
  uint32_t mul = 100000000;
#else
  proto mul = proto_from_u32(ctx, 100000000);
  if (!proto_valid(ctx, mul))
    {
      proto_destroy(ctx, acc);
      return proto_create_invalid();
    }
#endif

  while (width >= 8)
    {
      uint32_t cursor = next_n(bytes, 8, &bad);
      bytes += 8;
      width -= 8;

#if THIN_MUL
      proto tmp = muladd32(ctx, acc, mul, cursor);
#else
      proto tmp = muladd(ctx, acc, mul, cursor);

#endif
      proto_destroy(ctx, acc);

      if (proto_valid(ctx, tmp) && !bad)
        {
          acc = tmp;
        }
      else
        {
          if (proto_valid(ctx, tmp)) proto_destroy(ctx, tmp);
#if THIN_MUL
#else
          proto_destroy(ctx, mul);
#endif
          return proto_create_invalid();
        }
    }

  {
    if (width != 0)
      {
        uint32_t mulby = 1;
        for (size_t i = 0; i < width; i++) mulby *= 10;

#if THIN_MUL
        mul = mulby;
#else
        {
          proto nm = proto_from_u32(ctx, mulby);
          if (proto_valid(ctx, nm))
            {
              proto_destroy(ctx, mul);
              mul = nm;
            }
          else
            {
              bad = true;
            }
        }
#endif

        uint32_t cursor = next_n(bytes, width, &bad);
#if THIN_MUL
        proto tmp = muladd32(ctx, acc, mul, cursor);
#else
        proto tmp = muladd(ctx, acc, mul, cursor);
#endif
        proto_destroy(ctx, acc);
#if THIN_MUL
#else
        proto_destroy(ctx, mul);
#endif

        if (bad)
          {
            proto_destroy(ctx, tmp);
            return proto_create_invalid();
          }

        acc = tmp;
      }
    else
      {
#if THIN_MUL
#else
        proto_destroy(ctx, mul);
#endif
      }

    if (neg)
      {
        proto tmp1 = proto_neg(ctx, acc);
        proto_destroy(ctx, acc);
        acc = tmp1;
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
