#include "proto.h"

proto proto_from_base10(proto_context ctx, const char *bytes, size_t width)
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
