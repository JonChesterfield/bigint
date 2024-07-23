#include "proto.h"
#include <stdlib.h>

#include "vendor/libtommath/tommath.h"

_Static_assert(MP_DIGIT_BIT == 60, "");
_Static_assert(sizeof(mp_digit) == 8, "");

_Static_assert(offsetof(struct proto_ty, digits) == 24, "");

// Cast carefully as it's the same underlying memory
static mp_int proto_to_mp_int(proto x) {
  mp_int res;
  res.used = proto_used(x);
  res.alloc = proto_alloced(x);
  res.sign = proto_zpos(x) ? MP_ZPOS : MP_NEG;
  res.dp = &x->digits[0];
  return res;
}

static proto mp_int_to_proto(mp_int *x) {
  // The mp_int instance may have updated used/zpos fields which
  // aren't yet reflected in the underlying proto instance
  proto res = (proto)((char *)x->dp - offsetof(struct proto_ty, digits));
  res->used = x->used;
  res->zpos = (x->sign == MP_ZPOS);
  return res;
}

proto proto_create(size_t digits) {
  size_t bytes = sizeof(struct proto_ty) + digits * sizeof(uint64_t);
  proto state = malloc(bytes);
  if (state) {
    state->used = 0;
    state->alloc = digits;
    state->zpos = true;
    for (size_t i = 0; i < digits; i++) {
      state->digits[i] = 0;
    }
  }
  return state;
}

proto proto_create_invalid(void) { return NULL; }

bool proto_valid(proto x) { return x != NULL; }

void proto_destroy(proto x) { free(x); }

proto proto_copy(proto x) {
  size_t digits = proto_alloced(x);
  proto res = proto_create(digits);
  if (res) {
    res->used = x->used;
    res->alloc = x->alloc;
    res->zpos = x->zpos;
    for (size_t i = 0; i < digits; i++) {
      res->digits[i] = x->digits[i];
    }
  }
  return res;
}

void proto_dump(proto x) {
  if (!proto_valid(x)) {
    printf("(proto) <invalid>\n");
    return;
  }
  if (proto_is_sentinel(x)) {
    printf("(proto) <sentinel>\n");
    return;
  }
  size_t alloc = x->alloc;
  printf("(proto)\n"
         "{\n"
         "  .used = %zu,\n"
         "  .alloc = %zu,\n"
         "  .zpos = %u,\n"
         "  .digits[%lu] =\n  {\n",
         x->used, alloc, x->zpos, alloc);

  for (size_t i = 0; i < alloc; i++) {
    printf("    %lu,\n", x->digits[i]);
  }

  printf(""
         "  },\n"
         "}\n");
}

proto proto_sentinel(void) {
  static struct proto_ty p = {
      .used = ~0,
      .alloc = ~0,
      .zpos = false,
  };
  return &p;
}

bool proto_is_sentinel(proto x) { return x == proto_sentinel(); }

proto proto_from_u32(uint32_t val) {
  proto p = proto_create(1);
  mp_int tmp = proto_to_mp_int(p);
  mp_set_u32(&tmp, val);

  return mp_int_to_proto(&tmp);
}

uint32_t proto_to_u32(proto x) {
  mp_int tmp = proto_to_mp_int(x);
  return mp_get_u32(&tmp);
}

size_t proto_used(proto x) { return x->used; }
size_t proto_alloced(proto x) { return x->alloc; }

bool proto_zpos(proto x) { return x->zpos; }

bool proto_is_zero(proto x) {
  uint64_t N = proto_used(x);
  for (uint64_t i = 0; i < N; i++) {
    if (x->digits[i] != 0) {
      return false;
    }
  }
  return true;
}

void proto_swap(proto *x, proto *y) {
  proto tmp = *x;
  *x = *y;
  *y = tmp;
}

bool proto_resize(proto *x, size_t digits) {
  size_t alloced = proto_alloced(*x);
  size_t bytes = sizeof(struct proto_ty) + digits * sizeof(uint64_t);
  proto p = *x;
  proto r = realloc(p, bytes);
  if (r) {
    r->alloc = digits;
    for (size_t i = alloced; i < digits; i++) {
      r->digits[i] = 0;
    }
    *x = r;
    return true;
  } else {
    return false;
  }
}

bool proto_equal(proto x, proto y) {
  uint64_t N = proto_used(x);
  if (N != proto_used(y)) {
    return false;
  }

  if (x->zpos != y->zpos) {
    return false;
  }

  for (uint64_t i = 0; i < N; i++) {
    if (x->digits[i] != y->digits[i]) {
      return false;
    }
  }

  return true;
}

