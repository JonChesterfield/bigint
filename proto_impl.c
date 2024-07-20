#include "proto.h"
#include <stdlib.h>

#include "vendor/libtommath/tommath.h"

_Static_assert(MP_DIGIT_BIT == 60, "");
_Static_assert(sizeof(mp_digit) == 8, "");

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

size_t proto_used(proto x) { return x->used; }
size_t proto_alloced(proto x) { return x->alloc; }

bool proto_zpos(proto x) { return x->zpos; }
bool proto_neg(proto x) { return !proto_zpos(x); }

void proto_swap(proto *x, proto *y)
{
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
    for (size_t i = alloced; i < digits; i++) {
      r->digits[i] = 0;
    }
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


_Static_assert(offsetof(struct proto_ty, digits) == 24, "");

// Cast carefully as it's the same underlying memory
mp_int proto_to_mp_int(proto x)
{
  mp_int res;
  res.used = proto_used(x);
  res.alloc = proto_alloced(x);
  res.sign =
    proto_zpos(x) ? MP_ZPOS : MP_NEG;
  res.dp = &x->digits[0];
  return res;
}

proto mp_int_to_proto(mp_int *x)
{
  return (proto) ((char*)x->dp - offsetof(struct proto_ty, digits));
}

mp_err mp_init_size(mp_int *a, int size)
{
   if (size < 0) {
      return MP_VAL;
   }

   enum {
     sizeof_bits = ((size_t)CHAR_BIT * sizeof(long long)),
     min_prec = ((((int)sizeof_bits + MP_DIGIT_BIT) - 1) / MP_DIGIT_BIT)
   };

   size = (min_prec > size) ? min_prec : size;
   
   proto p = proto_create(size);
   if (proto_valid(p))
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
      proto_destroy(p);
      a->dp = NULL;
      a->alloc = 0;
      a->used = 0;
      a->sign = MP_ZPOS;
    }
}
    
mp_err mp_grow(mp_int *a, int size)
{
  if (size < 0)
    return MP_VAL;

  proto p = mp_int_to_proto(a);
  if (proto_resize(&p, size))
    {
      *a = proto_to_mp_int(p);
      return  MP_OKAY ; 
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
