#include "tommath_private.h"
/* init a new mp_int */
mp_err mp_init(mp_int *a)
{
  /* equivalent to the normal definition, swapping it out removes an allocation site */
  return mp_init_size(a, (size_t)MP_PREC);
}
