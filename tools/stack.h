#ifndef TOOLS_STACK_H_INCLUDED
#define TOOLS_STACK_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define STACK_CONTRACT() 0

struct stack_module_ty;
typedef const struct stack_module_ty *stack_module;

// Returns null on failure, stack with capacity >= N on success
static inline void *stack_create(stack_module mod, size_t N);
static inline void stack_destroy(stack_module mod, void *s);

static inline size_t stack_size(stack_module mod, void *s);

// Push returns NULL on failure to allocate. If it fails, s is unchanged.
// If it succeeds, the passed argument s is no longer valid.
// Returns s if it didn't need to allocate
static inline void *stack_push(stack_module mod, void *s, uint64_t v);

// Requires non-empty stack
static inline uint64_t stack_pop(stack_module mod, void *s);

// Less convenient and potentially faster interface
static inline size_t stack_capacity(stack_module mod, void *s);
static inline void *stack_reserve(stack_module mod, void *s, size_t N);

static inline uint64_t stack_available(stack_module mod, void *s) {
  return stack_capacity(mod, s) - stack_size(mod, s);
}

static inline bool stack_request_available(stack_module mod, void **s, uint64_t N)
{
  void *stack = *s;
  if (stack_available(mod, stack) >= N) { return true; }

  void * maybe = stack_reserve(mod, stack, stack_size(mod, stack) + N);
  if (maybe)
    {
      stack_destroy(mod, stack);
      *s = maybe;
      return true;
    }
  else
    {
      return false;
    }
}

static inline void stack_push_assuming_capacity(stack_module mod, void *s,
                                                uint64_t v);
static inline uint64_t stack_peek(stack_module mod, void *s);
static inline void stack_drop(stack_module mod, void *s);

struct stack_module_ty {
  void *(*const create)(void);
  void (*const destroy)(void *);

  size_t (*const size)(void *);
  size_t (*const capacity)(void *);

  void *(*const reserve)(void *, size_t);

  // This push does not allocate
  void (*const push)(void *, uint64_t);

  // pop ~= peek then drop
  uint64_t (*const peek)(void *);
  void (*const drop)(void *);
};

#if STACK_CONTRACT()
#include <stdio.h>
#include <stdlib.h>
#endif

#define stack_require(X) stack_require_func(X, #X, __LINE__)
static inline void stack_require_func(bool expr, const char *name, int line) {
  const bool contract = STACK_CONTRACT();
  if (contract & !expr) {
#if STACK_CONTRACT()
    fprintf(stderr, "stack contract failed L%u: %s\n", line, name);
    abort();
#else
    (void)name;
    (void)line;
#endif
  }
}

static inline void *stack_create(stack_module mod, size_t N) {
  stack_require(mod);
  void *created = mod->create();
  if (!created) {
    return (void *)0;
  }

  stack_require(stack_size(mod, created) == 0);
  stack_require(stack_capacity(mod, created) == 0);

  void *reserved = stack_reserve(mod, created, N);
  if (!reserved) {
    stack_destroy(mod, created);
    return (void *)0;
  }

  stack_require(stack_size(mod, reserved) == 0);
  stack_require(stack_capacity(mod, reserved) >= N);
  return reserved;
}

static inline void stack_destroy(stack_module mod, void *s) {
  stack_require(mod);
  stack_require(s);
  mod->destroy(s);
}

static inline size_t stack_size(stack_module mod, void *s) {
  stack_require(mod);
  stack_require(s);
  return mod->size(s);
}

static inline void *stack_push(stack_module mod, void *s, uint64_t v) {
  stack_require(mod);
  stack_require(s);

  size_t size_before = stack_size(mod, s);
  size_t capacity_before = stack_capacity(mod, s);

  stack_require(capacity_before >= size_before);

  if (size_before == capacity_before) {
    void *res = stack_reserve(mod, s, capacity_before + 1);
    if (!res) {
      return res;
    }
    s = res;
#if STACK_CONTRACT()
    capacity_before = stack_capacity(mod, s);
#endif
  }

  stack_require(capacity_before > size_before);

  stack_push_assuming_capacity(mod, s, v);

#if STACK_CONTRACT()
  size_t size_after = stack_size(mod, s);
  size_t capacity_after = stack_capacity(mod, s);

  stack_require(size_before + 1 == size_after);
  stack_require(capacity_before == capacity_after);
  stack_require(capacity_after >= size_after);
#endif

  return s;
}

