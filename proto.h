#ifndef PROTO_H_INCLUDED
#define PROTO_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct proto_ty
{
  size_t used;
  size_t alloc;
  bool zpos;
  uint64_t digits[];
};

typedef struct proto_ty *proto;


struct proto_context_ty
{
  uint64_t malloc_fuel;
  uint64_t malloc_count;
};

typedef struct proto_context_ty *proto_context;

static inline void proto_context_set_fuel_value(proto_context context, uint64_t value)
{
  context->malloc_fuel = value;
}

static inline uint64_t proto_context_fuel_value(proto_context context)
{
  return context->malloc_fuel;
}

static inline void proto_context_fuel_decrement(proto_context context)
{
  if (context->malloc_fuel != UINT64_MAX)
    {
      context->malloc_fuel--;
    }
}


static inline void proto_context_set_count_value(proto_context context, uint64_t value)
{
  context->malloc_count = value;
}

static inline uint64_t proto_context_count_value(proto_context context)
{
  return context->malloc_count;
}

static inline void proto_context_count_increment(proto_context context)
{
  if (context->malloc_count != UINT64_MAX)
    {
      context->malloc_count++;
    }
}


static inline void proto_context_init(proto_context context)
{
  proto_context_set_fuel_value(context, UINT64_MAX);
  proto_context_set_count_value(context, 0);
}




// Create zero with at least digits allocated space
proto proto_create(proto_context ctx, size_t digits);
proto proto_create_invalid(void);
bool proto_valid(proto_context ctx, proto x);  // allocation succeeded
void proto_destroy(proto_context ctx, proto x);
proto proto_copy(proto_context ctx, proto x);
void proto_dump(proto_context ctx, proto x);

// Shim for parser generator, wants a sentinel value distinct from failure
proto proto_sentinel(void);
bool proto_is_sentinel(proto x);

proto proto_from_u32(proto_context ctx, uint32_t);
uint32_t proto_to_u32(proto_context ctx, proto);  // truncates

size_t proto_used(proto x);
size_t proto_alloced(proto x);

bool proto_zpos(proto x);  // zero or positive

bool proto_is_zero(proto_context ctx, proto x);

// true on success is probably worse than an enum
bool proto_resize(proto_context ctx, proto *x, size_t digits);

bool proto_equal(proto_context ctx, proto x, proto y);

// Number of base 10 digits
size_t proto_count_base10(proto_context ctx, proto x);

// Read N [-]?[0-9]+ digits into a bit integer
proto proto_from_base10(proto_context ctx, const char *, size_t N);

static inline proto proto_from_base10_cstr(proto_context ctx, const char *str)
{
  size_t N = __builtin_strlen(str);
  return proto_from_base10(ctx, str, N);
}

// Write proto into out, returning how many bytes written
size_t proto_into_base10(proto_context ctx, proto, char *out, size_t N);

proto proto_abs(proto_context ctx, proto x);
proto proto_neg(proto_context ctx, proto x);
proto proto_incr(proto_context ctx, proto x);
proto proto_decr(proto_context ctx, proto x);

proto proto_add(proto_context ctx, proto x, proto y);
proto proto_sub(proto_context ctx, proto x, proto y);
proto proto_mul(proto_context ctx, proto x, proto y);
proto proto_div(proto_context ctx, proto x, proto y);
proto proto_rem(proto_context ctx, proto x, proto y);

proto proto_or(proto_context ctx, proto x, proto y);
proto proto_and(proto_context ctx, proto x, proto y);
proto proto_xor(proto_context ctx, proto x, proto y);

proto proto_add_u32(proto_context ctx, proto x, uint32_t y);
proto proto_mul_u32(proto_context ctx, proto x, uint32_t y);

// As above, except they call destroy on the arguments
proto proto_abs_move(proto_context ctx, proto x);
proto proto_neg_move(proto_context ctx, proto x);

proto proto_add_u32_move(proto_context ctx, proto x, uint32_t y);
proto proto_mul_u32_move(proto_context ctx, proto x, uint32_t y);

// Misc, not sure how to expose this interface yet
// need to know how big a digit is to know how many to allocate
// it's the base 2 number that can be stored in a single digit
uint64_t proto_digit_max(proto_context);
uint32_t proto_base_ten_per_digit(proto_context);

#endif
