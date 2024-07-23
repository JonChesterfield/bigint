#include "proto.h"
#include <assert.h>
#include <stdlib.h>

#include "vendor/libtommath/tommath.h"

_Static_assert(MP_DIGIT_BIT == 60, "");
_Static_assert(sizeof(mp_digit) == 8, "");

_Static_assert(offsetof(struct proto_ty, digits) == 24, "");

static bool can_alloc(proto_context ctx, size_t bytes)
{
  (void)bytes;
  uint64_t s = *(ctx.malloc_state);
  if (s == UINT64_MAX)
    {
      return true;
    }
  if (s == 0)
    {
      // fprintf(stderr, "Out of memory tokens!\n");
      return false;
    }
  (*ctx.malloc_state) = s - 1;
  return true;
}

// Cast carefully as it's the same underlying memory
static mp_int proto_to_mp_int(proto x)
{
  mp_int res;
  res.used = proto_used(x);
  res.alloc = proto_alloced(x);
  res.sign = proto_zpos(x) ? MP_ZPOS : MP_NEG;
  res.dp = &x->digits[0];
  return res;
}

static proto mp_int_to_proto(mp_int *x)
{
  // The mp_int instance may have updated used/zpos fields which
  // aren't yet reflected in the underlying proto instance
  proto res = (proto)((char *)x->dp - offsetof(struct proto_ty, digits));
  res->used = x->used;
  res->zpos = (x->sign == MP_ZPOS);
  return res;
}

proto proto_create(proto_context ctx, size_t digits)
{
  size_t bytes = sizeof(struct proto_ty) + digits * sizeof(uint64_t);
  proto state = can_alloc(ctx, bytes) ? malloc(bytes) : 0;
  if (state)
    {
      state->used = 0;
      state->alloc = digits;
      state->zpos = true;
      for (size_t i = 0; i < digits; i++)
        {
          state->digits[i] = 0;
        }
    }
  return state;
}

proto proto_create_invalid(void) { return NULL; }

bool proto_valid(proto_context ctx, proto x) { return x != NULL; }

void proto_destroy(proto_context ctx, proto x) { free(x); }

proto proto_copy(proto_context ctx, proto x)
{
  size_t digits = proto_alloced(x);
  proto res = proto_create(ctx, digits);
  if (res)
    {
      res->used = x->used;
      res->alloc = x->alloc;
      res->zpos = x->zpos;
      for (size_t i = 0; i < digits; i++)
        {
          res->digits[i] = x->digits[i];
        }
    }
  return res;
}

void proto_dump(proto_context ctx, proto x)
{
  if (!proto_valid(ctx, x))
    {
      printf("(proto) <invalid>\n");
      return;
    }
  if (proto_is_sentinel(x))
    {
      printf("(proto) <sentinel>\n");
      return;
    }
  size_t alloc = x->alloc;
  printf(
      "(proto)\n"
      "{\n"
      "  .used = %zu,\n"
      "  .alloc = %zu,\n"
      "  .zpos = %u,\n"
      "  .digits[%lu] =\n  {\n",
      x->used, alloc, x->zpos, alloc);

  for (size_t i = 0; i < alloc; i++)
    {
      printf("    %lu,\n", x->digits[i]);
    }

  printf(
      ""
      "  },\n"
      "}\n");
}

proto proto_sentinel(void)
{
  static struct proto_ty p = {
      .used = ~0,
      .alloc = ~0,
      .zpos = false,
  };
  return &p;
}

bool proto_is_sentinel(proto x) { return x == proto_sentinel(); }

size_t proto_used(proto x) { return x->used; }
size_t proto_alloced(proto x) { return x->alloc; }
bool proto_zpos(proto x) { return x->zpos; }

bool proto_is_zero(proto_context ctx, proto x)
{
  uint64_t N = proto_used(x);
  for (uint64_t i = 0; i < N; i++)
    {
      if (x->digits[i] != 0)
        {
          return false;
        }
    }
  return true;
}

bool proto_resize(proto_context ctx, proto *x, size_t digits)
{
  size_t alloced = proto_alloced(*x);
  size_t bytes = sizeof(struct proto_ty) + digits * sizeof(uint64_t);
  proto p = *x;
  proto r = can_alloc(ctx, bytes) ? realloc(p, bytes) : 0;
  if (r)
    {
      r->alloc = digits;
      for (size_t i = alloced; i < digits; i++)
        {
          r->digits[i] = 0;
        }
      *x = r;
      return true;
    }
  else
    {
      return false;
    }
}

bool proto_equal(proto_context ctx, proto x, proto y)
{
  uint64_t N = proto_used(x);
  if (N != proto_used(y))
    {
      return false;
    }

  if (x->zpos != y->zpos)
    {
      return false;
    }

  for (uint64_t i = 0; i < N; i++)
    {
      if (x->digits[i] != y->digits[i])
        {
          return false;
        }
    }

  return true;
}

// Implement the rest in terms of libtommath and careful casting

// Pass a context object around without modifying the libtommath api
static proto_context *global(void);
static void global_set(proto_context *ctx);
static void global_clear(void);

proto proto_from_u32(proto_context ctx, uint32_t val)
{
  proto p = proto_create(ctx, 1);
  if (!proto_valid(ctx, p))
    {
      return p;
    }

  mp_int tmp = proto_to_mp_int(p);

  global_set(&ctx);
  mp_set_u32(&tmp, val);
  global_clear();

  return mp_int_to_proto(&tmp);
}

