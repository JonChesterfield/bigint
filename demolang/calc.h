#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
int calclib(const uint8_t *bytes, size_t N, bool verbose);

static inline int calclib_cstr(const char *str)
{
  return calclib((const unsigned char*)str,
                 __builtin_strlen(str),
                 false);
}

#endif
