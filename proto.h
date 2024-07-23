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

// Create zero with at least digits allocated space
proto proto_create(size_t digits);
proto proto_create_invalid(void);
bool proto_valid(proto x);  // allocation succeeded
void proto_destroy(proto x);
proto proto_copy(proto x);
void proto_dump(proto x);

typedef struct
{
  char unused;
} proto_context;

// Shim for parser generator, wants a sentinel value distinct from failure
proto proto_sentinel(void);
bool proto_is_sentinel(proto x);

proto proto_from_u32(uint32_t);
uint32_t proto_to_u32(proto);  // truncates

size_t proto_used(proto x);
size_t proto_alloced(proto x);

bool proto_zpos(proto x);
bool proto_is_zero(proto x);

void proto_swap(proto *x, proto *y);

// true on success is probably worse than an enum
bool proto_resize(proto *x, size_t digits);

bool proto_equal(proto x, proto y);

// Number of base 10 digits
size_t proto_count_base10(proto x);

// Read N [0-9] digits into a bit integer
proto proto_from_base10(const char *, size_t N);

// Write proto into out, returning how many bytes written
size_t proto_into_base10(proto, char *out, size_t N);

proto proto_abs(proto x);
proto proto_neg(proto x);
proto proto_incr(proto x);
proto proto_decr(proto x);

proto proto_add(proto x, proto y);
proto proto_sub(proto x, proto y);
proto proto_mul(proto x, proto y);
proto proto_div(proto x, proto y);
proto proto_rem(proto x, proto y);

proto proto_or(proto x, proto y);
proto proto_and(proto x, proto y);
proto proto_xor(proto x, proto y);

#endif
