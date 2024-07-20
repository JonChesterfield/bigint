#ifndef TOMMATH_OVERRIDES_H_
#define TOMMATH_OVERRIDES_H_

/* leaves calls to MP_MALLOC, MP_FREE etc as external symbols */
#define MP_MALLOC(X) MP_MALLOC(X)

#endif
