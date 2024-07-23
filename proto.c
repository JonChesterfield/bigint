#include "vendor/EvilUnit/EvilUnit.h"

#include "proto.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

EVILUNIT_MODULE(proto)
{
  uint64_t malloc_state = UINT64_MAX;
  proto_context ctx = {
      .malloc_state = &malloc_state,
  };

  TEST("Initial")
  {
    proto p = proto_create(ctx, 4);

    CHECK(proto_valid(ctx, p));
    CHECK(proto_zpos(p));
    CHECK(proto_is_zero(ctx, p));
    CHECK(proto_used(p) == 0);
    CHECK(proto_alloced(p) == 4);

    proto q = proto_copy(ctx, p);

    CHECK(proto_valid(ctx, q));
    CHECK(proto_zpos(q));
    CHECK(proto_used(q) == 0);
    CHECK(proto_alloced(q) == 4);

    proto_destroy(ctx, q);
    proto_destroy(ctx, p);
  }

  TEST("small values")
  {
    for (unsigned i = 0; i < 4; i++)
      {
        proto p = proto_from_u32(ctx, i);
        CHECK(proto_valid(ctx, p));
        CHECK(proto_zpos(p));
        CHECK(proto_is_zero(ctx, p) == (i == 0));
        proto_destroy(ctx, p);
      }

    {
      proto p = proto_from_u32(ctx, 3);
      proto q = proto_from_u32(ctx, 5);
      CHECK(!proto_equal(ctx, p, q));
      proto_destroy(ctx, q);
      proto_destroy(ctx, p);
    }

    {
      proto p = proto_create(ctx, 4);
      CHECK(proto_alloced(p) == 4);
      CHECK(proto_resize(ctx, &p, 8));
      CHECK(proto_alloced(p) == 8);
      proto_destroy(ctx, p);
    }
  }

  TEST("small arithmetic")
  {
    proto x = proto_from_u32(ctx, 13);
    proto y = proto_from_u32(ctx, 7);

    {
      proto z = proto_add(ctx, x, y);
      CHECK(proto_to_u32(ctx, z) == 20);
      proto_destroy(ctx, z);
    }

    {
      proto z = proto_sub(ctx, x, y);
      CHECK(proto_to_u32(ctx, z) == 6);
      proto_destroy(ctx, z);
    }

    {
      proto z = proto_mul(ctx, x, y);
      CHECK(proto_to_u32(ctx, z) == 13 * 7);
      proto_destroy(ctx, z);
    }

    {
      proto z = proto_div(ctx, x, y);
      CHECK(proto_to_u32(ctx, z) == 13 / 7);
      proto_destroy(ctx, z);
    }

    {
      proto z = proto_rem(ctx, x, y);
      CHECK(proto_to_u32(ctx, z) == 13 % 7);
      proto_destroy(ctx, z);
    }

    proto_destroy(ctx, x);
    proto_destroy(ctx, y);
  }

  TEST("resize")
  {
    proto x = proto_from_u32(ctx, 13);
    proto y = proto_from_u32(ctx, 13);
    CHECK(proto_equal(ctx, x, y));
    CHECK(proto_resize(ctx, &y, 16));
    CHECK(proto_equal(ctx, x, y));
    CHECK(proto_resize(ctx, &y, 2));
    CHECK(proto_equal(ctx, x, y));
    proto_destroy(ctx, x);
    proto_destroy(ctx, y);
  }
}