uint32_t proto_to_u32(proto_context ctx, proto x)
{
  assert(proto_valid(ctx, x));

  mp_int tmp = proto_to_mp_int(x);
  global_set(&ctx);
  uint32_t res = mp_get_u32(&tmp);
  global_clear();
  return res;
}

static proto proto_unary(proto_context ctx, proto x,
                         mp_err (*func)(const mp_int *, mp_int *))
{
  if (!proto_valid(ctx, x))
    {
      return proto_create_invalid();
    }

  proto y = proto_create(ctx, 1);

  mp_int mx = proto_to_mp_int(x);
  mp_int my = proto_to_mp_int(y);

  global_set(&ctx);
  mp_err res = func(&mx, &my);
  global_clear();

  if (res == MP_OKAY)
    {
      return mp_int_to_proto(&my);
    }
  else
    {
      proto_destroy(ctx, y);
      return proto_create_invalid();
    }
}

static proto proto_binary(proto_context ctx, proto x, proto y,
                          mp_err (*func)(const mp_int *, const mp_int *,
                                         mp_int *))
{
  if (!proto_valid(ctx, x) || !proto_valid(ctx, y))
    {
      return proto_create_invalid();
    }

  proto z = proto_create(ctx, 1);

  mp_int mx = proto_to_mp_int(x);
  mp_int my = proto_to_mp_int(y);
  mp_int mz = proto_to_mp_int(z);

  global_set(&ctx);
  mp_err res = func(&mx, &my, &mz);
  global_clear();

  if (res == MP_OKAY)
    {
      return mp_int_to_proto(&mz);
    }
  else
    {
      proto_destroy(ctx, z);
      return proto_create_invalid();
    }
}

static proto proto_mutating_unary(proto_context ctx, proto x,
                                  mp_err (*func)(mp_int *))
{
  if (!proto_valid(ctx, x))
    {
      return proto_create_invalid();
    }

  proto res = proto_copy(ctx, x);
  mp_int mx = proto_to_mp_int(res);
  global_set(&ctx);
  mp_err err = func(&mx);
  global_clear();
  if (err == MP_OKAY)
    {
      return mp_int_to_proto(&mx);
    }
  else
    {
      proto_destroy(ctx, res);
      return proto_create_invalid();
    }
}

proto proto_abs(proto_context ctx, proto x)
{
  return proto_unary(ctx, x, mp_abs);
}
proto proto_neg(proto_context ctx, proto x)
{
  return proto_unary(ctx, x, mp_neg);
}

proto proto_incr(proto_context ctx, proto x)
{
  return proto_mutating_unary(ctx, x, mp_incr);
}

proto proto_decr(proto_context ctx, proto x)
{
  return proto_mutating_unary(ctx, x, mp_decr);
}

proto proto_add(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_add);
}
proto proto_sub(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_sub);
}
proto proto_mul(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_mul);
}

static mp_err mp_div_quotient(const mp_int *a, const mp_int *b, mp_int *c)
{
  mp_int tmp;
  mp_err err;
  if ((err = mp_init(&tmp)) != MP_OKAY) return err;
  err = mp_div(a, b, c, &tmp);
  mp_clear(&tmp);
  return err;
}

proto proto_div(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_div_quotient);
}

static mp_err mp_div_remainder(const mp_int *a, const mp_int *b, mp_int *c)
{
  mp_int tmp;
  mp_err err;
  if ((err = mp_init(&tmp)) != MP_OKAY) return err;
  err = mp_div(a, b, &tmp, c);
  mp_clear(&tmp);
  return err;
}

proto proto_rem(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_div_remainder);
}

proto proto_or(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_or);
}
proto proto_and(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_and);
}
proto proto_xor(proto_context ctx, proto x, proto y)
{
  return proto_binary(ctx, x, y, mp_xor);
}

// Define the libtommath memory interface non-invasively

mp_err mp_init_size(mp_int *a, int size)
{
  if (size < 0)
    {
      return MP_VAL;
    }

  enum
  {
    sizeof_bits = ((size_t)CHAR_BIT * sizeof(long long)),
    min_prec = ((((int)sizeof_bits + MP_DIGIT_BIT) - 1) / MP_DIGIT_BIT)
  };

  size = (min_prec > size) ? min_prec : size;

  proto_context *ctx = global();
  proto p = proto_create(*ctx, size);
  if (proto_valid(*ctx, p))
    {
      *a = proto_to_mp_int(p);
      return MP_OKAY;
    }
  else
    {
      return MP_MEM;
    }
}

void mp_clear(mp_int *a)
{
  if (a->dp != NULL)
    {
      proto p = mp_int_to_proto(a);
      proto_context *ctx = global();
      proto_destroy(*ctx, p);
      a->dp = NULL;
      a->alloc = 0;
      a->used = 0;
      a->sign = MP_ZPOS;
    }
}

mp_err mp_grow(mp_int *a, int size)
{
  if (size < 0) return MP_VAL;

  proto p = mp_int_to_proto(a);
  proto_context *ctx = global();
  if (proto_resize(*ctx, &p, size))
    {
      *a = proto_to_mp_int(p);
      return MP_OKAY;
    }
  else
    {
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

static _Thread_local proto_context *global_mp_ctx = 0;

static proto_context *global(void)
{
  assert(global_mp_ctx != 0);
  return global_mp_ctx;
}
static void global_set(proto_context *ctx)
{
  assert(ctx != 0);
  assert(global_mp_ctx == 0);
  global_mp_ctx = ctx;
}
static void global_clear(void)
{
  assert(global_mp_ctx != 0);
  global_mp_ctx = 0;
}