mp_err mp_init_size(mp_int *a, int size) {
  if (size < 0) {
    return MP_VAL;
  }

  enum {
    sizeof_bits = ((size_t)CHAR_BIT * sizeof(long long)),
    min_prec = ((((int)sizeof_bits + MP_DIGIT_BIT) - 1) / MP_DIGIT_BIT)
  };

  size = (min_prec > size) ? min_prec : size;

  proto p = proto_create(size);
  if (proto_valid(p)) {
    *a = proto_to_mp_int(p);
    return MP_OKAY;
  } else {
    return MP_MEM;
  }
}

void mp_clear(mp_int *a) {
  if (a->dp != NULL) {
    proto p = mp_int_to_proto(a);
    proto_destroy(p);
    a->dp = NULL;
    a->alloc = 0;
    a->used = 0;
    a->sign = MP_ZPOS;
  }
}

mp_err mp_grow(mp_int *a, int size) {
  if (size < 0)
    return MP_VAL;

  proto p = mp_int_to_proto(a);
  if (proto_resize(&p, size)) {
    *a = proto_to_mp_int(p);
    return MP_OKAY;
  } else {
    return MP_MEM;
  }
}

#if 0
// None of the mp functions call shrink
mp_err mp_shrink(mp_int *a)
{
  return MP_MEM;
}
#endif

static proto proto_unary(proto x, mp_err (*func)(const mp_int *, mp_int *)) {
  if (!proto_valid(x)) {
    return proto_create_invalid();
  }

  proto y = proto_create(1);

  mp_int mx = proto_to_mp_int(x);
  mp_int my = proto_to_mp_int(y);

  mp_err res = func(&mx, &my);
  if (res == MP_OKAY) {
    return mp_int_to_proto(&my);
  } else {
    proto_destroy(y);
    return proto_create_invalid();
  }
}

static proto proto_binary(proto x, proto y,
                          mp_err (*func)(const mp_int *, const mp_int *,
                                         mp_int *)) {
  if (!proto_valid(x) || !proto_valid(y)) {
    return proto_create_invalid();
  }

  proto z = proto_create(1);

  mp_int mx = proto_to_mp_int(x);
  mp_int my = proto_to_mp_int(y);
  mp_int mz = proto_to_mp_int(z);

  mp_err res = func(&mx, &my, &mz);
  if (res == MP_OKAY) {
    return mp_int_to_proto(&mz);
  } else {
    proto_destroy(z);
    return proto_create_invalid();
  }
}

proto proto_abs(proto x) { return proto_unary(x, mp_abs); }
proto proto_neg(proto x) { return proto_unary(x, mp_neg); }

proto proto_incr(proto x) {
  proto res = proto_copy(x);
  mp_int mx = proto_to_mp_int(res);
  mp_err err = mp_incr(&mx);

  if (err == MP_OKAY) {
    return mp_int_to_proto(&mx);
  } else {
    proto_destroy(res);
    return proto_create_invalid();
  }
}

proto proto_decr(proto x) {
  proto res = proto_copy(x);
  mp_int mx = proto_to_mp_int(res);
  mp_err err = mp_decr(&mx);

  if (err == MP_OKAY) {
    return mp_int_to_proto(&mx);
  } else {
    proto_destroy(res);
    return proto_create_invalid();
  }
}

proto proto_add(proto x, proto y) { return proto_binary(x, y, mp_add); }
proto proto_sub(proto x, proto y) { return proto_binary(x, y, mp_sub); }
proto proto_mul(proto x, proto y) { return proto_binary(x, y, mp_mul); }

static mp_err mp_div_quotient(const mp_int *a, const mp_int *b, mp_int *c) {
  mp_int tmp;
  mp_err err;
  if ((err = mp_init(&tmp)) != MP_OKAY)
    return err;
  err = mp_div(a, b, c, &tmp);
  mp_clear(&tmp);
  return err;
}

proto proto_div(proto x, proto y) {
  return proto_binary(x, y, mp_div_quotient);
}

static mp_err mp_div_remainder(const mp_int *a, const mp_int *b, mp_int *c) {
  mp_int tmp;
  mp_err err;
  if ((err = mp_init(&tmp)) != MP_OKAY)
    return err;
  err = mp_div(a, b, &tmp, c);
  mp_clear(&tmp);
  return err;
}

proto proto_rem(proto x, proto y) {
  return proto_binary(x, y, mp_div_remainder);
}

proto proto_or(proto x, proto y) { return proto_binary(x, y, mp_or); }
proto proto_and(proto x, proto y) { return proto_binary(x, y, mp_and); }
proto proto_xor(proto x, proto y) { return proto_binary(x, y, mp_xor); }
