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

typedef struct
{
  uint64_t *malloc_state;
} proto_context;

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

#endif
