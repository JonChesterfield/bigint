#ifndef TOMMATH_OVERRIDES_H_
#define TOMMATH_OVERRIDES_H_

/* leaves calls to MP_MALLOC, MP_FREE etc as external symbols */
#define MP_MALLOC(X) MP_MALLOC(X)

// Use the simple div for now
#define BN_MP_DIV_SMALL

// Do not want to change between mul algorithms at runtime
#define MP_FIXED_CUTOFFS

#endif
