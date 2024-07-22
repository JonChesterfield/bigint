#ifndef STACK_LIBC_H_INCLUDED
#define STACK_LIBC_H_INCLUDED

#include "stack.common.h"

#include <stdlib.h>

static void *stack_libc_create(void) {
  uint64_t *res = malloc(2 * sizeof(uint64_t));
  if (res) {
    res[cap_offset] = 0;
    res[size_offset] = 0;
  }
  return res;
}

static void stack_libc_destroy(void *s) { free(s); }

static void *stack_libc_reserve(void *s, size_t N) {
  if (N <= stack_impl_capacity(s)) {
    return s;
  }
  uint64_t *r = realloc(s, (2 + N) * sizeof(uint64_t));
  if (r) {
    r[cap_offset] = N;
  }
  return r;
}

static const struct stack_module_ty stack_libc = {
    .create = stack_libc_create,
    .destroy = stack_libc_destroy,
    .size = stack_impl_size,
    .capacity = stack_impl_capacity,
    .reserve = stack_libc_reserve,
    .push = stack_impl_push,
    .peek = stack_impl_peek,
    .drop = stack_impl_drop,
};

#endif
