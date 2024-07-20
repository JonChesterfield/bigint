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

typedef struct proto_ty * proto;

// Create zero with at least digits allocated space
proto proto_create(size_t digits);
bool proto_valid(proto x); // allocation succeeded
void proto_destroy(proto x);
proto proto_copy(proto x);

size_t proto_used(proto x);
size_t proto_alloced(proto x);

bool proto_zpos(proto x);
bool proto_neg(proto x);

void proto_swap(proto *x, proto *y);

// true on success is probably worse than an enum
bool proto_resize(proto *x, size_t digits);

bool proto_equal(proto x, proto y);

// Number of base 10 digits
size_t proto_count_base10(proto x);

// Read N [0-9] digits into a bit integer
proto proto_from_base10(const char *, size_t N);

// Write proto into out, returning how many bytes written
size_t proto_into_base10(proto, char* out, size_t N);


#endif
