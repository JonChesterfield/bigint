#ifndef BIGINT_TOMMATH_HPP_INCLUDED
#define BIGINT_TOMMATH_HPP_INCLUDED

#include <stddef.h>
#include <stdint.h>

// Derived mechanically from libtommath:
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */
#include "base_operations.hpp"

namespace bigint
{

template <typename IntType>
class tommath
{
  using ops = typename bigint::base_operations<IntType>;
public:
  using mp_int = typename ops::mp_int;
  using mp_digit = typename ops::mp_digit;
  using mp_word = typename ops::mp_word;
  using mp_count = typename ops::mp_count;

  typedef enum {
     MP_ZPOS = 0,   /* positive */
     MP_NEG = 1     /* negative */
  } mp_sign;
  typedef enum {
     MP_LT = -1,    /* less than */
     MP_EQ = 0,     /* equal */
     MP_GT = 1      /* greater than */
  } mp_ord;
  typedef enum {
     MP_NO = 0,
     MP_YES = 1
  } mp_bool;

  typedef enum {
     MP_OKAY  = 0,   /* no error */
     MP_ERR   = -1,  /* unknown error */
     MP_MEM   = -2,  /* out of mem */
     MP_VAL   = -3,  /* invalid input */
     // MP_ITER  = -4,  /* maximum iterations reached */
     // MP_BUF   = -5   /* buffer overflow, supplied buffer too small */
  } mp_err;

static mp_err mp_init_size(mp_int *a, mp_count size)
{
  bool r = ops::create(a, size);
  return r ? MP_OKAY : MP_ERR;
}
static mp_err mp_grow(mp_int *a, mp_count size)
{
  bool r = ops::grow(a, size);
  return r ? MP_OKAY : MP_ERR;
}

static void mp_clear(mp_int *a)
{
  ops::destroy(a);
}

static mp_count mp_get_alloc(const mp_int* a) { return ops::get_storage_count(a); }
static mp_count mp_get_used(const mp_int* a){ return ops::get_nonzero_count(a); }
static mp_sign mp_get_sign(const mp_int* a){ return ops::get_sign(a) ? MP_NEG : MP_ZPOS; }

// None of these set alloc
static void mp_set_used(mp_int* a, mp_count n) { ops::set_nonzero_count(a, n); }
static void mp_set_sign(mp_int* a, mp_sign s) { ops::set_sign(a, s == MP_NEG); }

static mp_digit mp_get_digit(const mp_int* a, mp_count n) { return ops::get_digit(a, n); }
static void mp_set_digit(mp_int* a, mp_count i, mp_digit d) { ops::set_digit(a, i, d); }

static mp_digit * mp_get_digit_iter(const mp_int* a) { return ops::get_digit_iter(a); }

static 
mp_count MP_MIN(mp_count x, mp_count y)
{
  return x < y ? x : y;
}

static 
mp_count MP_MAX(mp_count x, mp_count y)
{
  return x > y ? x : y;
}

static 
void MP_ZERO_DIGITS(mp_digit* zm_, mp_count zd_)
{
   while (zd_-- > 0) {
      *zm_++ = 0;
   }
}

static  __attribute__((unused))
mp_bool mp_iszero(const mp_int * a)
{
  return (mp_get_used(a) == 0) ? MP_YES : MP_NO;
}

static  __attribute__((unused))
mp_bool mp_isneg(const mp_int * a)
{
  return (mp_get_sign(a) != MP_ZPOS) ? MP_YES : MP_NO;
}


static 
bool MP_IS_ZERO(const mp_int *a)
{
  return (mp_get_used(a) == 0);
}

public:


#define MP_32BIT
#define MP_DIGIT_BIT 28
#define MP_MASK          ((((mp_digit)1)<<((mp_digit)MP_DIGIT_BIT))-((mp_digit)1))
#define MP_DIGIT_MAX     MP_MASK

#define MP_SIZEOF_BITS(type)    (8 * sizeof(type))
#define MP_MAXFAST              (int)(1uL << (MP_SIZEOF_BITS(mp_word) - (2u * (size_t)MP_DIGIT_BIT)))

#define MP_STRINGIZE(x)  MP__STRINGIZE(x)
#define MP__STRINGIZE(x) ""#x""
#define MP_HAS(x)        (sizeof(MP_STRINGIZE(BN_##x##_C)) == 1u)
#define MP_IS_2EXPT(x) (((x) != 0u) && (((x) & ((x) - 1u)) == 0u))



#define MP_WARRAY (int)(1uLL << (((8 * sizeof(mp_word)) - (2 * MP_DIGIT_BIT)) + 1))

#define MP_DEFAULT_KARATSUBA_MUL_CUTOFF 80
#define MP_DEFAULT_KARATSUBA_SQR_CUTOFF 120
#define MP_DEFAULT_TOOM_MUL_CUTOFF      350
#define MP_DEFAULT_TOOM_SQR_CUTOFF      400
#  define MP_KARATSUBA_MUL_CUTOFF MP_DEFAULT_KARATSUBA_MUL_CUTOFF
#  define MP_KARATSUBA_SQR_CUTOFF MP_DEFAULT_KARATSUBA_SQR_CUTOFF
#  define MP_TOOM_MUL_CUTOFF      MP_DEFAULT_TOOM_MUL_CUTOFF
#  define MP_TOOM_SQR_CUTOFF      MP_DEFAULT_TOOM_SQR_CUTOFF

#define MP_GET_MAG(name, type)                                                         \
    type name(const mp_int* a)                                                         \
    {                                                                                  \
        unsigned i = MP_MIN((unsigned)a->used, (unsigned)((MP_SIZEOF_BITS(type) + MP_DIGIT_BIT - 1) / MP_DIGIT_BIT)); \
        type res = 0u;                                                                 \
        while (i --> 0u) {                                                             \
            res <<= ((MP_SIZEOF_BITS(type) <= MP_DIGIT_BIT) ? 0 : MP_DIGIT_BIT);       \
            res |= (type)a->dp[i];                                                     \
            if (MP_SIZEOF_BITS(type) <= MP_DIGIT_BIT) { break; }                       \
        }                                                                              \
        return res;                                                                    \
    }

#define MP_GET_SIGNED(name, mag, type, utype)                 \
    type name(const mp_int* a)                                \
    {                                                         \
        utype res = mag(a);                                   \
        return (a->sign == MP_NEG) ? (type)-res : (type)res;  \
    }


static
  mp_err mp_abs(const mp_int *a, mp_int *b)
  {
     mp_err     err;
  
     /* copy a to b */
     if (a != b) {
        if ((err = mp_copy(a, b)) != MP_OKAY) {
           return err;
        }
     }
  
     /* force the sign of b to positive */
     mp_set_sign(b, MP_ZPOS);
  
     return MP_OKAY;
  }
static
  mp_err mp_add(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_sign sa, sb;
     mp_err err;
  
     /* get sign of both inputs */
     sa = mp_get_sign(a);
     sb = mp_get_sign(b);
  
     /* handle two cases, not four */
     if (sa == sb) {
        /* both positive or both negative */
        /* add their magnitudes, copy the sign */
        mp_set_sign(c, sa);
        err = s_mp_add(a, b, c);
     } else {
        /* one positive, the other negative */
        /* subtract the one with the greater magnitude from */
        /* the one of the lesser magnitude.  The result gets */
        /* the sign of the one with the greater magnitude. */
        if (mp_cmp_mag(a, b) == MP_LT) {
           mp_set_sign(c, sb);
           err = s_mp_sub(b, a, c);
        } else {
           mp_set_sign(c, sa);
           err = s_mp_sub(a, b, c);
        }
     }
     return err;
  }
  
static
  mp_err mp_add_d(const mp_int *a, mp_digit b, mp_int *c)
  {
     mp_err     err;
     int ix, oldused;
     mp_digit *tmpa, *tmpc;
  
     /* grow c as required */
     if (mp_get_alloc(c) < (mp_get_used(a) + 1)) {
        if ((err = mp_grow(c, mp_get_used(a) + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* if a is negative and |a| >= b, call c = |a| - b */
     if ((mp_get_sign(a) == MP_NEG) && ((mp_get_used(a) > 1) || (mp_get_digit(a, 0) >= b))) {
        mp_int a_ = *a;
        /* temporarily fix sign of a */
        mp_set_sign(&a_, MP_ZPOS);
  
        /* c = |a| - b */
        err = mp_sub_d(&a_, b, c);
  
        /* fix sign  */
        mp_set_sign(c, MP_NEG);
  
        /* clamp */
        mp_clamp(c);
  
        return err;
     }
  
     /* old number of used digits in c */
     oldused = mp_get_used(c);
  
     /* source alias */
     tmpa    = mp_get_digit_iter(a);
  
     /* destination alias */
     tmpc    = mp_get_digit_iter(c);
  
     /* if a is positive */
     if (mp_get_sign(a) == MP_ZPOS) {
        /* add digits, mu is carry */
        mp_digit mu = b;
        for (ix = 0; ix < mp_get_used(a); ix++) {
           *tmpc   = *tmpa++ + mu;
           mu      = *tmpc >> MP_DIGIT_BIT;
           *tmpc++ &= MP_MASK;
        }
        /* set final carry */
        ix++;
        *tmpc++  = mu;
  
        /* setup size */
        mp_set_used(c, mp_get_used(a) + 1);
     } else {
        /* a was negative and |a| < b */
        mp_set_used(c, 1);
  
        /* the result is a single digit */
        if (mp_get_used(a) == 1) {
           *tmpc++  =  b - mp_get_digit(a, 0);
        } else {
           *tmpc++  =  b;
        }
  
        /* setup count so the clearing of oldused
         * can fall through correctly
         */
        ix       = 1;
     }
  
     /* sign always positive */
     mp_set_sign(c, MP_ZPOS);
  
     /* now zero to oldused */
     MP_ZERO_DIGITS(tmpc, oldused - ix);
     mp_clamp(c);
  
     return MP_OKAY;
  }
  
static
  mp_err mp_and(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int used = MP_MAX(mp_get_used(a), mp_get_used(b)) + 1, i;
     mp_err err;
     mp_digit ac = 1, bc = 1, cc = 1;
     mp_sign csign = ((mp_get_sign(a) == MP_NEG) && (mp_get_sign(b) == MP_NEG)) ? MP_NEG : MP_ZPOS;
  
     if (mp_get_alloc(c) < used) {
        if ((err = mp_grow(c, used)) != MP_OKAY) {
           return err;
        }
     }
  
     for (i = 0; i < used; i++) {
        mp_digit x, y;
  
        /* convert to two complement if negative */
        if (mp_get_sign(a) == MP_NEG) {
           ac += (i >= mp_get_used(a)) ? MP_MASK : (~mp_get_digit(a, i) & MP_MASK);
           x = ac & MP_MASK;
           ac >>= MP_DIGIT_BIT;
        } else {
           x = (i >= mp_get_used(a)) ? 0uL : mp_get_digit(a, i);
        }
  
        /* convert to two complement if negative */
        if (mp_get_sign(b) == MP_NEG) {
           bc += (i >= mp_get_used(b)) ? MP_MASK : (~mp_get_digit(b, i) & MP_MASK);
           y = bc & MP_MASK;
           bc >>= MP_DIGIT_BIT;
        } else {
           y = (i >= mp_get_used(b)) ? 0uL : mp_get_digit(b, i);
        }
  
        mp_set_digit(c, i, x & y);
  
        /* convert to to sign-magnitude if negative */
        if (csign == MP_NEG) {
           cc += ~mp_get_digit(c, i) & MP_MASK;
           mp_set_digit(c, i, cc & MP_MASK);
           cc >>= MP_DIGIT_BIT;
        }
     }
  
     mp_set_used(c, used);
     mp_set_sign(c, csign);
     mp_clamp(c);
     return MP_OKAY;
  }
static
  mp_err mp_init(mp_int *a)
  {
    /* special cased */
    /* equivalent to the normal definition, swapping it out removes an allocation site */
    enum {MP_PREC = 8, };
    return mp_init_size(a, (size_t)MP_PREC);
  }
static
  mp_err mp_init_multi(mp_int *mp[])
  {
     mp_err err = MP_OKAY;      /* Assume ok until proven otherwise */
     int n = 0;                 /* Number of ok inits */
     mp_int *cur_arg = mp[0];
  
     while (cur_arg != NULL) {
        if (mp_init(cur_arg) != MP_OKAY) {
           /* Oops - error! Back-track and mp_clear what we already
              succeeded in init-ing, then return error.
           */
  
           for (int i = 0; i < n; i++) {
              mp_clear(mp[i]);
           }
  
           err = MP_MEM;
           break;
        }
        n++;
        cur_arg = mp[n];
     }
  
     return err;                /* Assumed ok, if error flagged above. */
  }
static
  mp_err mp_init_set(mp_int *a, mp_digit b)
  {
     mp_err err;
     if ((err = mp_init(a)) != MP_OKAY) {
        return err;
     }
     mp_set(a, b);
     return err;
  }
static
  mp_err mp_init_copy(mp_int *a, const mp_int *b)
  {
     mp_err     err;
  
     if ((err = mp_init_size(a, mp_get_used(b))) != MP_OKAY) {
        return err;
     }
  
     if ((err = mp_copy(b, a)) != MP_OKAY) {
        mp_clear(a);
     }
  
     return err;
  }
static
  void mp_clamp(mp_int *a)
  {
     /* decrease used while the most significant digit is
      * zero.
      */
      int used = mp_get_used(a);
      while ((used > 0) && (mp_get_digit(a, used - 1) == 0u))
      {
        --used;
      }
      mp_set_used(a, used);
  
     /* reset the sign flag if used == 0 */
     if (mp_get_used(a) == 0) {
        mp_set_sign(a, MP_ZPOS);
     }
  }
static
  mp_ord mp_cmp(const mp_int *a, const mp_int *b)
  {
     /* compare based on sign */
     if (mp_get_sign(a) != mp_get_sign(b)) {
        if (mp_get_sign(a) == MP_NEG) {
           return MP_LT;
        } else {
           return MP_GT;
        }
     }
  
     /* compare digits */
     if (mp_get_sign(a) == MP_NEG) {
        /* if negative compare opposite direction */
        return mp_cmp_mag(b, a);
     } else {
        return mp_cmp_mag(a, b);
     }
  }
static
  mp_ord mp_cmp_d(const mp_int *a, mp_digit b)
  {
     /* compare based on sign */
     if (mp_get_sign(a) == MP_NEG) {
        return MP_LT;
     }
  
     /* compare based on magnitude */
     if (mp_get_used(a) > 1) {
        return MP_GT;
     }
  
     /* compare the only digit of a to b */
     if (mp_get_digit(a, 0) > b) {
        return MP_GT;
     } else if (mp_get_digit(a, 0) < b) {
        return MP_LT;
     } else {
        return MP_EQ;
     }
  }
static
  mp_ord mp_cmp_mag(const mp_int *a, const mp_int *b)
  {
     int     n;
     const mp_digit *tmpa, *tmpb;
  
     /* compare based on # of non-zero digits */
     if (mp_get_used(a) > mp_get_used(b)) {
        return MP_GT;
     }
  
     if (mp_get_used(a) < mp_get_used(b)) {
        return MP_LT;
     }
  
     /* alias for a */
     tmpa = mp_get_digit_iter(a) + (mp_get_used(a) - 1);
  
     /* alias for b */
     tmpb = mp_get_digit_iter(b) + (mp_get_used(a) - 1);
  
     /* compare based on digits  */
     for (n = 0; n < mp_get_used(a); ++n, --tmpa, --tmpb) {
        if (*tmpa > *tmpb) {
           return MP_GT;
        }
  
        if (*tmpa < *tmpb) {
           return MP_LT;
        }
     }
     return MP_EQ;
  }
static
  mp_err mp_complement(const mp_int *a, mp_int *b)
  {
     mp_err err = mp_neg(a, b);
     return (err == MP_OKAY) ? mp_sub_d(b, 1uL, b) : err;
  }
static
  mp_err mp_copy(const mp_int *a, mp_int *b)
  {
     int n;
     mp_digit *tmpa, *tmpb;
     mp_err err;
  
     /* if dst == src do nothing */
     if (a == b) {
        return MP_OKAY;
     }
  
     /* grow dest */
     if (mp_get_alloc(b) < mp_get_used(a)) {
        if ((err = mp_grow(b, mp_get_used(a))) != MP_OKAY) {
           return err;
        }
     }
  
     /* zero b and copy the parameters over */
     /* pointer aliases */
  
     /* source */
     tmpa = mp_get_digit_iter(a);
  
     /* destination */
     tmpb = mp_get_digit_iter(b);
  
     /* copy all the digits */
     for (n = 0; n < mp_get_used(a); n++) {
        *tmpb++ = *tmpa++;
     }
  
     /* clear high digits */
     MP_ZERO_DIGITS(tmpb, mp_get_used(b) - n);
  
     /* copy used count and sign */
     mp_set_used(b, mp_get_used(a));
     mp_set_sign(b, mp_get_sign(a));
     return MP_OKAY;
  }
static
  int mp_count_bits(const mp_int *a)
  {
     int     r;
     mp_digit q;
  
     /* shortcut */
     if (MP_IS_ZERO(a)) {
        return 0;
     }
  
     /* get number of digits and add that */
     r = (mp_get_used(a) - 1) * MP_DIGIT_BIT;
  
     /* take the last digit and count the bits in it */
     q = mp_get_digit(a, mp_get_used(a) - 1);
     while (q > 0u) {
        ++r;
        q >>= 1u;
     }
     return r;
  }
static
  mp_err mp_decr(mp_int *a)
  {
     if (MP_IS_ZERO(a)) {
        mp_set(a,1uL);
        mp_set_sign(a, MP_NEG);
        return MP_OKAY;
     } else if (mp_get_sign(a) == MP_NEG) {
        mp_err err;
        mp_set_sign(a, MP_ZPOS);
        if ((err = mp_incr(a)) != MP_OKAY) {
           return err;
        }
        /* There is no -0 in LTM */
        if (!MP_IS_ZERO(a)) {
           mp_set_sign(a, MP_NEG);
        }
        return MP_OKAY;
     } else if (mp_get_digit(a, 0) > 1uL) {
        mp_set_digit(a, 0, mp_get_digit(a, 0) - 1);
        if (mp_get_digit(a, 0) == 0u) {
           mp_zero(a);
        }
        return MP_OKAY;
     } else {
        return mp_sub_d(a, 1uL,a);
     }
  }
static
  mp_err mp_div(const mp_int *a, const mp_int *b, mp_int *c, mp_int *d)
  {
     mp_int ta, tb, tq, q;
     int     n;
     mp_sign n1, n2;
     mp_err err;
  
     /* is divisor zero ? */
     if (MP_IS_ZERO(b)) {
        return MP_VAL;
     }
  
     /* if a < b then q=0, r = a */
     if (mp_cmp_mag(a, b) == MP_LT) {
        if (d != NULL) {
           err = mp_copy(a, d);
        } else {
           err = MP_OKAY;
        }
        if (c != NULL) {
           mp_zero(c);
        }
        return err;
     }
  
     /* init our temps */
     if ((err = mp_init_multi((mp_int*[]){&ta, &tb, &tq, &q, NULL})) != MP_OKAY) {
        return err;
     }
  
     mp_set(&tq, 1uL);
     n = mp_count_bits(a) - mp_count_bits(b);
     if ((err = mp_abs(a, &ta)) != MP_OKAY)                         goto LBL_ERR;
     if ((err = mp_abs(b, &tb)) != MP_OKAY)                         goto LBL_ERR;
     if ((err = mp_mul_2d(&tb, n, &tb)) != MP_OKAY)                 goto LBL_ERR;
     if ((err = mp_mul_2d(&tq, n, &tq)) != MP_OKAY)                 goto LBL_ERR;
  
     while (n-- >= 0) {
        if (mp_cmp(&tb, &ta) != MP_GT) {
           if ((err = mp_sub(&ta, &tb, &ta)) != MP_OKAY)            goto LBL_ERR;
           if ((err = mp_add(&q, &tq, &q)) != MP_OKAY)              goto LBL_ERR;
        }
        if ((err = mp_div_2d(&tb, 1, &tb, NULL)) != MP_OKAY)        goto LBL_ERR;
        if ((err = mp_div_2d(&tq, 1, &tq, NULL)) != MP_OKAY)        goto LBL_ERR;
     }
  
     /* now q == quotient and ta == remainder */
     n1  = mp_get_sign(a);
     n2 = (mp_get_sign(a) == mp_get_sign(b)) ? MP_ZPOS : MP_NEG;
     if (c != NULL) {
        mp_exch(c, &q);
        mp_set_sign(c, MP_IS_ZERO(c) ? MP_ZPOS : n2);
     }
     if (d != NULL) {
        mp_exch(d, &ta);
        mp_set_sign(d, MP_IS_ZERO(d) ? MP_ZPOS : n1);
     }
  LBL_ERR:
     mp_clear(&ta);
     mp_clear(&tb);
     mp_clear(&tq);
     mp_clear(&q);
     return err;
  }
  
static
  mp_err mp_div_no_rem(const mp_int *a, const mp_int *b, mp_int *c)
  {
    return mp_div(a, b, c, NULL);
  }
static
  mp_err mp_div_only_rem(const mp_int *a, const mp_int *b, mp_int *c)
  {
    return mp_div(a, b, NULL, c);
  }
static
  mp_err mp_div_2(const mp_int *a, mp_int *b)
  {
     int     x, oldused;
     mp_digit r, rr, *tmpa, *tmpb;
     mp_err err;
  
     /* copy */
     if (mp_get_alloc(b) < mp_get_used(a)) {
        if ((err = mp_grow(b, mp_get_used(a))) != MP_OKAY) {
           return err;
        }
     }
  
     oldused = mp_get_used(b);
     mp_set_used(b, mp_get_used(a));
  
     /* source alias */
     tmpa = mp_get_digit_iter(a) + mp_get_used(b) - 1;
  
     /* dest alias */
     tmpb = mp_get_digit_iter(b) + mp_get_used(b) - 1;
  
     /* carry */
     r = 0;
     for (x = mp_get_used(b) - 1; x >= 0; x--) {
        /* get the carry for the next iteration */
        rr = *tmpa & 1u;
  
        /* shift the current digit, add in carry and store */
        *tmpb-- = (*tmpa-- >> 1) | (r << (MP_DIGIT_BIT - 1));
  
        /* forward carry to next iteration */
        r = rr;
     }
  
     /* zero excess digits */
     MP_ZERO_DIGITS(mp_get_digit_iter(b) + mp_get_used(b), oldused - mp_get_used(b));
  
     mp_set_sign(b, mp_get_sign(a));
     mp_clamp(b);
     return MP_OKAY;
  }
static
  mp_err mp_div_2d(const mp_int *a, int b, mp_int *c, mp_int *d)
  {
     mp_digit D, r, rr;
     int     x;
     mp_err err;
  
     /* if the shift count is <= 0 then we do no work */
     if (b <= 0) {
        err = mp_copy(a, c);
        if (d != NULL) {
           mp_zero(d);
        }
        return err;
     }
  
     /* copy */
     if ((err = mp_copy(a, c)) != MP_OKAY) {
        return err;
     }
     /* 'a' should not be used after here - it might be the same as d */
  
     /* get the remainder */
     if (d != NULL) {
        if ((err = mp_mod_2d(a, b, d)) != MP_OKAY) {
           return err;
        }
     }
  
     /* shift by as many digits in the bit count */
     if (b >= MP_DIGIT_BIT) {
        mp_rshd(c, b / MP_DIGIT_BIT);
     }
  
     /* shift any bit count < MP_DIGIT_BIT */
     D = (mp_digit)(b % MP_DIGIT_BIT);
     if (D != 0u) {
        mp_digit *tmpc, mask, shift;
  
        /* mask */
        mask = ((mp_digit)1 << D) - 1uL;
  
        /* shift for lsb */
        shift = (mp_digit)MP_DIGIT_BIT - D;
  
        /* alias */
        tmpc = mp_get_digit_iter(c) + (mp_get_used(c) - 1);
  
        /* carry */
        r = 0;
        for (x = mp_get_used(c) - 1; x >= 0; x--) {
           /* get the lower  bits of this word in a temp */
           rr = *tmpc & mask;
  
           /* shift the current word and mix in the carry bits from the previous word */
           *tmpc = (*tmpc >> D) | (r << shift);
           --tmpc;
  
           /* set the carry to the carry bits of the current word found above */
           r = rr;
        }
     }
     mp_clamp(c);
     return MP_OKAY;
  }
static
  mp_err mp_div_d(const mp_int *a, mp_digit b, mp_int *c, mp_digit *d)
  {
     mp_int  q;
     mp_word w;
     mp_digit t;
     mp_err err;
     int ix;
  
     /* cannot divide by zero */
     if (b == 0u) {
        return MP_VAL;
     }
  
     /* quick outs */
     if ((b == 1u) || MP_IS_ZERO(a)) {
        if (d != NULL) {
           *d = 0;
        }
        if (c != NULL) {
           return mp_copy(a, c);
        }
        return MP_OKAY;
     }
  
     /* power of two ? */
     if ((b & (b - 1u)) == 0u) {
        ix = 1;
        while ((ix < MP_DIGIT_BIT) && (b != (((mp_digit)1)<<ix))) {
           ix++;
        }
        if (d != NULL) {
           *d = mp_get_digit(a, 0) & (((mp_digit)1<<(mp_digit)ix) - 1uL);
        }
        if (c != NULL) {
           return mp_div_2d(a, ix, c, NULL);
        }
        return MP_OKAY;
     }
  
     /* three? */
     if (MP_HAS(S_MP_DIV_3) && (b == 3u)) {
        return s_mp_div_3(a, c, d);
     }
  
     /* no easy answer [c'est la vie].  Just division */
     if ((err = mp_init_size(&q, mp_get_used(a))) != MP_OKAY) {
        return err;
     }
  
     mp_set_used(&q, mp_get_used(a));
     mp_set_sign(&q, mp_get_sign(a));
     w = 0;
     for (ix = mp_get_used(a) - 1; ix >= 0; ix--) {
        w = (w << (mp_word)MP_DIGIT_BIT) | (mp_word)mp_get_digit(a, ix);
  
        if (w >= b) {
           t = (mp_digit)(w / b);
           w -= (mp_word)t * (mp_word)b;
        } else {
           t = 0;
        }
        mp_set_digit(&q, ix, t);
     }
  
     if (d != NULL) {
        *d = (mp_digit)w;
     }
  
     if (c != NULL) {
        mp_clamp(&q);
        mp_exch(&q, c);
     }
     mp_clear(&q);
  
     return err;
  }
  
static
  void mp_exch(mp_int *a, mp_int *b)
  {
     mp_int  t;
  
     t  = *a;
     *a = *b;
     *b = t;
  }
static
  mp_err mp_from_decimal(const char * start, const char * end, mp_int *c)
  {
    size_t width = end - start;
    if (width == 0) return MP_VAL;
  
    bool neg = start[0] == '-';
    if (neg)
    {
      if (width == 1)
      {
          return MP_VAL;
      }
      start++;
      width--;
    }
  
    for (size_t i = 0; i < width; i++)
    {
      char b = (start[i] - '0');
      if (b < 0 || b > 9)
      {
        return MP_VAL;
      }
  
      if (mp_mul_d(c, 10, c) != MP_OKAY)
      {
        mp_clear(c);
        return MP_MEM;
      }
  
      if (mp_add_d(c, b, c) != MP_OKAY)
      {
        mp_clear(c);
        return MP_MEM;
      }
    }
  
    if (neg)
    {
      (void)mp_neg(c, c); // Is zero-fail when arguments alias
    }
  
    return MP_OKAY;
  }
  
static
  double mp_get_double(const mp_int *a)
  {
     int i;
     double d = 0.0, fac = 1.0;
     for (i = 0; i < MP_DIGIT_BIT; ++i) {
        fac *= 2.0;
     }
     for (i = mp_get_used(a); i --> 0;) {
        d = (d * fac) + (double)mp_get_digit(a, i);
     }
     return (mp_get_sign(a) == MP_NEG) ? -d : d;
  }
static
  mp_err mp_incr(mp_int *a)
  {
     if (MP_IS_ZERO(a)) {
        mp_set(a,1uL);
        return MP_OKAY;
     } else if (mp_get_sign(a) == MP_NEG) {
        mp_err err;
        mp_set_sign(a, MP_ZPOS);
        if ((err = mp_decr(a)) != MP_OKAY) {
           return err;
        }
        /* There is no -0 in LTM */
        if (!MP_IS_ZERO(a)) {
           mp_set_sign(a, MP_NEG);
        }
        return MP_OKAY;
     } else if (mp_get_digit(a, 0) < MP_DIGIT_MAX) {
        mp_set_digit(a, 0, mp_get_digit(a, 0) + 1);
        return MP_OKAY;
     } else {
        return mp_add_d(a, 1uL,a);
     }
  }
static
  mp_err mp_add_one(const mp_int *a, mp_int *b)
  {
    mp_err r = mp_copy(a, b);
    if (r != MP_OKAY)
    {
      return r;
    }
  
    r = mp_incr(b);
    if (r != MP_OKAY)
    {
      mp_clear(b);
    }
    return r;
  }
static
  mp_err mp_sub_one(const mp_int *a, mp_int *b)
  {
    mp_err r = mp_copy(a, b);
    if (r != MP_OKAY)
    {
      return r;
    }
  
    r = mp_decr(b);
    if (r != MP_OKAY)
    {
      mp_clear(b);
    }
    return r;
  }
static
  mp_err mp_lsh(const mp_int *a, const mp_int *b, mp_int *c)
  {
    if (mp_isneg(b)) {
      // Choices...
      return mp_copy(a, c);
    }
  
    // TODO, this is clumsy
  
    mp_int tmp;
    if (mp_init_size(&tmp, 2) != MP_OKAY) return MP_MEM; 
    mp_set_i32(&tmp, INT32_MAX);
  
    if (mp_cmp(b, &tmp) == MP_GT)
    {
      // Shift by > int not presently available
      mp_clear(&tmp);
      return MP_VAL;
    }
  
    int32_t i = mp_get_i32(b);
  
    if (mp_copy(a, c) != MP_OKAY) return MP_MEM; 
    mp_err r = mp_lshd(c, i);
    if (r != MP_OKAY)
    {
      mp_clear(c);
    }
    return r;
  }
static
  mp_err mp_rsh(const mp_int *a, const mp_int *b, mp_int *c)
  {
    return MP_VAL; // until lsh is less ugly
  }
static
  mp_err mp_lshd(mp_int *a, int b)
  {
     int x;
     mp_err err;
     mp_digit *top, *bottom;
  
     /* if its less than zero return */
     if (b <= 0) {
        return MP_OKAY;
     }
     /* no need to shift 0 around */
     if (MP_IS_ZERO(a)) {
        return MP_OKAY;
     }
  
     /* grow to fit the new digits */
     if (mp_get_alloc(a) < (mp_get_used(a) + b)) {
        if ((err = mp_grow(a, mp_get_used(a) + b)) != MP_OKAY) {
           return err;
        }
     }
  
     /* increment the used by the shift amount then copy upwards */
     mp_set_used(a, mp_get_used(a)  + b);
  
     /* top */
     top = mp_get_digit_iter(a) + mp_get_used(a) - 1;
  
     /* base */
     bottom = (mp_get_digit_iter(a) + mp_get_used(a) - 1) - b;
  
     /* much like mp_rshd this is implemented using a sliding window
      * except the window goes the otherway around.  Copying from
      * the bottom to the top.  see bn_mp_rshd.c for more info.
      */
     for (x = mp_get_used(a) - 1; x >= b; x--) {
        *top-- = *bottom--;
     }
  
     /* zero the lower digits */
     MP_ZERO_DIGITS(mp_get_digit_iter(a), b);
  
     return MP_OKAY;
  }
static
  mp_err mp_mod(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_int  t;
     mp_err  err;
  
     if ((err = mp_init_size(&t, mp_get_used(b))) != MP_OKAY) {
        return err;
     }
  
     if ((err = mp_div(a, b, NULL, &t)) != MP_OKAY) {
        goto LBL_ERR;
     }
  
     if (MP_IS_ZERO(&t) || (mp_get_sign(&t) == mp_get_sign(b))) {
        err = MP_OKAY;
        mp_exch(&t, c);
     } else {
        err = mp_add(b, &t, c);
     }
  
  LBL_ERR:
     mp_clear(&t);
     return err;
  }
static
  mp_err mp_mod_2d(const mp_int *a, int b, mp_int *c)
  {
     int x;
     mp_err err;
  
     /* if b is <= 0 then zero the int */
     if (b <= 0) {
        mp_zero(c);
        return MP_OKAY;
     }
  
     /* if the modulus is larger than the value than return */
     if (b >= (mp_get_used(a) * MP_DIGIT_BIT)) {
        return mp_copy(a, c);
     }
  
     /* copy */
     if ((err = mp_copy(a, c)) != MP_OKAY) {
        return err;
     }
  
     /* zero digits above the last digit of the modulus */
     x = (b / MP_DIGIT_BIT) + (((b % MP_DIGIT_BIT) == 0) ? 0 : 1);
     MP_ZERO_DIGITS(mp_get_digit_iter(c) + x, mp_get_used(c) - x);
  
     /* clear the digit that is not completely outside/inside the modulus */
     mp_digit tmp = (mp_digit)1 << (mp_digit)(b % MP_DIGIT_BIT);
     mp_set_digit(c, b / MP_DIGIT_BIT, mp_get_digit(c, b / MP_DIGIT_BIT) & tmp - (mp_digit)1);
     mp_clamp(c);
     return MP_OKAY;
  }
static
  mp_err mp_mod_d(const mp_int *a, mp_digit b, mp_digit *c)
  {
     return mp_div_d(a, b, NULL, c);
  }
static
  mp_err mp_mul(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_err err;
     int min_len = MP_MIN(mp_get_used(a), mp_get_used(b)),
         max_len = MP_MAX(mp_get_used(a), mp_get_used(b)),
         digs = mp_get_used(a) + mp_get_used(b) + 1;
     mp_sign neg = (mp_get_sign(a) == mp_get_sign(b)) ? MP_ZPOS : MP_NEG;
  
     if (MP_HAS(S_MP_BALANCE_MUL) &&
         /* Check sizes. The smaller one needs to be larger than the Karatsuba cut-off.
          * The bigger one needs to be at least about one MP_KARATSUBA_MUL_CUTOFF bigger
          * to make some sense, but it depends on architecture, OS, position of the
          * stars... so YMMV.
          * Using it to cut the input into slices small enough for fast_s_mp_mul_digs
          * was actually slower on the author's machine, but YMMV.
          */
         (min_len >= MP_KARATSUBA_MUL_CUTOFF) &&
         ((max_len / 2) >= MP_KARATSUBA_MUL_CUTOFF) &&
         /* Not much effect was observed below a ratio of 1:2, but again: YMMV. */
         (max_len >= (2 * min_len))) {
        err = s_mp_balance_mul(a,b,c);
     }
  #if 0
      else if (MP_HAS(S_MP_TOOM_MUL) &&
                (min_len >= MP_TOOM_MUL_CUTOFF)) {
        err = s_mp_toom_mul(a, b, c);
      }
  #endif
  #if 0
      else if (MP_HAS(S_MP_KARATSUBA_MUL) &&
                (min_len >= MP_KARATSUBA_MUL_CUTOFF)) {
        err = s_mp_karatsuba_mul(a, b, c);
      }
  #endif
      else if (MP_HAS(S_MP_MUL_DIGS_FAST) &&
  
                /* can we use the fast multiplier?
                 *
                 * The fast multiplier can be used if the output will
                 * have less than MP_WARRAY digits and the number of
                 * digits won't affect carry propagation
                 */
                (digs < MP_WARRAY) &&
                (min_len <= MP_MAXFAST)) {
        err = s_mp_mul_digs_fast(a, b, c, digs);
     } else if (MP_HAS(S_MP_MUL_DIGS)) {
        err = s_mp_mul_digs(a, b, c, digs);
     } else {
        err = MP_VAL;
     }
     mp_set_sign(c, (mp_get_used(c) > 0) ? neg : MP_ZPOS);
     return err;
  }
static
  mp_err mp_mul_2(const mp_int *a, mp_int *b)
  {
     int     x, oldused;
     mp_err err;
  
     /* grow to accomodate result */
     if (mp_get_alloc(b) < (mp_get_used(a) + 1)) {
        if ((err = mp_grow(b, mp_get_used(a) + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     oldused = mp_get_used(b);
     mp_set_used(b, mp_get_used(a));
  
     {
        mp_digit r, rr, *tmpa, *tmpb;
  
        /* alias for source */
        tmpa = mp_get_digit_iter(a);
  
        /* alias for dest */
        tmpb = mp_get_digit_iter(b);
  
        /* carry */
        r = 0;
        for (x = 0; x < mp_get_used(a); x++) {
  
           /* get what will be the *next* carry bit from the
            * MSB of the current digit
            */
           rr = *tmpa >> (mp_digit)(MP_DIGIT_BIT - 1);
  
           /* now shift up this digit, add in the carry [from the previous] */
           *tmpb++ = ((*tmpa++ << 1uL) | r) & MP_MASK;
  
           /* copy the carry that would be from the source
            * digit into the next iteration
            */
           r = rr;
        }
  
        /* new leading digit? */
        if (r != 0u) {
           /* add a MSB which is always 1 at this point */
           *tmpb = 1;
           mp_set_used(b, mp_get_used(b) + 1);
        }
  
        /* now zero any excess digits on the destination
         * that we didn't write to
         */
        MP_ZERO_DIGITS(mp_get_digit_iter(b) + mp_get_used(b), oldused - mp_get_used(b));
     }
     mp_set_sign(b, mp_get_sign(a));
     return MP_OKAY;
  }
static
  mp_err mp_mul_2d(const mp_int *a, int b, mp_int *c)
  {
     mp_digit d;
     mp_err   err;
  
     if (b < 0) {
        return MP_VAL;
     }
  
     /* copy */
     if (a != c) {
        if ((err = mp_copy(a, c)) != MP_OKAY) {
           return err;
        }
     }
  
     if (mp_get_alloc(c) < (mp_get_used(c) + (b / MP_DIGIT_BIT) + 1)) {
        if ((err = mp_grow(c, mp_get_used(c) + (b / MP_DIGIT_BIT) + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* shift by as many digits in the bit count */
     if (b >= MP_DIGIT_BIT) {
        if ((err = mp_lshd(c, b / MP_DIGIT_BIT)) != MP_OKAY) {
           return err;
        }
     }
  
     /* shift any bit count < MP_DIGIT_BIT */
     d = (mp_digit)(b % MP_DIGIT_BIT);
     if (d != 0u) {
        mp_digit *tmpc, shift, mask, r, rr;
        int x;
  
        /* bitmask for carries */
        mask = ((mp_digit)1 << d) - (mp_digit)1;
  
        /* shift for msbs */
        shift = (mp_digit)MP_DIGIT_BIT - d;
  
        /* alias */
        tmpc = mp_get_digit_iter(c);
  
        /* carry */
        r    = 0;
        for (x = 0; x < mp_get_used(c); x++) {
           /* get the higher bits of the current word */
           rr = (*tmpc >> shift) & mask;
  
           /* shift the current word and OR in the carry */
           *tmpc = ((*tmpc << d) | r) & MP_MASK;
           ++tmpc;
  
           /* set the carry to the carry bits of the current word */
           r = rr;
        }
  
        /* set final carry */
        if (r != 0u) {
          int idx = mp_get_used(c);
          mp_set_digit(c, idx, r);
          mp_set_used(c, mp_get_used(c) + 1);
        }
     }
     mp_clamp(c);
     return MP_OKAY;
  }
static
  mp_err mp_mul_d(const mp_int *a, mp_digit b, mp_int *c)
  {
     mp_digit u, *tmpa, *tmpc;
     mp_word  r;
     mp_err   err;
     int      ix, olduse;
  
     /* make sure c is big enough to hold a*b */
     if (mp_get_alloc(c) < (mp_get_used(a) + 1)) {
        if ((err = mp_grow(c, mp_get_used(a) + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* get the original destinations used count */
     olduse = mp_get_used(c);
  
     /* set the sign */
     mp_set_sign(c, mp_get_sign(a));
  
     /* alias for mp_get_digit_iter(a) [source] */
     tmpa = mp_get_digit_iter(a);
  
     /* alias for mp_get_digit_iter(c) [dest] */
     tmpc = mp_get_digit_iter(c);
  
     /* zero carry */
     u = 0;
  
     /* compute columns */
     for (ix = 0; ix < mp_get_used(a); ix++) {
        /* compute product and carry sum for this term */
        r       = (mp_word)u + ((mp_word)*tmpa++ * (mp_word)b);
  
        /* mask off higher bits to get a single digit */
        *tmpc++ = (mp_digit)(r & (mp_word)MP_MASK);
  
        /* send carry into next iteration */
        u       = (mp_digit)(r >> (mp_word)MP_DIGIT_BIT);
     }
  
     /* store final carry [if any] and increment ix offset  */
     *tmpc++ = u;
     ++ix;
  
     /* now zero digits above the top */
     MP_ZERO_DIGITS(tmpc, olduse - ix);
  
     /* set used count */
     mp_set_used(c, mp_get_used(a) + 1);
     mp_clamp(c);
  
     return MP_OKAY;
  }
static
  mp_err mp_neg(const mp_int *a, mp_int *b)
  {
     mp_err err;
     if (a != b) {
        if ((err = mp_copy(a, b)) != MP_OKAY) {
           return err;
        }
     }
  
     if (!MP_IS_ZERO(b)) {
        mp_set_sign(b, (mp_get_sign(a) == MP_ZPOS) ? MP_NEG : MP_ZPOS);
     } else {
        mp_set_sign(b, MP_ZPOS);
     }
  
     return MP_OKAY;
  }
static
  mp_err mp_or(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int used = MP_MAX(mp_get_used(a), mp_get_used(b)) + 1, i;
     mp_err err;
     mp_digit ac = 1, bc = 1, cc = 1;
     mp_sign csign = ((mp_get_sign(a) == MP_NEG) || (mp_get_sign(b) == MP_NEG)) ? MP_NEG : MP_ZPOS;
  
     if (mp_get_alloc(c) < used) {
        if ((err = mp_grow(c, used)) != MP_OKAY) {
           return err;
        }
     }
  
     for (i = 0; i < used; i++) {
        mp_digit x, y;
  
        /* convert to two complement if negative */
        if (mp_get_sign(a) == MP_NEG) {
           ac += (i >= mp_get_used(a)) ? MP_MASK : (~mp_get_digit(a, i) & MP_MASK);
           x = ac & MP_MASK;
           ac >>= MP_DIGIT_BIT;
        } else {
           x = (i >= mp_get_used(a)) ? 0uL : mp_get_digit(a, i);
        }
  
        /* convert to two complement if negative */
        if (mp_get_sign(b) == MP_NEG) {
           bc += (i >= mp_get_used(b)) ? MP_MASK : (~mp_get_digit(b, i) & MP_MASK);
           y = bc & MP_MASK;
           bc >>= MP_DIGIT_BIT;
        } else {
           y = (i >= mp_get_used(b)) ? 0uL : mp_get_digit(b, i);
        }
  
        mp_set_digit(c, i, x | y);
  
        /* convert to to sign-magnitude if negative */
        if (csign == MP_NEG) {
           cc += ~mp_get_digit(c, i) & MP_MASK;
           mp_set_digit(c, i, cc & MP_MASK);
           cc >>= MP_DIGIT_BIT;
        }
     }
  
     mp_set_used(c, used);
     mp_set_sign(c, csign);
     mp_clamp(c);
     return MP_OKAY;
  }
static
  void mp_rshd(mp_int *a, int b)
  {
     int     x;
     mp_digit *bottom, *top;
  
     /* if b <= 0 then ignore it */
     if (b <= 0) {
        return;
     }
  
     /* if b > used then simply zero it and return */
     if (mp_get_used(a) <= b) {
        mp_zero(a);
        return;
     }
  
     /* shift the digits down */
  
     /* bottom */
     bottom = mp_get_digit_iter(a);
  
     /* top [offset into digits] */
     top = mp_get_digit_iter(a) + b;
  
     /* this is implemented as a sliding window where
      * the window is b-digits long and digits from
      * the top of the window are copied to the bottom
      *
      * e.g.
  
      b-2 | b-1 | b0 | b1 | b2 | ... | bb |   ---->
                  /\                   |      ---->
                   \-------------------/      ---->
      */
     for (x = 0; x < (mp_get_used(a) - b); x++) {
        *bottom++ = *top++;
     }
  
     /* zero the top digits */
     MP_ZERO_DIGITS(bottom, mp_get_used(a) - x);
  
     /* remove excess digits */
     mp_set_used(a, mp_get_used(a)  - b);
  }
static
  void mp_set(mp_int *a, mp_digit b)
  {
     mp_set_digit(a, 0, b & MP_MASK);
     mp_set_sign(a, MP_ZPOS);
     mp_set_used(a, (mp_get_digit(a, 0) != 0u) ? 1 : 0);
     MP_ZERO_DIGITS(mp_get_digit_iter(a) + mp_get_used(a), mp_get_alloc(a) - mp_get_used(a));
  }
static
  #if defined(__STDC_IEC_559__) || defined(__GCC_IEC_559)
  mp_err mp_set_double(mp_int *a, double b)
  {
     uint64_t frac;
     int exp;
     mp_err err;
     union {
        double   dbl;
        uint64_t bits;
     } cast;
     cast.dbl = b;
  
     exp = (int)((unsigned)(cast.bits >> 52) & 0x7FFu);
     frac = (cast.bits & ((1uLL << 52) - 1uLL)) | (1uLL << 52);
  
     if (exp == 0x7FF) { /* +-inf, NaN */
        return MP_VAL;
     }
     exp -= 1023 + 52;
  
     mp_set_u64(a, frac);
  
     err = (exp < 0) ? mp_div_2d(a, -exp, a, NULL) : mp_mul_2d(a, exp, a);
     if (err != MP_OKAY) {
        return err;
     }
  
     if (((cast.bits >> 63) != 0uLL) && !MP_IS_ZERO(a)) {
        mp_set_sign(a, MP_NEG);
     }
  
     return MP_OKAY;
  }
  #else
  /* pragma message() not supported by several compilers (in mostly older but still used versions) */
  #  ifdef _MSC_VER
  #    pragma message("mp_set_double implementation is only available on platforms with IEEE754 floating point format")
  #  else
  #    warning "mp_set_double implementation is only available on platforms with IEEE754 floating point format"
  #  endif
  #endif
static
  void mp_set_i32(mp_int * a, int32_t b)
  {
      mp_set_u32(a, (b < 0) ? -(uint32_t)b : (uint32_t)b);
      if (b < 0) {
          mp_set_sign(a, MP_NEG);
      }
  }
static
  void mp_set_i64(mp_int * a, int64_t b)
  {
      mp_set_u64(a, (b < 0) ? -(uint64_t)b : (uint64_t)b);
      if (b < 0) {
          mp_set_sign(a, MP_NEG);
      }
  }
static
  void mp_set_u32(mp_int * a, uint32_t b)
  {
      mp_count i = 0;
      while (b != 0u) {
          mp_set_digit(a, i++, ((mp_digit)b & MP_MASK));
          if (MP_SIZEOF_BITS(uint32_t) <= MP_DIGIT_BIT) { break; }
          b >>= ((MP_SIZEOF_BITS(uint32_t) <= MP_DIGIT_BIT) ? 0 : MP_DIGIT_BIT);
      }
      mp_set_used(a, i);
      mp_set_sign(a, MP_ZPOS);
      MP_ZERO_DIGITS(mp_get_digit_iter(a) + mp_get_used(a), mp_get_alloc(a) - mp_get_used(a));
  }
static
  void mp_set_u64(mp_int * a, uint64_t b)
  {
      mp_count i = 0;
      while (b != 0u) {
          mp_set_digit(a, i++, ((mp_digit)b & MP_MASK));
          if (MP_SIZEOF_BITS(uint64_t) <= MP_DIGIT_BIT) { break; }
          b >>= ((MP_SIZEOF_BITS(uint64_t) <= MP_DIGIT_BIT) ? 0 : MP_DIGIT_BIT);
      }
      mp_set_used(a, i);
      mp_set_sign(a, MP_ZPOS);
      MP_ZERO_DIGITS(mp_get_digit_iter(a) + mp_get_used(a), mp_get_alloc(a) - mp_get_used(a));
  }
static
  MP_GET_SIGNED(mp_get_i32, mp_get_mag_u32, int32_t, uint32_t)
static
  MP_GET_MAG(mp_get_mag_u32, uint32_t)
static
  mp_err mp_signed_rsh(const mp_int *a, int b, mp_int *c)
  {
     mp_err res;
     if (mp_get_sign(a) == MP_ZPOS) {
        return mp_div_2d(a, b, c, NULL);
     }
  
     res = mp_add_d(a, 1uL, c);
     if (res != MP_OKAY) {
        return res;
     }
  
     res = mp_div_2d(c, b, c, NULL);
     return (res == MP_OKAY) ? mp_sub_d(c, 1uL, c) : res;
  }
static
  mp_err mp_sqr(const mp_int *a, mp_int *b)
  {
     mp_err err;
     if (MP_HAS(S_MP_TOOM_SQR) && /* use Toom-Cook? */
         (mp_get_used(a) >= MP_TOOM_SQR_CUTOFF)) {
        err = s_mp_toom_sqr(a, b);
     } else if (MP_HAS(S_MP_KARATSUBA_SQR) &&  /* Karatsuba? */
                (mp_get_used(a) >= MP_KARATSUBA_SQR_CUTOFF)) {
        err = s_mp_karatsuba_sqr(a, b);
     } else if (MP_HAS(S_MP_SQR_FAST) && /* can we use the fast comba multiplier? */
                (((mp_get_used(a) * 2) + 1) < MP_WARRAY) &&
                (mp_get_used(a) < (MP_MAXFAST / 2))) {
        err = s_mp_sqr_fast(a, b);
     } else if (MP_HAS(S_MP_SQR)) {
        err = s_mp_sqr(a, b);
     } else {
        err = MP_VAL;
     }
     mp_set_sign(b, MP_ZPOS);
     return err;
  }
static
  mp_err mp_sqrt(const mp_int *arg, mp_int *ret)
  {
     mp_err err;
     mp_int t1, t2;
  
     /* must be positive */
     if (mp_get_sign(arg) == MP_NEG) {
        return MP_VAL;
     }
  
     /* easy out */
     if (MP_IS_ZERO(arg)) {
        mp_zero(ret);
        return MP_OKAY;
     }
  
     if ((err = mp_init_copy(&t1, arg)) != MP_OKAY) {
        return err;
     }
  
     if ((err = mp_init(&t2)) != MP_OKAY) {
        goto E2;
     }
  
     /* First approx. (not very bad for large arg) */
     mp_rshd(&t1, mp_get_used(&t1)/2);
  
     /* t1 > 0  */
     if ((err = mp_div(arg, &t1, &t2, NULL)) != MP_OKAY) {
        goto E1;
     }
     if ((err = mp_add(&t1, &t2, &t1)) != MP_OKAY) {
        goto E1;
     }
     if ((err = mp_div_2(&t1, &t1)) != MP_OKAY) {
        goto E1;
     }
     /* And now t1 > sqrt(arg) */
     do {
        if ((err = mp_div(arg, &t1, &t2, NULL)) != MP_OKAY) {
           goto E1;
        }
        if ((err = mp_add(&t1, &t2, &t1)) != MP_OKAY) {
           goto E1;
        }
        if ((err = mp_div_2(&t1, &t1)) != MP_OKAY) {
           goto E1;
        }
        /* t1 >= sqrt(arg) >= t2 at this point */
     } while (mp_cmp_mag(&t1, &t2) == MP_GT);
  
     mp_exch(&t1, ret);
  
  E1:
     mp_clear(&t2);
  E2:
     mp_clear(&t1);
     return err;
  }
  
static
  mp_err mp_sub(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_sign sa = mp_get_sign(a), sb = mp_get_sign(b);
     mp_err err;
  
     if (sa != sb) {
        /* subtract a negative from a positive, OR */
        /* subtract a positive from a negative. */
        /* In either case, ADD their magnitudes, */
        /* and use the sign of the first number. */
        mp_set_sign(c, sa);
        err = s_mp_add(a, b, c);
     } else {
        /* subtract a positive from a positive, OR */
        /* subtract a negative from a negative. */
        /* First, take the difference between their */
        /* magnitudes, then... */
        if (mp_cmp_mag(a, b) != MP_LT) {
           /* Copy the sign from the first */
           mp_set_sign(c, sa);
           /* The first has a larger or equal magnitude */
           err = s_mp_sub(a, b, c);
        } else {
           /* The result has the *opposite* sign from */
           /* the first number. */
           mp_set_sign(c, (sa == MP_ZPOS) ? MP_NEG : MP_ZPOS);
           /* The second has a larger magnitude */
           err = s_mp_sub(b, a, c);
        }
     }
     return err;
  }
  
static
  mp_err mp_sub_d(const mp_int *a, mp_digit b, mp_int *c)
  {
     mp_digit *tmpa, *tmpc;
     mp_err    err;
     int       ix, oldused;
  
     /* grow c as required */
     if (mp_get_alloc(c) < (mp_get_used(a) + 1)) {
        if ((err = mp_grow(c, mp_get_used(a) + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* if a is negative just do an unsigned
      * addition [with fudged signs]
      */
     if (mp_get_sign(a) == MP_NEG) {
        mp_int a_ = *a;
        mp_set_sign(&a_, MP_ZPOS);
        err     = mp_add_d(&a_, b, c);
        mp_set_sign(c, MP_NEG);
  
        /* clamp */
        mp_clamp(c);
  
        return err;
     }
  
     /* setup regs */
     oldused = mp_get_used(c);
     tmpa    = mp_get_digit_iter(a);
     tmpc    = mp_get_digit_iter(c);
  
     /* if a <= b simply fix the single digit */
     if (((mp_get_used(a) == 1) && (mp_get_digit(a, 0) <= b)) || (mp_get_used(a) == 0)) {
        if (mp_get_used(a) == 1) {
           *tmpc++ = b - *tmpa;
        } else {
           *tmpc++ = b;
        }
        ix      = 1;
  
        /* negative/1digit */
        mp_set_sign(c, MP_NEG);
        mp_set_used(c, 1);
     } else {
        mp_digit mu = b;
  
        /* positive/size */
        mp_set_sign(c, MP_ZPOS);
        mp_set_used(c, mp_get_used(a));
  
        /* subtract digits, mu is carry */
        for (ix = 0; ix < mp_get_used(a); ix++) {
           *tmpc    = *tmpa++ - mu;
           mu       = *tmpc >> (MP_SIZEOF_BITS(mp_digit) - 1u);
           *tmpc++ &= MP_MASK;
        }
     }
  
     /* zero excess digits */
     MP_ZERO_DIGITS(tmpc, oldused - ix);
  
     mp_clamp(c);
     return MP_OKAY;
  }
  
static
  mp_err mp_xor(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int used = MP_MAX(mp_get_used(a), mp_get_used(b)) + 1, i;
     mp_err err;
     mp_digit ac = 1, bc = 1, cc = 1;
     mp_sign csign = (mp_get_sign(a) != mp_get_sign(b)) ? MP_NEG : MP_ZPOS;
  
     if (mp_get_alloc(c) < used) {
        if ((err = mp_grow(c, used)) != MP_OKAY) {
           return err;
        }
     }
  
     for (i = 0; i < used; i++) {
        mp_digit x, y;
  
        /* convert to two complement if negative */
        if (mp_get_sign(a) == MP_NEG) {
           ac += (i >= mp_get_used(a)) ? MP_MASK : (~mp_get_digit(a, i) & MP_MASK);
           x = ac & MP_MASK;
           ac >>= MP_DIGIT_BIT;
        } else {
           x = (i >= mp_get_used(a)) ? 0uL : mp_get_digit(a, i);
        }
  
        /* convert to two complement if negative */
        if (mp_get_sign(b) == MP_NEG) {
           bc += (i >= mp_get_used(b)) ? MP_MASK : (~mp_get_digit(b, i) & MP_MASK);
           y = bc & MP_MASK;
           bc >>= MP_DIGIT_BIT;
        } else {
           y = (i >= mp_get_used(b)) ? 0uL : mp_get_digit(b, i);
        }
  
        mp_set_digit(c, i, x ^ y);
  
        /* convert to to sign-magnitude if negative */
        if (csign == MP_NEG) {
           cc += ~mp_get_digit(c, i) & MP_MASK;
           mp_set_digit(c, i, cc & MP_MASK);
           cc >>= MP_DIGIT_BIT;
        }
     }
  
     mp_set_used(c, used);
     mp_set_sign(c, csign);
     mp_clamp(c);
     return MP_OKAY;
  }
static
  void mp_zero(mp_int *a)
  {
     mp_set_sign(a, MP_ZPOS);
     mp_set_used(a, 0);
     MP_ZERO_DIGITS(mp_get_digit_iter(a), mp_get_alloc(a));
  }
private:
static
  mp_err s_mp_add(const mp_int *a, const mp_int *b, mp_int *c)
  {
     const mp_int *x;
     mp_err err;
     int     olduse, min, max;
  
     /* find sizes, we let |a| <= |b| which means we have to sort
      * them.  "x" will point to the input with the most digits
      */
     if (mp_get_used(a) > mp_get_used(b)) {
        min = mp_get_used(b);
        max = mp_get_used(a);
        x = a;
     } else {
        min = mp_get_used(a);
        max = mp_get_used(b);
        x = b;
     }
  
     /* init result */
     if (mp_get_alloc(c) < (max + 1)) {
        if ((err = mp_grow(c, max + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* get old used digit count and set new one */
     olduse = mp_get_used(c);
     mp_set_used(c, max + 1);
  
     {
        mp_digit u, *tmpa, *tmpb, *tmpc;
        int i;
  
        /* alias for digit pointers */
  
        /* first input */
        tmpa = mp_get_digit_iter(a);
  
        /* second input */
        tmpb = mp_get_digit_iter(b);
  
        /* destination */
        tmpc = mp_get_digit_iter(c);
  
        /* zero the carry */
        u = 0;
        for (i = 0; i < min; i++) {
           /* Compute the sum at one digit, T[i] = A[i] + B[i] + U */
           *tmpc = *tmpa++ + *tmpb++ + u;
  
           /* U = carry bit of T[i] */
           u = *tmpc >> (mp_digit)MP_DIGIT_BIT;
  
           /* take away carry bit from T[i] */
           *tmpc++ &= MP_MASK;
        }
  
        /* now copy higher words if any, that is in A+B
         * if A or B has more digits add those in
         */
        if (min != max) {
           for (; i < max; i++) {
              /* T[i] = X[i] + U */
              *tmpc = mp_get_digit(x, i) + u;
  
              /* U = carry bit of T[i] */
              u = *tmpc >> (mp_digit)MP_DIGIT_BIT;
  
              /* take away carry bit from T[i] */
              *tmpc++ &= MP_MASK;
           }
        }
  
        /* add carry */
        *tmpc++ = u;
  
        /* clear digits above oldused */
        MP_ZERO_DIGITS(tmpc, olduse - mp_get_used(c));
     }
  
     mp_clamp(c);
     return MP_OKAY;
  }
static
  mp_err s_mp_balance_mul(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int count, len_a, len_b, nblocks, i, j, bsize;
     mp_int a0, tmp, A, B, r;
     mp_err err;
  
     len_a = mp_get_used(a);
     len_b = mp_get_used(b);
  
     nblocks = MP_MAX(mp_get_used(a), mp_get_used(b)) / MP_MIN(mp_get_used(a), mp_get_used(b));
     bsize = MP_MIN(mp_get_used(a), mp_get_used(b)) ;
  
     if ((err = mp_init_size(&a0, bsize + 2)) != MP_OKAY) {
        return err;
     }
     if ((err = mp_init_multi((mp_int*[]){&tmp, &r, NULL})) != MP_OKAY) {
        mp_clear(&a0);
        return err;
     }
  
     /* Make sure that A is the larger one*/
     if (len_a < len_b) {
        B = *a;
        A = *b;
     } else {
        A = *a;
        B = *b;
     }
  
     for (i = 0, j=0; i < nblocks; i++) {
        /* Cut a slice off of a */
        mp_set_used(&a0, 0);
        for (count = 0; count < bsize; count++) {
           mp_set_digit(&a0, count, mp_get_digit(&A,  j++ ));
           mp_set_used(&a0, mp_get_used(&a0) + 1);
        }
        mp_clamp(&a0);
        /* Multiply with b */
        if ((err = mp_mul(&a0, &B, &tmp)) != MP_OKAY) {
           goto LBL_ERR;
        }
        /* Shift tmp to the correct position */
        if ((err = mp_lshd(&tmp, bsize * i)) != MP_OKAY) {
           goto LBL_ERR;
        }
        /* Add to output. No carry needed */
        if ((err = mp_add(&r, &tmp, &r)) != MP_OKAY) {
           goto LBL_ERR;
        }
     }
     /* The left-overs; there are always left-overs */
     if (j < mp_get_used(&A)) {
        mp_set_used(&a0, 0);
        for (count = 0; j < mp_get_used(&A); count++) {
           mp_set_digit(&a0, count, mp_get_digit(&A,  j++ ));
           mp_set_used(&a0, mp_get_used(&a0) + 1);
        }
        mp_clamp(&a0);
        if ((err = mp_mul(&a0, &B, &tmp)) != MP_OKAY) {
           goto LBL_ERR;
        }
        if ((err = mp_lshd(&tmp, bsize * i)) != MP_OKAY) {
           goto LBL_ERR;
        }
        if ((err = mp_add(&r, &tmp, &r)) != MP_OKAY) {
           goto LBL_ERR;
        }
     }
  
     mp_exch(&r,c);
  LBL_ERR:
     mp_clear(&a0);
     mp_clear(&tmp);
     mp_clear(&r);
     return err;
  }
static
  mp_err s_mp_div_3(const mp_int *a, mp_int *c, mp_digit *d)
  {
     mp_int   q;
     mp_word  w, t;
     mp_digit b;
     mp_err   err;
     int      ix;
  
     /* b = 2**MP_DIGIT_BIT / 3 */
     b = ((mp_word)1 << (mp_word)MP_DIGIT_BIT) / (mp_word)3;
  
     if ((err = mp_init_size(&q, mp_get_used(a))) != MP_OKAY) {
        return err;
     }
  
     mp_set_used(&q, mp_get_used(a));
     mp_set_sign(&q, mp_get_sign(a));
     w = 0;
     for (ix = mp_get_used(a) - 1; ix >= 0; ix--) {
        w = (w << (mp_word)MP_DIGIT_BIT) | (mp_word)mp_get_digit(a, ix);
  
        if (w >= 3u) {
           /* multiply w by [1/3] */
           t = (w * (mp_word)b) >> (mp_word)MP_DIGIT_BIT;
  
           /* now subtract 3 * [w/3] from w, to get the remainder */
           w -= t+t+t;
  
           /* fixup the remainder as required since
            * the optimization is not exact.
            */
           while (w >= 3u) {
              t += 1u;
              w -= 3u;
           }
        } else {
           t = 0;
        }
        mp_set_digit(&q, ix, (mp_digit)t);
     }
  
     /* [optional] store the remainder */
     if (d != NULL) {
        *d = (mp_digit)w;
     }
  
     /* [optional] store the quotient */
     if (c != NULL) {
        mp_clamp(&q);
        mp_exch(&q, c);
     }
     mp_clear(&q);
  
     return err;
  }
  
static
  mp_err s_mp_mul_digs(const mp_int *a, const mp_int *b, mp_int *c, int digs)
  {
     mp_int  t;
     mp_err  err;
     int     pa, pb, ix, iy;
     mp_digit u;
     mp_word r;
     mp_digit tmpx, *tmpt, *tmpy;
  
     if (digs < 0) {
        return MP_VAL;
     }
  
     /* can we use the fast multiplier? */
     if ((digs < MP_WARRAY) &&
         (MP_MIN(mp_get_used(a), mp_get_used(b)) < MP_MAXFAST)) {
        return s_mp_mul_digs_fast(a, b, c, digs);
     }
  
     if ((err = mp_init_size(&t, digs)) != MP_OKAY) {
        return err;
     }
     mp_set_used(&t, digs);
  
     /* compute the digits of the product directly */
     pa = mp_get_used(a);
     for (ix = 0; ix < pa; ix++) {
        /* set the carry to zero */
        u = 0;
  
        /* limit ourselves to making digs digits of output */
        pb = MP_MIN(mp_get_used(b), digs - ix);
  
        /* setup some aliases */
        /* copy of the digit from a used within the nested loop */
        tmpx = mp_get_digit(a, ix);
  
        /* an alias for the destination shifted ix places */
        tmpt = mp_get_digit_iter(&t) + ix;
  
        /* an alias for the digits of b */
        tmpy = mp_get_digit_iter(b);
  
        /* compute the columns of the output and propagate the carry */
        for (iy = 0; iy < pb; iy++) {
           /* compute the column as a mp_word */
           r       = (mp_word)*tmpt +
                     ((mp_word)tmpx * (mp_word)*tmpy++) +
                     (mp_word)u;
  
           /* the new column is the lower part of the result */
           *tmpt++ = (mp_digit)(r & (mp_word)MP_MASK);
  
           /* get the carry word from the result */
           u       = (mp_digit)(r >> (mp_word)MP_DIGIT_BIT);
        }
        /* set carry if it is placed below digs */
        if ((ix + iy) < digs) {
           *tmpt = u;
        }
     }
  
     mp_clamp(&t);
     mp_exch(&t, c);
  
     mp_clear(&t);
     return MP_OKAY;
  }
static
  mp_err s_mp_mul_digs_fast(const mp_int *a, const mp_int *b, mp_int *c, int digs)
  {
     int      olduse, pa, ix, iz;
     mp_err   err;
     mp_digit W[MP_WARRAY];
     mp_word  _W;
  
     if (digs < 0) {
        return MP_VAL;
     }
  
     /* grow the destination as required */
     if (mp_get_alloc(c) < digs) {
        if ((err = mp_grow(c, digs)) != MP_OKAY) {
           return err;
        }
     }
  
     /* number of output digits to produce */
     pa = MP_MIN(digs, mp_get_used(a) + mp_get_used(b));
  
     /* clear the carry */
     _W = 0;
     for (ix = 0; ix < pa; ix++) {
        int      tx, ty;
        int      iy;
        mp_digit *tmpx, *tmpy;
  
        /* get offsets into the two bignums */
        ty = MP_MIN(mp_get_used(b)-1, ix);
        tx = ix - ty;
  
        /* setup temp aliases */
        tmpx = mp_get_digit_iter(a) + tx;
        tmpy = mp_get_digit_iter(b) + ty;
  
        /* this is the number of times the loop will iterrate, essentially
           while (tx++ < mp_get_used(a) && ty-- >= 0) { ... }
         */
        iy = MP_MIN(mp_get_used(a)-tx, ty+1);
  
        /* execute loop */
        for (iz = 0; iz < iy; ++iz) {
           _W += (mp_word)*tmpx++ * (mp_word)*tmpy--;
  
        }
  
        /* store term */
        W[ix] = (mp_digit)_W & MP_MASK;
  
        /* make next carry */
        _W = _W >> (mp_word)MP_DIGIT_BIT;
     }
  
     /* setup dest */
     olduse  = mp_get_used(c);
     mp_set_used(c, pa);
  
     {
        mp_digit *tmpc;
        tmpc = mp_get_digit_iter(c);
        for (ix = 0; ix < pa; ix++) {
           /* now extract the previous digit [below the carry] */
           *tmpc++ = W[ix];
        }
  
        /* clear unused digits [that existed in the old copy of c] */
        MP_ZERO_DIGITS(tmpc, olduse - ix);
     }
     mp_clamp(c);
     return MP_OKAY;
  }
static
  mp_err s_mp_sqr(const mp_int *a, mp_int *b)
  {
     mp_int   t;
     int      ix, iy, pa;
     mp_err   err;
     mp_word  r;
     mp_digit u, tmpx, *tmpt;
  
     pa = mp_get_used(a);
     if ((err = mp_init_size(&t, (2 * pa) + 1)) != MP_OKAY) {
        return err;
     }
  
     /* default used is maximum possible size */
     mp_set_used(&t, (2 * pa) + 1);
  
     for (ix = 0; ix < pa; ix++) {
        /* first calculate the digit at 2*ix */
        /* calculate double precision result */
        r = (mp_word)mp_get_digit(&t, 2*ix) +
            ((mp_word)mp_get_digit(a, ix) * (mp_word)mp_get_digit(a, ix));
  
        /* store lower part in result */
        mp_set_digit(&t, ix+ix, (mp_digit)(r & (mp_word)MP_MASK));
  
        /* get the carry */
        u           = (mp_digit)(r >> (mp_word)MP_DIGIT_BIT);
  
        /* left hand side of A[ix] * A[iy] */
        tmpx        = mp_get_digit(a, ix);
  
        /* alias for where to store the results */
        tmpt        = mp_get_digit_iter(&t) + ((2 * ix) + 1);
  
        for (iy = ix + 1; iy < pa; iy++) {
           /* first calculate the product */
           r       = (mp_word)tmpx * (mp_word)mp_get_digit(a, iy);
  
           /* now calculate the double precision result, note we use
            * addition instead of *2 since it's easier to optimize
            */
           r       = (mp_word)*tmpt + r + r + (mp_word)u;
  
           /* store lower part */
           *tmpt++ = (mp_digit)(r & (mp_word)MP_MASK);
  
           /* get carry */
           u       = (mp_digit)(r >> (mp_word)MP_DIGIT_BIT);
        }
        /* propagate upwards */
        while (u != 0uL) {
           r       = (mp_word)*tmpt + (mp_word)u;
           *tmpt++ = (mp_digit)(r & (mp_word)MP_MASK);
           u       = (mp_digit)(r >> (mp_word)MP_DIGIT_BIT);
        }
     }
  
     mp_clamp(&t);
     mp_exch(&t, b);
     mp_clear(&t);
     return MP_OKAY;
  }
static
  mp_err s_mp_sqr_fast(const mp_int *a, mp_int *b)
  {
     int       olduse, pa, ix, iz;
     mp_digit  W[MP_WARRAY], *tmpx;
     mp_word   W1;
     mp_err    err;
  
     /* grow the destination as required */
     pa = mp_get_used(a) + mp_get_used(a);
     if (mp_get_alloc(b) < pa) {
        if ((err = mp_grow(b, pa)) != MP_OKAY) {
           return err;
        }
     }
  
     /* number of output digits to produce */
     W1 = 0;
     for (ix = 0; ix < pa; ix++) {
        int      tx, ty, iy;
        mp_word  _W;
        mp_digit *tmpy;
  
        /* clear counter */
        _W = 0;
  
        /* get offsets into the two bignums */
        ty = MP_MIN(mp_get_used(a)-1, ix);
        tx = ix - ty;
  
        /* setup temp aliases */
        tmpx = mp_get_digit_iter(a) + tx;
        tmpy = mp_get_digit_iter(a) + ty;
  
        /* this is the number of times the loop will iterrate, essentially
           while (tx++ < mp_get_used(a) && ty-- >= 0) { ... }
         */
        iy = MP_MIN(mp_get_used(a)-tx, ty+1);
  
        /* now for squaring tx can never equal ty
         * we halve the distance since they approach at a rate of 2x
         * and we have to round because odd cases need to be executed
         */
        iy = MP_MIN(iy, ((ty-tx)+1)>>1);
  
        /* execute loop */
        for (iz = 0; iz < iy; iz++) {
           _W += (mp_word)*tmpx++ * (mp_word)*tmpy--;
        }
  
        /* double the inner product and add carry */
        _W = _W + _W + W1;
  
        /* even columns have the square term in them */
        if (((unsigned)ix & 1u) == 0u) {
           _W += (mp_word)mp_get_digit(a, ix>>1) * (mp_word)mp_get_digit(a, ix>>1);
        }
  
        /* store it */
        W[ix] = (mp_digit)_W & MP_MASK;
  
        /* make next carry */
        W1 = _W >> (mp_word)MP_DIGIT_BIT;
     }
  
     /* setup dest */
     olduse  = mp_get_used(b);
     mp_set_used(b, mp_get_used(a)+mp_get_used(a));
  
     {
        mp_digit *tmpb;
        tmpb = mp_get_digit_iter(b);
        for (ix = 0; ix < pa; ix++) {
           *tmpb++ = W[ix] & MP_MASK;
        }
  
        /* clear unused digits [that existed in the old copy of c] */
        MP_ZERO_DIGITS(tmpb, olduse - ix);
     }
     mp_clamp(b);
     return MP_OKAY;
  }
static
  /*
     This file contains code from J. Arndt's book  "Matters Computational"
     and the accompanying FXT-library with permission of the author.
  */
  
  /* squaring using Toom-Cook 3-way algorithm */
  /*
     Setup and interpolation from algorithm SQR_3 in
  
       Chung, Jaewook, and M. Anwar Hasan. "Asymmetric squaring formulae."
       18th IEEE Symposium on Computer Arithmetic (ARITH'07). IEEE, 2007.
  
  */
  mp_err s_mp_toom_sqr(const mp_int *a, mp_int *b)
  {
     mp_int S0, a0, a1, a2;
     mp_digit *tmpa, *tmpc;
     int B, count;
     mp_err err;
  
     /* init temps */
     if ((err = mp_init(&S0)) != MP_OKAY) {
        return err;
     }
  
     /* B */
     B = mp_get_used(a) / 3;
  
     /** a = a2 * x^2 + a1 * x + a0; */
     if ((err = mp_init_size(&a0, B)) != MP_OKAY)                   goto LBL_ERRa0;
  
     mp_set_used(&a0, B);
     if ((err = mp_init_size(&a1, B)) != MP_OKAY)                   goto LBL_ERRa1;
     mp_set_used(&a1, B);
     if ((err = mp_init_size(&a2, B + (mp_get_used(a) - (3 * B)))) != MP_OKAY) goto LBL_ERRa2;
  
     tmpa = mp_get_digit_iter(a);
     tmpc = mp_get_digit_iter(&a0);
     for (count = 0; count < B; count++) {
        *tmpc++ = *tmpa++;
     }
     tmpc = mp_get_digit_iter(&a1);
     for (; count < (2 * B); count++) {
        *tmpc++ = *tmpa++;
     }
     tmpc = mp_get_digit_iter(&a2);
     for (; count < mp_get_used(a); count++) {
        *tmpc++ = *tmpa++;
        mp_set_used(&a2, mp_get_used(&a2) + 1);
     }
     mp_clamp(&a0);
     mp_clamp(&a1);
     mp_clamp(&a2);
  
     /** S0 = a0^2;  */
     if ((err = mp_sqr(&a0, &S0)) != MP_OKAY)                       goto LBL_ERR;
  
     /** \\S1 = (a2 + a1 + a0)^2 */
     /** \\S2 = (a2 - a1 + a0)^2  */
     /** \\S1 = a0 + a2; */
     /** a0 = a0 + a2; */
     if ((err = mp_add(&a0, &a2, &a0)) != MP_OKAY)                  goto LBL_ERR;
     /** \\S2 = S1 - a1; */
     /** b = a0 - a1; */
     if ((err = mp_sub(&a0, &a1, b)) != MP_OKAY)                    goto LBL_ERR;
     /** \\S1 = S1 + a1; */
     /** a0 = a0 + a1; */
     if ((err = mp_add(&a0, &a1, &a0)) != MP_OKAY)                  goto LBL_ERR;
     /** \\S1 = S1^2;  */
     /** a0 = a0^2; */
     if ((err = mp_sqr(&a0, &a0)) != MP_OKAY)                       goto LBL_ERR;
     /** \\S2 = S2^2;  */
     /** b = b^2; */
     if ((err = mp_sqr(b, b)) != MP_OKAY)                           goto LBL_ERR;
  
     /** \\ S3 = 2 * a1 * a2  */
     /** \\S3 = a1 * a2;  */
     /** a1 = a1 * a2; */
     if ((err = mp_mul(&a1, &a2, &a1)) != MP_OKAY)                  goto LBL_ERR;
     /** \\S3 = S3 << 1;  */
     /** a1 = a1 << 1; */
     if ((err = mp_mul_2(&a1, &a1)) != MP_OKAY)                     goto LBL_ERR;
  
     /** \\S4 = a2^2;  */
     /** a2 = a2^2; */
     if ((err = mp_sqr(&a2, &a2)) != MP_OKAY)                       goto LBL_ERR;
  
     /** \\ tmp = (S1 + S2)/2  */
     /** \\tmp = S1 + S2; */
     /** b = a0 + b; */
     if ((err = mp_add(&a0, b, b)) != MP_OKAY)                      goto LBL_ERR;
     /** \\tmp = tmp >> 1; */
     /** b = b >> 1; */
     if ((err = mp_div_2(b, b)) != MP_OKAY)                         goto LBL_ERR;
  
     /** \\ S1 = S1 - tmp - S3  */
     /** \\S1 = S1 - tmp; */
     /** a0 = a0 - b; */
     if ((err = mp_sub(&a0, b, &a0)) != MP_OKAY)                    goto LBL_ERR;
     /** \\S1 = S1 - S3;  */
     /** a0 = a0 - a1; */
     if ((err = mp_sub(&a0, &a1, &a0)) != MP_OKAY)                  goto LBL_ERR;
  
     /** \\S2 = tmp - S4 -S0  */
     /** \\S2 = tmp - S4;  */
     /** b = b - a2; */
     if ((err = mp_sub(b, &a2, b)) != MP_OKAY)                      goto LBL_ERR;
     /** \\S2 = S2 - S0;  */
     /** b = b - S0; */
     if ((err = mp_sub(b, &S0, b)) != MP_OKAY)                      goto LBL_ERR;
  
     /** \\P = S4*x^4 + S3*x^3 + S2*x^2 + S1*x + S0; */
     /** P = a2*x^4 + a1*x^3 + b*x^2 + a0*x + S0; */
  
     if ((err = mp_lshd(&a2, 4 * B)) != MP_OKAY)                    goto LBL_ERR;
     if ((err = mp_lshd(&a1, 3 * B)) != MP_OKAY)                    goto LBL_ERR;
     if ((err = mp_lshd(b, 2 * B)) != MP_OKAY)                      goto LBL_ERR;
     if ((err = mp_lshd(&a0, 1 * B)) != MP_OKAY)                    goto LBL_ERR;
     if ((err = mp_add(&a2, &a1, &a2)) != MP_OKAY)                  goto LBL_ERR;
     if ((err = mp_add(&a2, b, b)) != MP_OKAY)                      goto LBL_ERR;
     if ((err = mp_add(b, &a0, b)) != MP_OKAY)                      goto LBL_ERR;
     if ((err = mp_add(b, &S0, b)) != MP_OKAY)                      goto LBL_ERR;
     /** a^2 - P  */
  
  LBL_ERR:
     mp_clear(&a2);
  LBL_ERRa2:
     mp_clear(&a1);
  LBL_ERRa1:
     mp_clear(&a0);
  LBL_ERRa0:
     mp_clear(&S0);
  
     return err;
  }
  
static
  mp_err s_mp_karatsuba_sqr(const mp_int *a, mp_int *b)
  {
     mp_int  x0, x1, t1, t2, x0x0, x1x1;
     int     B;
     mp_err  err = MP_MEM;
  
     /* min # of digits */
     B = mp_get_used(a);
  
     /* now divide in two */
     B = B >> 1;
  
     /* init copy all the temps */
     if (mp_init_size(&x0, B) != MP_OKAY)
        goto LBL_ERR;
     if (mp_init_size(&x1, mp_get_used(a) - B) != MP_OKAY)
        goto X0;
  
     /* init temps */
     if (mp_init_size(&t1, mp_get_used(a) * 2) != MP_OKAY)
        goto X1;
     if (mp_init_size(&t2, mp_get_used(a) * 2) != MP_OKAY)
        goto T1;
     if (mp_init_size(&x0x0, B * 2) != MP_OKAY)
        goto T2;
     if (mp_init_size(&x1x1, (mp_get_used(a) - B) * 2) != MP_OKAY)
        goto X0X0;
  
     {
        int x;
        mp_digit *dst, *src;
  
        src = mp_get_digit_iter(a);
  
        /* now shift the digits */
        dst = mp_get_digit_iter(&x0);
        for (x = 0; x < B; x++) {
           *dst++ = *src++;
        }
  
        dst = mp_get_digit_iter(&x1);
        for (x = B; x < mp_get_used(a); x++) {
           *dst++ = *src++;
        }
     }
  
     mp_set_used(&x0, B);
     mp_set_used(&x1, mp_get_used(a) - B);
  
     mp_clamp(&x0);
  
     /* now calc the products x0*x0 and x1*x1 */
     if (mp_sqr(&x0, &x0x0) != MP_OKAY)
        goto X1X1;           /* x0x0 = x0*x0 */
     if (mp_sqr(&x1, &x1x1) != MP_OKAY)
        goto X1X1;           /* x1x1 = x1*x1 */
  
     /* now calc (x1+x0)**2 */
     if (s_mp_add(&x1, &x0, &t1) != MP_OKAY)
        goto X1X1;           /* t1 = x1 - x0 */
     if (mp_sqr(&t1, &t1) != MP_OKAY)
        goto X1X1;           /* t1 = (x1 - x0) * (x1 - x0) */
  
     /* add x0y0 */
     if (s_mp_add(&x0x0, &x1x1, &t2) != MP_OKAY)
        goto X1X1;           /* t2 = x0x0 + x1x1 */
     if (s_mp_sub(&t1, &t2, &t1) != MP_OKAY)
        goto X1X1;           /* t1 = (x1+x0)**2 - (x0x0 + x1x1) */
  
     /* shift by B */
     if (mp_lshd(&t1, B) != MP_OKAY)
        goto X1X1;           /* t1 = (x0x0 + x1x1 - (x1-x0)*(x1-x0))<<B */
     if (mp_lshd(&x1x1, B * 2) != MP_OKAY)
        goto X1X1;           /* x1x1 = x1x1 << 2*B */
  
     if (mp_add(&x0x0, &t1, &t1) != MP_OKAY)
        goto X1X1;           /* t1 = x0x0 + t1 */
     if (mp_add(&t1, &x1x1, b) != MP_OKAY)
        goto X1X1;           /* t1 = x0x0 + t1 + x1x1 */
  
     err = MP_OKAY;
  
  X1X1:
     mp_clear(&x1x1);
  X0X0:
     mp_clear(&x0x0);
  T2:
     mp_clear(&t2);
  T1:
     mp_clear(&t1);
  X1:
     mp_clear(&x1);
  X0:
     mp_clear(&x0);
  LBL_ERR:
     return err;
  }
static
  mp_err s_mp_sub(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int    olduse, min, max;
     mp_err err;
  
     /* find sizes */
     min = mp_get_used(b);
     max = mp_get_used(a);
  
     /* init result */
     if (mp_get_alloc(c) < max) {
        if ((err = mp_grow(c, max)) != MP_OKAY) {
           return err;
        }
     }
     olduse = mp_get_used(c);
     mp_set_used(c, max);
  
     {
        mp_digit u, *tmpa, *tmpb, *tmpc;
        int i;
  
        /* alias for digit pointers */
        tmpa = mp_get_digit_iter(a);
        tmpb = mp_get_digit_iter(b);
        tmpc = mp_get_digit_iter(c);
  
        /* set carry to zero */
        u = 0;
        for (i = 0; i < min; i++) {
           /* T[i] = A[i] - B[i] - U */
           *tmpc = (*tmpa++ - *tmpb++) - u;
  
           /* U = carry bit of T[i]
            * Note this saves performing an AND operation since
            * if a carry does occur it will propagate all the way to the
            * MSB.  As a result a single shift is enough to get the carry
            */
           u = *tmpc >> (MP_SIZEOF_BITS(mp_digit) - 1u);
  
           /* Clear carry from T[i] */
           *tmpc++ &= MP_MASK;
        }
  
        /* now copy higher words if any, e.g. if A has more digits than B  */
        for (; i < max; i++) {
           /* T[i] = A[i] - U */
           *tmpc = *tmpa++ - u;
  
           /* U = carry bit of T[i] */
           u = *tmpc >> (MP_SIZEOF_BITS(mp_digit) - 1u);
  
           /* Clear carry from T[i] */
           *tmpc++ &= MP_MASK;
        }
  
        /* clear digits above used (since we may not have grown result above) */
        MP_ZERO_DIGITS(tmpc, olduse - mp_get_used(c));
     }
  
     mp_clamp(c);
     return MP_OKAY;
  }
  

};

}
#endif // BIGINT_TOMMATH_HPP_INCLUDED