static inline uint64_t stack_pop(stack_module mod, void *s) {
  stack_require(mod);
  stack_require(s);
#if STACK_CONTRACT()
  size_t size_before = stack_size(mod, s);
  size_t capacity_before = stack_capacity(mod, s);
  stack_require(size_before > 0);
  stack_require(capacity_before >= size_before);
#endif

  uint64_t res = stack_peek(mod, s);
  stack_drop(mod, s);

#if STACK_CONTRACT()
  stack_require(size_before - 1 == stack_size(mod, s));
  stack_require(capacity_before == stack_capacity(mod, s));
#endif

  return res;
}

static inline size_t stack_capacity(stack_module mod, void *s) {
  stack_require(mod);
  stack_require(s);
  return mod->capacity(s);
}

static inline void *stack_reserve(stack_module mod, void *s, size_t N) {
  stack_require(mod);
  stack_require(s);
  if (N == 0) {
    return s;
  }

#if STACK_CONTRACT()
  size_t size_before = stack_size(mod, s);
  size_t capacity_before = stack_capacity(mod, s);
  stack_require(capacity_before >= size_before);
#endif

  void *res = mod->reserve(s, N);

#if STACK_CONTRACT()
  size_t size_after = stack_size(mod, res ? res : s);
  size_t capacity_after = stack_capacity(mod, res ? res : s);
  if (res)
    {
      // Succeeded, can't look at s again
      stack_require(capacity_after >= N);
    }
  else
    {
      // Failed, s still valid
      stack_require(size_before == size_after);
    }
  stack_require(size_before == size_after);
#endif
  
  return res;
}

static inline void stack_push_assuming_capacity(stack_module mod, void *s,
                                                uint64_t v) {
  stack_require(mod);
  stack_require(s);
#if STACK_CONTRACT()
  size_t size_before = stack_size(mod, s);
  size_t capacity_before = stack_capacity(mod, s);
  stack_require(capacity_before > size_before);
#endif

  mod->push(s, v);

#if STACK_CONTRACT()
  size_t size_after = stack_size(mod, s);
  size_t capacity_after = stack_capacity(mod, s);
  stack_require(size_before + 1 == size_after);
  stack_require(capacity_before == capacity_after);
  stack_require(capacity_after >= size_after);
#endif

  stack_require(v == stack_peek(mod, s));
}

static inline uint64_t stack_peek(stack_module mod, void *s) {
  stack_require(mod);
  stack_require(s);

#if STACK_CONTRACT()
  size_t size_before = stack_size(mod, s);
  size_t capacity_before = stack_capacity(mod, s);
  stack_require(size_before > 0);
  stack_require(capacity_before >= size_before);
#endif

  uint64_t res = mod->peek(s);

#if STACK_CONTRACT()
  size_t size_after = stack_size(mod, s);
  size_t capacity_after = stack_capacity(mod, s);
  stack_require(size_before == size_after);
  stack_require(capacity_before == capacity_after);
#endif

  return res;
}

static inline void stack_drop(stack_module mod, void *s) {
  stack_require(mod);
  stack_require(s);

#if STACK_CONTRACT()
  size_t size_before = stack_size(mod, s);
  size_t capacity_before = stack_capacity(mod, s);
  stack_require(size_before > 0);
  stack_require(capacity_before >= size_before);
#endif

  mod->drop(s);

#if STACK_CONTRACT()
  size_t size_after = stack_size(mod, s);
  size_t capacity_after = stack_capacity(mod, s);
  stack_require(size_before - 1 == size_after);
  stack_require(capacity_before == capacity_after);
#endif
}

#endif
