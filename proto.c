#include "vendor/EvilUnit/EvilUnit.h"

#include "proto.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

EVILUNIT_MAIN_MODULE() {
  TEST("Initial") {
    proto p = proto_create(4);

    CHECK(proto_valid(p));
    CHECK(proto_zpos(p));
    CHECK(!proto_neg(p));
    CHECK(proto_is_zero(p));
    CHECK(proto_used(p) == 0);
    CHECK(proto_alloced(p) == 4);

    proto q = proto_copy(p);

    CHECK(proto_valid(q));
    CHECK(proto_zpos(q));
    CHECK(!proto_neg(q));
    CHECK(proto_used(q) == 0);
    CHECK(proto_alloced(q) == 4);

    proto_destroy(q);
    proto_destroy(p);
  }

  TEST("small values") {
    for (unsigned i = 0; i < 4; i++) {
      proto p = proto_from_u32(i);
      CHECK(proto_valid(p));
      CHECK(proto_zpos(p));
      CHECK(!proto_neg(p));
      CHECK(proto_is_zero(p) == (i == 0));
      proto_destroy(p);
    }

    {
      proto p = proto_from_u32(3);
      proto q = proto_from_u32(5);
      CHECK(!proto_equal(p, q));
      proto_destroy(q);
      proto_destroy(p);
    }

    {
      proto p = proto_create(4);
      CHECK(proto_alloced(p) == 4);
      CHECK(proto_resize(&p, 8));
      CHECK(proto_alloced(p) == 8);
      proto_destroy(p);
    }
  }

  TEST("small arithmetic") {
    proto x = proto_from_u32(13);
    proto y = proto_from_u32(7);

    {
      proto z = proto_add(x, y);
      CHECK(proto_to_u32(z) == 20);
      proto_destroy(z);
    }

    {
      proto z = proto_sub(x, y);
      CHECK(proto_to_u32(z) == 6);
      proto_destroy(z);
    }

    {
      proto z = proto_mul(x, y);
      CHECK(proto_to_u32(z) == 13 * 7);
      proto_destroy(z);
    }

    {
      proto z = proto_div(x, y);
      CHECK(proto_to_u32(z) == 13 / 7);
      proto_destroy(z);
    }

    {
      proto z = proto_rem(x, y);
      CHECK(proto_to_u32(z) == 13 % 7);
      proto_destroy(z);
    }

    proto_destroy(x);
    proto_destroy(y);
  }
}
