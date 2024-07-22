#ifndef STACK_COMMON_H_INCLUDED
#define STACK_COMMON_H_INCLUDED

#include "stack.h"

enum {
  size_offset = 1,
  cap_offset = 0,
};

static size_t stack_impl_size(void *s) {
  uint64_t *stack = (uint64_t *)s;
  return stack[size_offset];
}

static size_t stack_impl_capacity(void *s) {
  uint64_t *stack = (uint64_t *)s;
  return stack[cap_offset];
}

static inline uint64_t * stack_impl_ith(void *s, uint64_t v) {
  uint64_t *stack = (uint64_t *)s;
  size_t sz = stack_impl_size(s);
  return &stack[2 + sz - v - 1];
}

static void stack_impl_push(void *s, uint64_t v) {
  uint64_t *stack = (uint64_t *)s;
  size_t sz = stack_impl_size(s);
  stack[2 + sz] = v;
  stack[size_offset] = sz + 1;
}

static uint64_t stack_impl_peek(void *s) {
  uint64_t *stack = (uint64_t *)s;
  size_t sz = stack_impl_size(s);
  return stack[2 + sz - 1];
}

static void stack_impl_drop(void *s) {
  uint64_t *stack = (uint64_t *)s;
  size_t sz = stack_impl_size(s);
  stack[size_offset] = sz - 1;
}

#endif
