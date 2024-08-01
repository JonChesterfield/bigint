#ifndef BIGINT_TOMMATH_HPP_INCLUDED
#define BIGINT_TOMMATH_HPP_INCLUDED

#include <stddef.h>
#include <stdint.h>

// Derived mechanically from libtommath:
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

template <typename mp_int>
class bigint_tommath
{
public:
  typedef uint32_t mp_digit;
  typedef uint64_t mp_word;

  typedef mp_digit* mp_digit_iter;
  typedef const mp_digit* mp_digit_const_iter;

  static inline mp_digit_const_iter  mp_int_get_citer(const mp_int * i) {return i->dp; }
  static inline mp_digit_iter  mp_int_get_miter(mp_int *i) {return i->dp;}

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

#  define MP_ZERO_DIGITS(mem, digits)                   \
do {                                                    \
   int zd_ = (digits);                                  \
   mp_digit_iter zm_ = (mem);                           \
   while (zd_-- > 0) {                                  \
      *zm_++ = 0;                                       \
   }                                                    \
} while (0)

#define MP_SET_UNSIGNED(name, type)                                                    \
    void name(mp_int * a, type b)                                                      \
    {                                                                                  \
        int i = 0;                                                                     \
        while (b != 0u) {                                                              \
            a->dp[i++] = ((mp_digit)b & MP_MASK);                                      \
            if (MP_SIZEOF_BITS(type) <= MP_DIGIT_BIT) { break; }                       \
            b >>= ((MP_SIZEOF_BITS(type) <= MP_DIGIT_BIT) ? 0 : MP_DIGIT_BIT);         \
        }                                                                              \
        a->used = i;                                                                   \
        a->sign = MP_ZPOS;                                                             \
        MP_ZERO_DIGITS(mp_int_get_miter(a) + a->used, a->alloc - a->used); \
    }

#define MP_SET_SIGNED(name, uname, type, utype)          \
    void name(mp_int * a, type b)                        \
    {                                                    \
        uname(a, (b < 0) ? -(utype)b : (utype)b);        \
        if (b < 0) { a->sign = MP_NEG; }                 \
    }


#define MP_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MP_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MP_IS_ZERO(a) ((a)->used == 0)

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

#define mp_iszero(a) (((a)->used == 0) ? MP_YES : MP_NO)
#define mp_isneg(a)  (((a)->sign != MP_ZPOS) ? MP_YES : MP_NO)

#define MP_WARRAY (int)(1uLL << (((8 * sizeof(mp_word)) - (2 * MP_DIGIT_BIT)) + 1))

#define MP_DEFAULT_KARATSUBA_MUL_CUTOFF 80
#define MP_DEFAULT_KARATSUBA_SQR_CUTOFF 120
#define MP_DEFAULT_TOOM_MUL_CUTOFF      350
#define MP_DEFAULT_TOOM_SQR_CUTOFF      400
#  define MP_KARATSUBA_MUL_CUTOFF MP_DEFAULT_KARATSUBA_MUL_CUTOFF
#  define MP_KARATSUBA_SQR_CUTOFF MP_DEFAULT_KARATSUBA_SQR_CUTOFF
#  define MP_TOOM_MUL_CUTOFF      MP_DEFAULT_TOOM_MUL_CUTOFF
#  define MP_TOOM_SQR_CUTOFF      MP_DEFAULT_TOOM_SQR_CUTOFF

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
     b->sign = MP_ZPOS;
  
     return MP_OKAY;
  }
  mp_err mp_add(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_sign sa, sb;
     mp_err err;
  
     /* get sign of both inputs */
     sa = a->sign;
     sb = b->sign;
  
     /* handle two cases, not four */
     if (sa == sb) {
        /* both positive or both negative */
        /* add their magnitudes, copy the sign */
        c->sign = sa;
        err = s_mp_add(a, b, c);
     } else {
        /* one positive, the other negative */
        /* subtract the one with the greater magnitude from */
        /* the one of the lesser magnitude.  The result gets */
        /* the sign of the one with the greater magnitude. */
        if (mp_cmp_mag(a, b) == MP_LT) {
           c->sign = sb;
           err = s_mp_sub(b, a, c);
        } else {
           c->sign = sa;
           err = s_mp_sub(a, b, c);
        }
     }
     return err;
  }
  
  mp_err mp_add_d(const mp_int *a, mp_digit b, mp_int *c)
  {
     mp_err     err;
     int ix, oldused;
  
     /* grow c as required */
     if (c->alloc < (a->used + 1)) {
        if ((err = mp_grow(c, a->used + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* if a is negative and |a| >= b, call c = |a| - b */
     if ((a->sign == MP_NEG) && ((a->used > 1) || (a->dp[0] >= b))) {
        mp_int a_ = *a;
        /* temporarily fix sign of a */
        a_.sign = MP_ZPOS;
  
        /* c = |a| - b */
        err = mp_sub_d(&a_, b, c);
  
        /* fix sign  */
        c->sign = MP_NEG;
  
        /* clamp */
        mp_clamp(c);
  
        return err;
     }
  
     /* old number of used digits in c */
     oldused = c->used;
  
     /* source alias */
     mp_digit_const_iter   tmpa    = mp_int_get_citer(a);
  
     /* destination alias */
     mp_digit_iter tmpc    = mp_int_get_miter(c);
  
     /* if a is positive */
     if (a->sign == MP_ZPOS) {
        /* add digits, mu is carry */
        mp_digit mu = b;
        for (ix = 0; ix < a->used; ix++) {
           *tmpc   = *tmpa++ + mu;
           mu      = *tmpc >> MP_DIGIT_BIT;
           *tmpc++ &= MP_MASK;
        }
        /* set final carry */
        ix++;
        *tmpc++  = mu;
  
        /* setup size */
        c->used = a->used + 1;
     } else {
        /* a was negative and |a| < b */
        c->used  = 1;
  
        /* the result is a single digit */
        if (a->used == 1) {
           *tmpc++  =  b - a->dp[0];
        } else {
           *tmpc++  =  b;
        }
  
        /* setup count so the clearing of oldused
         * can fall through correctly
         */
        ix       = 1;
     }
  
     /* sign always positive */
     c->sign = MP_ZPOS;
  
     /* now zero to oldused */
     MP_ZERO_DIGITS(tmpc, oldused - ix);
     mp_clamp(c);
  
     return MP_OKAY;
  }
  
  mp_err mp_and(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int used = MP_MAX(a->used, b->used) + 1, i;
     mp_err err;
     mp_digit ac = 1, bc = 1, cc = 1;
     mp_sign csign = ((a->sign == MP_NEG) && (b->sign == MP_NEG)) ? MP_NEG : MP_ZPOS;
  
     if (c->alloc < used) {
        if ((err = mp_grow(c, used)) != MP_OKAY) {
           return err;
        }
     }
  
     for (i = 0; i < used; i++) {
        mp_digit x, y;
  
        /* convert to two complement if negative */
        if (a->sign == MP_NEG) {
           ac += (i >= a->used) ? MP_MASK : (~a->dp[i] & MP_MASK);
           x = ac & MP_MASK;
           ac >>= MP_DIGIT_BIT;
        } else {
           x = (i >= a->used) ? 0uL : a->dp[i];
        }
  
        /* convert to two complement if negative */
        if (b->sign == MP_NEG) {
           bc += (i >= b->used) ? MP_MASK : (~b->dp[i] & MP_MASK);
           y = bc & MP_MASK;
           bc >>= MP_DIGIT_BIT;
        } else {
           y = (i >= b->used) ? 0uL : b->dp[i];
        }
  
        c->dp[i] = x & y;
  
        /* convert to to sign-magnitude if negative */
        if (csign == MP_NEG) {
           cc += ~c->dp[i] & MP_MASK;
           c->dp[i] = cc & MP_MASK;
           cc >>= MP_DIGIT_BIT;
        }
     }
  
     c->used = used;
     c->sign = csign;
     mp_clamp(c);
     return MP_OKAY;
  }
  mp_err mp_init(mp_int *a)
  {
    /* special cased */
    /* equivalent to the normal definition, swapping it out removes an allocation site */
    enum {MP_PREC = 8, };
    return mp_init_size(a, (size_t)MP_PREC);
  }
  void mp_clamp(mp_int *a)
  {
     /* decrease used while the most significant digit is
      * zero.
      */
     while ((a->used > 0) && (a->dp[a->used - 1] == 0u)) {
        --(a->used);
     }
  
     /* reset the sign flag if used == 0 */
     if (a->used == 0) {
        a->sign = MP_ZPOS;
     }
  }
  mp_ord mp_cmp(const mp_int *a, const mp_int *b)
  {
     /* compare based on sign */
     if (a->sign != b->sign) {
        if (a->sign == MP_NEG) {
           return MP_LT;
        } else {
           return MP_GT;
        }
     }
  
     /* compare digits */
     if (a->sign == MP_NEG) {
        /* if negative compare opposite direction */
        return mp_cmp_mag(b, a);
     } else {
        return mp_cmp_mag(a, b);
     }
  }
  mp_ord mp_cmp_d(const mp_int *a, mp_digit b)
  {
     /* compare based on sign */
     if (a->sign == MP_NEG) {
        return MP_LT;
     }
  
     /* compare based on magnitude */
     if (a->used > 1) {
        return MP_GT;
     }
  
     /* compare the only digit of a to b */
     if (a->dp[0] > b) {
        return MP_GT;
     } else if (a->dp[0] < b) {
        return MP_LT;
     } else {
        return MP_EQ;
     }
  }
  mp_ord mp_cmp_mag(const mp_int *a, const mp_int *b)
  {
     int     n;
  
     /* compare based on # of non-zero digits */
     if (a->used > b->used) {
        return MP_GT;
     }
  
     if (a->used < b->used) {
        return MP_LT;
     }
  
     /* alias for a */
     mp_digit_const_iter tmpa = mp_int_get_citer(a) + (a->used - 1);
  
     /* alias for b */
     mp_digit_const_iter tmpb = mp_int_get_citer(b) + (a->used - 1);
  
     /* compare based on digits  */
     for (n = 0; n < a->used; ++n, --tmpa, --tmpb) {
        if (*tmpa > *tmpb) {
           return MP_GT;
        }
  
        if (*tmpa < *tmpb) {
           return MP_LT;
        }
     }
     return MP_EQ;
  }
  mp_err mp_complement(const mp_int *a, mp_int *b)
  {
     mp_err err = mp_neg(a, b);
     return (err == MP_OKAY) ? mp_sub_d(b, 1uL, b) : err;
  }
  mp_err mp_copy(const mp_int *a, mp_int *b)
  {
     int n;
     mp_err err;
  
     /* if dst == src do nothing */
     if (a == b) {
        return MP_OKAY;
     }
  
     /* grow dest */
     if (b->alloc < a->used) {
        if ((err = mp_grow(b, a->used)) != MP_OKAY) {
           return err;
        }
     }
  
     /* zero b and copy the parameters over */
     /* pointer aliases */
  
     /* source */
     mp_digit_const_iter   tmpa = mp_int_get_citer(a);
  
     /* destination */
     mp_digit_iter   tmpb = mp_int_get_miter(b);
  
     /* copy all the digits */
     for (n = 0; n < a->used; n++) {
        *tmpb++ = *tmpa++;
     }
  
     /* clear high digits */
     MP_ZERO_DIGITS(tmpb, b->used - n);
  
     /* copy used count and sign */
     b->used = a->used;
     b->sign = a->sign;
     return MP_OKAY;
  }
  int mp_count_bits(const mp_int *a)
  {
     int     r;
     mp_digit q;
  
     /* shortcut */
     if (MP_IS_ZERO(a)) {
        return 0;
     }
  
     /* get number of digits and add that */
     r = (a->used - 1) * MP_DIGIT_BIT;
  
     /* take the last digit and count the bits in it */
     q = a->dp[a->used - 1];
     while (q > 0u) {
        ++r;
        q >>= 1u;
     }
     return r;
  }
  mp_err mp_decr(mp_int *a)
  {
     if (MP_IS_ZERO(a)) {
        mp_set(a,1uL);
        a->sign = MP_NEG;
        return MP_OKAY;
     } else if (a->sign == MP_NEG) {
        mp_err err;
        a->sign = MP_ZPOS;
        if ((err = mp_incr(a)) != MP_OKAY) {
           return err;
        }
        /* There is no -0 in LTM */
        if (!MP_IS_ZERO(a)) {
           a->sign = MP_NEG;
        }
        return MP_OKAY;
     } else if (a->dp[0] > 1uL) {
        a->dp[0]--;
        if (a->dp[0] == 0u) {
           mp_zero(a);
        }
        return MP_OKAY;
     } else {
        return mp_sub_d(a, 1uL,a);
     }
  }
  mp_err mp_div(const mp_int *a, const mp_int *b, mp_int *c, mp_int *d)
  {
     mp_int ta, tb, tq, q;
     int     n, n2;
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
     if ((err = mp_init_multi(&ta, &tb, &tq, &q, NULL)) != MP_OKAY) {
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
     n  = a->sign;
     n2 = (a->sign == b->sign) ? MP_ZPOS : MP_NEG;
     if (c != NULL) {
        mp_exch(c, &q);
        c->sign  = MP_IS_ZERO(c) ? MP_ZPOS : n2;
     }
     if (d != NULL) {
        mp_exch(d, &ta);
        d->sign = MP_IS_ZERO(d) ? MP_ZPOS : n;
     }
  LBL_ERR:
     mp_clear_multi(&ta, &tb, &tq, &q, NULL);
     return err;
  }
  
  mp_err mp_div_2(const mp_int *a, mp_int *b)
  {
     int     x, oldused;
     mp_digit r, rr;
     mp_err err;
  
     /* copy */
     if (b->alloc < a->used) {
        if ((err = mp_grow(b, a->used)) != MP_OKAY) {
           return err;
        }
     }
  
     oldused = b->used;
     b->used = a->used;
  
     /* source alias */
     mp_digit_const_iter   tmpa = mp_int_get_citer(a) + b->used - 1;
  
     /* dest alias */
     mp_digit_iter   tmpb = mp_int_get_miter(b) + b->used - 1;
  
     /* carry */
     r = 0;
     for (x = b->used - 1; x >= 0; x--) {
        /* get the carry for the next iteration */
        rr = *tmpa & 1u;
  
        /* shift the current digit, add in carry and store */
        *tmpb-- = (*tmpa-- >> 1) | (r << (MP_DIGIT_BIT - 1));
  
        /* forward carry to next iteration */
        r = rr;
     }
  
     /* zero excess digits */
     MP_ZERO_DIGITS(mp_int_get_miter(b) + b->used, oldused - b->used);
  
     b->sign = a->sign;
     mp_clamp(b);
     return MP_OKAY;
  }
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
        mp_digit mask, shift;
  
        /* mask */
        mask = ((mp_digit)1 << D) - 1uL;
  
        /* shift for lsb */
        shift = (mp_digit)MP_DIGIT_BIT - D;
  
        /* alias */
        mp_digit_iter tmpc = mp_int_get_miter(c) + (c->used - 1);
  
        /* carry */
        r = 0;
        for (x = c->used - 1; x >= 0; x--) {
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
           *d = a->dp[0] & (((mp_digit)1<<(mp_digit)ix) - 1uL);
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
     if ((err = mp_init_size(&q, a->used)) != MP_OKAY) {
        return err;
     }
  
     q.used = a->used;
     q.sign = a->sign;
     w = 0;
     for (ix = a->used - 1; ix >= 0; ix--) {
        w = (w << (mp_word)MP_DIGIT_BIT) | (mp_word)a->dp[ix];
  
        if (w >= b) {
           t = (mp_digit)(w / b);
           w -= (mp_word)t * (mp_word)b;
        } else {
           t = 0;
        }
        q.dp[ix] = t;
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
  
  void mp_exch(mp_int *a, mp_int *b)
  {
     mp_int  t;
  
     t  = *a;
     *a = *b;
     *b = t;
  }
  mp_err mp_expt_n(const mp_int *a, int b, mp_int *c)
  {
     mp_err err;
     mp_int  g;
  
     if ((err = mp_init_copy(&g, a)) != MP_OKAY) {
        return err;
     }
  
     /* set initial result */
     mp_set(c, 1uL);
  
     while (b > 0) {
        /* if the bit is set multiply */
        if ((b & 1) != 0) {
           if ((err = mp_mul(c, &g, c)) != MP_OKAY) {
              goto LBL_ERR;
           }
        }
  
        /* square */
        if (b > 1) {
           if ((err = mp_sqr(&g, &g)) != MP_OKAY) {
              goto LBL_ERR;
           }
        }
  
        /* shift to next bit */
        b >>= 1;
     }
  
  LBL_ERR:
     mp_clear(&g);
     return err;
  }
  
  double mp_get_double(const mp_int *a)
  {
     int i;
     double d = 0.0, fac = 1.0;
     for (i = 0; i < MP_DIGIT_BIT; ++i) {
        fac *= 2.0;
     }
     for (i = a->used; i --> 0;) {
        d = (d * fac) + (double)a->dp[i];
     }
     return (a->sign == MP_NEG) ? -d : d;
  }
  mp_err mp_incr(mp_int *a)
  {
     if (MP_IS_ZERO(a)) {
        mp_set(a,1uL);
        return MP_OKAY;
     } else if (a->sign == MP_NEG) {
        mp_err err;
        a->sign = MP_ZPOS;
        if ((err = mp_decr(a)) != MP_OKAY) {
           return err;
        }
        /* There is no -0 in LTM */
        if (!MP_IS_ZERO(a)) {
           a->sign = MP_NEG;
        }
        return MP_OKAY;
     } else if (a->dp[0] < MP_DIGIT_MAX) {
        a->dp[0]++;
        return MP_OKAY;
     } else {
        return mp_add_d(a, 1uL,a);
     }
  }
  mp_err mp_log_n(const mp_int *a, int base, int *c)
  {
     if (mp_isneg(a) || mp_iszero(a) || (base < 2) || (unsigned)base > (unsigned)MP_DIGIT_MAX) {
        return MP_VAL;
     }
  
     if (MP_HAS(S_MP_LOG_2EXPT) && MP_IS_2EXPT((mp_digit)base)) {
        *c = s_mp_log_2expt(a, (mp_digit)base);
        return MP_OKAY;
     }
  
     if (MP_HAS(S_MP_LOG_D) && (a->used == 1)) {
        *c = s_mp_log_d((mp_digit)base, a->dp[0]);
        return MP_OKAY;
     }
  
     if (MP_HAS(S_MP_LOG)) {
        return s_mp_log(a, (mp_digit)base, c);
     }
  
     return MP_VAL;
  }
  
  mp_err mp_lshd(mp_int *a, int b)
  {
     int x;
     mp_err err;
  
     /* if its less than zero return */
     if (b <= 0) {
        return MP_OKAY;
     }
     /* no need to shift 0 around */
     if (MP_IS_ZERO(a)) {
        return MP_OKAY;
     }
  
     /* grow to fit the new digits */
     if (a->alloc < (a->used + b)) {
        if ((err = mp_grow(a, a->used + b)) != MP_OKAY) {
           return err;
        }
     }
  
     /* increment the used by the shift amount then copy upwards */
     a->used += b;
  
     /* top */
     mp_digit_iter top = mp_int_get_miter(a) + a->used - 1;
  
     /* base */
     mp_digit_iter bottom = (mp_int_get_miter(a) + a->used - 1) - b;
  
     /* much like mp_rshd this is implemented using a sliding window
      * except the window goes the otherway around.  Copying from
      * the bottom to the top.  see bn_mp_rshd.c for more info.
      */
     for (x = a->used - 1; x >= b; x--) {
        *top-- = *bottom--;
     }
  
     /* zero the lower digits */
     MP_ZERO_DIGITS(mp_int_get_miter(a), b);
  
     return MP_OKAY;
  }
  mp_err mp_mod(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_int  t;
     mp_err  err;
  
     if ((err = mp_init_size(&t, b->used)) != MP_OKAY) {
        return err;
     }
  
     if ((err = mp_div(a, b, NULL, &t)) != MP_OKAY) {
        goto LBL_ERR;
     }
  
     if (MP_IS_ZERO(&t) || (t.sign == b->sign)) {
        err = MP_OKAY;
        mp_exch(&t, c);
     } else {
        err = mp_add(b, &t, c);
     }
  
  LBL_ERR:
     mp_clear(&t);
     return err;
  }
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
     if (b >= (a->used * MP_DIGIT_BIT)) {
        return mp_copy(a, c);
     }
  
     /* copy */
     if ((err = mp_copy(a, c)) != MP_OKAY) {
        return err;
     }
  
     /* zero digits above the last digit of the modulus */
     x = (b / MP_DIGIT_BIT) + (((b % MP_DIGIT_BIT) == 0) ? 0 : 1);
     MP_ZERO_DIGITS(mp_int_get_miter(c) + x, c->used - x);
  
     /* clear the digit that is not completely outside/inside the modulus */
     c->dp[b / MP_DIGIT_BIT] &=
        ((mp_digit)1 << (mp_digit)(b % MP_DIGIT_BIT)) - (mp_digit)1;
     mp_clamp(c);
     return MP_OKAY;
  }
  mp_err mp_mod_d(const mp_int *a, mp_digit b, mp_digit *c)
  {
     return mp_div_d(a, b, NULL, c);
  }
  mp_err mp_mul(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_err err;
     int min_len = MP_MIN(a->used, b->used),
         max_len = MP_MAX(a->used, b->used),
         digs = a->used + b->used + 1;
     mp_sign neg = (a->sign == b->sign) ? MP_ZPOS : MP_NEG;
  
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
     c->sign = (c->used > 0) ? neg : MP_ZPOS;
     return err;
  }
  mp_err mp_mul_2(const mp_int *a, mp_int *b)
  {
     int     x, oldused;
     mp_err err;
  
     /* grow to accomodate result */
     if (b->alloc < (a->used + 1)) {
        if ((err = mp_grow(b, a->used + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     oldused = b->used;
     b->used = a->used;
  
     {
       mp_digit r, rr;
  
        /* alias for source */
        mp_digit_const_iter tmpa = mp_int_get_citer(a);
  
        /* alias for dest */
        mp_digit_iter tmpb = mp_int_get_miter(b);
  
        /* carry */
        r = 0;
        for (x = 0; x < a->used; x++) {
  
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
           ++(b->used);
        }
  
        /* now zero any excess digits on the destination
         * that we didn't write to
         */
        MP_ZERO_DIGITS(mp_int_get_miter(b) + b->used, oldused - b->used);
     }
     b->sign = a->sign;
     return MP_OKAY;
  }
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
  
     if (c->alloc < (c->used + (b / MP_DIGIT_BIT) + 1)) {
        if ((err = mp_grow(c, c->used + (b / MP_DIGIT_BIT) + 1)) != MP_OKAY) {
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
        mp_digit shift, mask, r, rr;
        int x;
  
        /* bitmask for carries */
        mask = ((mp_digit)1 << d) - (mp_digit)1;
  
        /* shift for msbs */
        shift = (mp_digit)MP_DIGIT_BIT - d;
  
        /* alias */
        mp_digit_iter tmpc = mp_int_get_miter(c);
  
        /* carry */
        r    = 0;
        for (x = 0; x < c->used; x++) {
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
           c->dp[(c->used)++] = r;
        }
     }
     mp_clamp(c);
     return MP_OKAY;
  }
  mp_err mp_mul_d(const mp_int *a, mp_digit b, mp_int *c)
  {
     mp_digit u;
     mp_word  r;
     mp_err   err;
     int      ix, olduse;
  
     /* make sure c is big enough to hold a*b */
     if (c->alloc < (a->used + 1)) {
        if ((err = mp_grow(c, a->used + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* get the original destinations used count */
     olduse = c->used;
  
     /* set the sign */
     c->sign = a->sign;
  
     /* alias for a->dp [source] */
     mp_digit_const_iter tmpa = mp_int_get_citer(a);
  
     /* alias for c->dp [dest] */
     mp_digit_iter tmpc = mp_int_get_miter(c);
  
     /* zero carry */
     u = 0;
  
     /* compute columns */
     for (ix = 0; ix < a->used; ix++) {
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
     c->used = a->used + 1;
     mp_clamp(c);
  
     return MP_OKAY;
  }
  mp_err mp_neg(const mp_int *a, mp_int *b)
  {
     mp_err err;
     if (a != b) {
        if ((err = mp_copy(a, b)) != MP_OKAY) {
           return err;
        }
     }
  
     if (!MP_IS_ZERO(b)) {
        b->sign = (a->sign == MP_ZPOS) ? MP_NEG : MP_ZPOS;
     } else {
        b->sign = MP_ZPOS;
     }
  
     return MP_OKAY;
  }
  mp_err mp_or(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int used = MP_MAX(a->used, b->used) + 1, i;
     mp_err err;
     mp_digit ac = 1, bc = 1, cc = 1;
     mp_sign csign = ((a->sign == MP_NEG) || (b->sign == MP_NEG)) ? MP_NEG : MP_ZPOS;
  
     if (c->alloc < used) {
        if ((err = mp_grow(c, used)) != MP_OKAY) {
           return err;
        }
     }
  
     for (i = 0; i < used; i++) {
        mp_digit x, y;
  
        /* convert to two complement if negative */
        if (a->sign == MP_NEG) {
           ac += (i >= a->used) ? MP_MASK : (~a->dp[i] & MP_MASK);
           x = ac & MP_MASK;
           ac >>= MP_DIGIT_BIT;
        } else {
           x = (i >= a->used) ? 0uL : a->dp[i];
        }
  
        /* convert to two complement if negative */
        if (b->sign == MP_NEG) {
           bc += (i >= b->used) ? MP_MASK : (~b->dp[i] & MP_MASK);
           y = bc & MP_MASK;
           bc >>= MP_DIGIT_BIT;
        } else {
           y = (i >= b->used) ? 0uL : b->dp[i];
        }
  
        c->dp[i] = x | y;
  
        /* convert to to sign-magnitude if negative */
        if (csign == MP_NEG) {
           cc += ~c->dp[i] & MP_MASK;
           c->dp[i] = cc & MP_MASK;
           cc >>= MP_DIGIT_BIT;
        }
     }
  
     c->used = used;
     c->sign = csign;
     mp_clamp(c);
     return MP_OKAY;
  }
  void mp_rshd(mp_int *a, int b)
  {
     int     x;
  
     /* if b <= 0 then ignore it */
     if (b <= 0) {
        return;
     }
  
     /* if b > used then simply zero it and return */
     if (a->used <= b) {
        mp_zero(a);
        return;
     }
  
     /* shift the digits down */
  
     /* bottom */
     mp_digit_iter bottom = mp_int_get_miter(a);
  
     /* top [offset into digits] */
     mp_digit_iter top = mp_int_get_miter(a) + b;
  
     /* this is implemented as a sliding window where
      * the window is b-digits long and digits from
      * the top of the window are copied to the bottom
      *
      * e.g.
  
      b-2 | b-1 | b0 | b1 | b2 | ... | bb |   ---->
                  /\                   |      ---->
                   \-------------------/      ---->
      */
     for (x = 0; x < (a->used - b); x++) {
        *bottom++ = *top++;
     }
  
     /* zero the top digits */
     MP_ZERO_DIGITS(bottom, a->used - x);
  
     /* remove excess digits */
     a->used -= b;
  }
  void mp_set(mp_int *a, mp_digit b)
  {
     a->dp[0] = b & MP_MASK;
     a->sign  = MP_ZPOS;
     a->used  = (a->dp[0] != 0u) ? 1 : 0;
     MP_ZERO_DIGITS(mp_int_get_miter(a) + a->used, a->alloc - a->used);
  }
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
        a->sign = MP_NEG;
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
  MP_SET_UNSIGNED(mp_set_u64, uint64_t)
  mp_err mp_signed_rsh(const mp_int *a, int b, mp_int *c)
  {
     mp_err res;
     if (a->sign == MP_ZPOS) {
        return mp_div_2d(a, b, c, NULL);
     }
  
     res = mp_add_d(a, 1uL, c);
     if (res != MP_OKAY) {
        return res;
     }
  
     res = mp_div_2d(c, b, c, NULL);
     return (res == MP_OKAY) ? mp_sub_d(c, 1uL, c) : res;
  }
  mp_err mp_sqr(const mp_int *a, mp_int *b)
  {
     mp_err err;
  #if 0
     if (MP_HAS(S_MP_TOOM_SQR) && /* use Toom-Cook? */
         (a->used >= MP_TOOM_SQR_CUTOFF)) {
        err = s_mp_toom_sqr(a, b);
     }
  #else
     if (0) {}
  #endif
  #if 0
     else if (MP_HAS(S_MP_KARATSUBA_SQR) &&  /* Karatsuba? */
                (a->used >= MP_KARATSUBA_SQR_CUTOFF)) {
        err = s_mp_karatsuba_sqr(a, b);
     }
  #endif
  #if 0
     else if (MP_HAS(S_MP_SQR_FAST) && /* can we use the fast comba multiplier? */
                (((a->used * 2) + 1) < MP_WARRAY) &&
                (a->used < (MP_MAXFAST / 2))) {
        err = s_mp_sqr_fast(a, b);
     }
  #endif
     else if (MP_HAS(S_MP_SQR)) {
        err = s_mp_sqr(a, b);
     } else {
        err = MP_VAL;
     }
     b->sign = MP_ZPOS;
     return err;
  }
  mp_err mp_sqrt(const mp_int *arg, mp_int *ret)
  {
     mp_err err;
     mp_int t1, t2;
  
     /* must be positive */
     if (arg->sign == MP_NEG) {
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
     mp_rshd(&t1, t1.used/2);
  
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
  
  mp_err mp_sub(const mp_int *a, const mp_int *b, mp_int *c)
  {
     mp_sign sa = a->sign, sb = b->sign;
     mp_err err;
  
     if (sa != sb) {
        /* subtract a negative from a positive, OR */
        /* subtract a positive from a negative. */
        /* In either case, ADD their magnitudes, */
        /* and use the sign of the first number. */
        c->sign = sa;
        err = s_mp_add(a, b, c);
     } else {
        /* subtract a positive from a positive, OR */
        /* subtract a negative from a negative. */
        /* First, take the difference between their */
        /* magnitudes, then... */
        if (mp_cmp_mag(a, b) != MP_LT) {
           /* Copy the sign from the first */
           c->sign = sa;
           /* The first has a larger or equal magnitude */
           err = s_mp_sub(a, b, c);
        } else {
           /* The result has the *opposite* sign from */
           /* the first number. */
           c->sign = (sa == MP_ZPOS) ? MP_NEG : MP_ZPOS;
           /* The second has a larger magnitude */
           err = s_mp_sub(b, a, c);
        }
     }
     return err;
  }
  
  mp_err mp_sub_d(const mp_int *a, mp_digit b, mp_int *c)
  {
     mp_err    err;
     int       ix, oldused;
  
     /* grow c as required */
     if (c->alloc < (a->used + 1)) {
        if ((err = mp_grow(c, a->used + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* if a is negative just do an unsigned
      * addition [with fudged signs]
      */
     if (a->sign == MP_NEG) {
        mp_int a_ = *a;
        a_.sign = MP_ZPOS;
        err     = mp_add_d(&a_, b, c);
        c->sign = MP_NEG;
  
        /* clamp */
        mp_clamp(c);
  
        return err;
     }
  
     /* setup regs */
     oldused = c->used;
     mp_digit_const_iter tmpa    = mp_int_get_citer(a);
     mp_digit_iter tmpc    = mp_int_get_miter(c);
  
     /* if a <= b simply fix the single digit */
     if (((a->used == 1) && (a->dp[0] <= b)) || (a->used == 0)) {
        if (a->used == 1) {
           *tmpc++ = b - *tmpa;
        } else {
           *tmpc++ = b;
        }
        ix      = 1;
  
        /* negative/1digit */
        c->sign = MP_NEG;
        c->used = 1;
     } else {
        mp_digit mu = b;
  
        /* positive/size */
        c->sign = MP_ZPOS;
        c->used = a->used;
  
        /* subtract digits, mu is carry */
        for (ix = 0; ix < a->used; ix++) {
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
  
  mp_err mp_xor(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int used = MP_MAX(a->used, b->used) + 1, i;
     mp_err err;
     mp_digit ac = 1, bc = 1, cc = 1;
     mp_sign csign = (a->sign != b->sign) ? MP_NEG : MP_ZPOS;
  
     if (c->alloc < used) {
        if ((err = mp_grow(c, used)) != MP_OKAY) {
           return err;
        }
     }
  
     for (i = 0; i < used; i++) {
        mp_digit x, y;
  
        /* convert to two complement if negative */
        if (a->sign == MP_NEG) {
           ac += (i >= a->used) ? MP_MASK : (~a->dp[i] & MP_MASK);
           x = ac & MP_MASK;
           ac >>= MP_DIGIT_BIT;
        } else {
           x = (i >= a->used) ? 0uL : a->dp[i];
        }
  
        /* convert to two complement if negative */
        if (b->sign == MP_NEG) {
           bc += (i >= b->used) ? MP_MASK : (~b->dp[i] & MP_MASK);
           y = bc & MP_MASK;
           bc >>= MP_DIGIT_BIT;
        } else {
           y = (i >= b->used) ? 0uL : b->dp[i];
        }
  
        c->dp[i] = x ^ y;
  
        /* convert to to sign-magnitude if negative */
        if (csign == MP_NEG) {
           cc += ~c->dp[i] & MP_MASK;
           c->dp[i] = cc & MP_MASK;
           cc >>= MP_DIGIT_BIT;
        }
     }
  
     c->used = used;
     c->sign = csign;
     mp_clamp(c);
     return MP_OKAY;
  }
  void mp_zero(mp_int *a)
  {
     a->sign = MP_ZPOS;
     a->used = 0;
     MP_ZERO_DIGITS(mp_int_get_miter(a), a->alloc);
  }
private:
  mp_err s_mp_add(const mp_int *a, const mp_int *b, mp_int *c)
  {
     const mp_int *x;
     mp_err err;
     int     olduse, min, max;
  
     /* find sizes, we let |a| <= |b| which means we have to sort
      * them.  "x" will point to the input with the most digits
      */
     if (a->used > b->used) {
        min = b->used;
        max = a->used;
        x = a;
     } else {
        min = a->used;
        max = b->used;
        x = b;
     }
  
     /* init result */
     if (c->alloc < (max + 1)) {
        if ((err = mp_grow(c, max + 1)) != MP_OKAY) {
           return err;
        }
     }
  
     /* get old used digit count and set new one */
     olduse = c->used;
     c->used = max + 1;
  
     {
        mp_digit u;
        int i;
  
        /* alias for digit pointers */
  
        /* first input */
        mp_digit_const_iter tmpa = mp_int_get_citer(a);
  
        /* second input */
        mp_digit_const_iter tmpb = mp_int_get_citer(b);
  
        /* destination */
        mp_digit_iter tmpc = mp_int_get_miter(c);
  
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
              *tmpc = x->dp[i] + u;
  
              /* U = carry bit of T[i] */
              u = *tmpc >> (mp_digit)MP_DIGIT_BIT;
  
              /* take away carry bit from T[i] */
              *tmpc++ &= MP_MASK;
           }
        }
  
        /* add carry */
        *tmpc++ = u;
  
        /* clear digits above oldused */
        MP_ZERO_DIGITS(tmpc, olduse - c->used);
     }
  
     mp_clamp(c);
     return MP_OKAY;
  }
  mp_err s_mp_balance_mul(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int count, len_a, len_b, nblocks, i, j, bsize;
     mp_int a0, tmp, A, B, r;
     mp_err err;
  
     len_a = a->used;
     len_b = b->used;
  
     nblocks = MP_MAX(a->used, b->used) / MP_MIN(a->used, b->used);
     bsize = MP_MIN(a->used, b->used) ;
  
     if ((err = mp_init_size(&a0, bsize + 2)) != MP_OKAY) {
        return err;
     }
     if ((err = mp_init_multi(&tmp, &r, NULL)) != MP_OKAY) {
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
        a0.used = 0;
        for (count = 0; count < bsize; count++) {
           a0.dp[count] = A.dp[ j++ ];
           a0.used++;
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
     if (j < A.used) {
        a0.used = 0;
        for (count = 0; j < A.used; count++) {
           a0.dp[count] = A.dp[ j++ ];
           a0.used++;
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
     mp_clear_multi(&a0, &tmp, &r,NULL);
     return err;
  }
  mp_err s_mp_div_3(const mp_int *a, mp_int *c, mp_digit *d)
  {
     mp_int   q;
     mp_word  w, t;
     mp_digit b;
     mp_err   err;
     int      ix;
  
     /* b = 2**MP_DIGIT_BIT / 3 */
     b = ((mp_word)1 << (mp_word)MP_DIGIT_BIT) / (mp_word)3;
  
     if ((err = mp_init_size(&q, a->used)) != MP_OKAY) {
        return err;
     }
  
     q.used = a->used;
     q.sign = a->sign;
     w = 0;
     for (ix = a->used - 1; ix >= 0; ix--) {
        w = (w << (mp_word)MP_DIGIT_BIT) | (mp_word)a->dp[ix];
  
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
        q.dp[ix] = (mp_digit)t;
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
  
  mp_err s_mp_log(const mp_int *a, mp_digit base, int *c)
  {
     mp_err err;
     int high, low;
     mp_int bracket_low, bracket_high, bracket_mid, t, bi_base;
  
     mp_ord cmp = mp_cmp_d(a, base);
     if ((cmp == MP_LT) || (cmp == MP_EQ)) {
        *c = cmp == MP_EQ;
        return MP_OKAY;
     }
  
     if ((err =
             mp_init_multi(&bracket_low, &bracket_high,
                           &bracket_mid, &t, &bi_base, NULL)) != MP_OKAY) {
        return err;
     }
  
     low = 0;
     mp_set(&bracket_low, 1uL);
     high = 1;
  
     mp_set(&bracket_high, base);
  
     /*
         A kind of Giant-step/baby-step algorithm.
         Idea shamelessly stolen from https://programmingpraxis.com/2010/05/07/integer-logarithms/2/
         The effect is asymptotic, hence needs benchmarks to test if the Giant-step should be skipped
         for small n.
      */
     while (mp_cmp(&bracket_high, a) == MP_LT) {
        low = high;
        if ((err = mp_copy(&bracket_high, &bracket_low)) != MP_OKAY) {
           goto LBL_END;
        }
        high <<= 1;
        if ((err = mp_sqr(&bracket_high, &bracket_high)) != MP_OKAY) {
           goto LBL_END;
        }
     }
     mp_set(&bi_base, base);
  
     while ((high - low) > 1) {
        int mid = (high + low) >> 1;
  
        if ((err = mp_expt_n(&bi_base, mid - low, &t)) != MP_OKAY) {
           goto LBL_END;
        }
        if ((err = mp_mul(&bracket_low, &t, &bracket_mid)) != MP_OKAY) {
           goto LBL_END;
        }
        cmp = mp_cmp(a, &bracket_mid);
        if (cmp == MP_LT) {
           high = mid;
           mp_exch(&bracket_mid, &bracket_high);
        }
        if (cmp == MP_GT) {
           low = mid;
           mp_exch(&bracket_mid, &bracket_low);
        }
        if (cmp == MP_EQ) {
           *c = mid;
           goto LBL_END;
        }
     }
  
     *c = (mp_cmp(&bracket_high, a) == MP_EQ) ? high : low;
  
  LBL_END:
     mp_clear_multi(&bracket_low, &bracket_high, &bracket_mid,
                    &t, &bi_base, NULL);
     return err;
  }
  
  int s_mp_log_2expt(const mp_int *a, mp_digit base)
  {
     int y;
     for (y = 0; (base & 1) == 0; y++, base >>= 1) {}
     return (mp_count_bits(a) - 1) / y;
  }
  static mp_word s_pow(mp_word base, mp_word exponent)
  {
     mp_word result = 1u;
     while (exponent != 0u) {
        if ((exponent & 1u) == 1u) {
           result *= base;
        }
        exponent >>= 1;
        base *= base;
     }
  
     return result;
  }
  
  int s_mp_log_d(mp_digit base, mp_digit n)
  {
     mp_word bracket_low = 1uLL, bracket_high = base, N = n;
     int ret, high = 1, low = 0;
  
     if (n < base) {
        return 0;
     }
     if (n == base) {
        return 1;
     }
  
     while (bracket_high < N) {
        low = high;
        bracket_low = bracket_high;
        high <<= 1;
        bracket_high *= bracket_high;
     }
  
     while (((mp_digit)(high - low)) > 1uL) {
        int mid = (low + high) >> 1;
        mp_word bracket_mid = bracket_low * s_pow(base, (mp_word)(mid - low));
  
        if (N < bracket_mid) {
           high = mid ;
           bracket_high = bracket_mid ;
        }
        if (N > bracket_mid) {
           low = mid ;
           bracket_low = bracket_mid ;
        }
        if (N == bracket_mid) {
           return mid;
        }
     }
  
     if (bracket_high == N) {
        ret = high;
     } else {
        ret = low;
     }
  
     return ret;
  }
  
  mp_err s_mp_mul_digs(const mp_int *a, const mp_int *b, mp_int *c, int digs)
  {
     mp_int  t;
     mp_err  err;
     int     pa, pb, ix, iy;
     mp_digit u;
     mp_word r;
     mp_digit tmpx;
  
     if (digs < 0) {
        return MP_VAL;
     }
  
     /* can we use the fast multiplier? */
     if ((digs < MP_WARRAY) &&
         (MP_MIN(a->used, b->used) < MP_MAXFAST)) {
        return s_mp_mul_digs_fast(a, b, c, digs);
     }
  
     if ((err = mp_init_size(&t, digs)) != MP_OKAY) {
        return err;
     }
     t.used = digs;
  
     /* compute the digits of the product directly */
     pa = a->used;
     for (ix = 0; ix < pa; ix++) {
        /* set the carry to zero */
        u = 0;
  
        /* limit ourselves to making digs digits of output */
        pb = MP_MIN(b->used, digs - ix);
  
        /* setup some aliases */
        /* copy of the digit from a used within the nested loop */
        tmpx = a->dp[ix];
        
        /* an alias for the destination shifted ix places */
        mp_digit_iter tmpt = mp_int_get_miter(&t) + ix;
  
        
        /* an alias for the digits of b */
        mp_digit_const_iter tmpy = mp_int_get_citer(b);
  
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
     if (c->alloc < digs) {
        if ((err = mp_grow(c, digs)) != MP_OKAY) {
           return err;
        }
     }
  
     /* number of output digits to produce */
     pa = MP_MIN(digs, a->used + b->used);
  
     /* clear the carry */
     _W = 0;
     for (ix = 0; ix < pa; ix++) {
        int      tx, ty;
        int      iy;
  
        /* get offsets into the two bignums */
        ty = MP_MIN(b->used-1, ix);
        tx = ix - ty;
  
        /* setup temp aliases */
        mp_digit_const_iter tmpx = mp_int_get_citer(a) + tx;
        mp_digit_const_iter tmpy = mp_int_get_citer(b) + ty;
  
        /* this is the number of times the loop will iterrate, essentially
           while (tx++ < a->used && ty-- >= 0) { ... }
         */
        iy = MP_MIN(a->used-tx, ty+1);
  
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
     olduse  = c->used;
     c->used = pa;
  
     {
       mp_digit_iter tmpc = mp_int_get_miter(c);
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
  mp_err s_mp_sqr(const mp_int *a, mp_int *b)
  {
     mp_int   t;
     int      ix, iy, pa;
     mp_err   err;
     mp_word  r;
     mp_digit u, tmpx;
  
     pa = a->used;
     if ((err = mp_init_size(&t, (2 * pa) + 1)) != MP_OKAY) {
        return err;
     }
  
     /* default used is maximum possible size */
     t.used = (2 * pa) + 1;
  
     for (ix = 0; ix < pa; ix++) {
        /* first calculate the digit at 2*ix */
        /* calculate double precision result */
        r = (mp_word)t.dp[2*ix] +
            ((mp_word)a->dp[ix] * (mp_word)a->dp[ix]);
  
        /* store lower part in result */
        t.dp[ix+ix] = (mp_digit)(r & (mp_word)MP_MASK);
  
        /* get the carry */
        u           = (mp_digit)(r >> (mp_word)MP_DIGIT_BIT);
  
        /* left hand side of A[ix] * A[iy] */
        tmpx        = a->dp[ix];
  
        /* alias for where to store the results */
        mp_digit_iter tmpt        = mp_int_get_miter(&t) + ((2 * ix) + 1);
  
        for (iy = ix + 1; iy < pa; iy++) {
           /* first calculate the product */
           r       = (mp_word)tmpx * (mp_word)a->dp[iy];
  
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
  mp_err s_mp_sqr_fast(const mp_int *a, mp_int *b)
  {
     int       olduse, pa, ix, iz;
     mp_digit  W[MP_WARRAY];
     mp_word   W1;
     mp_err    err;
  
     /* grow the destination as required */
     pa = a->used + a->used;
     if (b->alloc < pa) {
        if ((err = mp_grow(b, pa)) != MP_OKAY) {
           return err;
        }
     }
  
     /* number of output digits to produce */
     W1 = 0;
     for (ix = 0; ix < pa; ix++) {
        int      tx, ty, iy;
        mp_word  _W;
  
        /* clear counter */
        _W = 0;
  
        /* get offsets into the two bignums */
        ty = MP_MIN(a->used-1, ix);
        tx = ix - ty;
  
        /* setup temp aliases */
        mp_digit_const_iter tmpx = mp_int_get_citer(a) + tx;
        mp_digit_const_iter tmpy = mp_int_get_citer(a) + ty;
        
        /* this is the number of times the loop will iterrate, essentially
           while (tx++ < a->used && ty-- >= 0) { ... }
         */
        iy = MP_MIN(a->used-tx, ty+1);
  
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
           _W += (mp_word)a->dp[ix>>1] * (mp_word)a->dp[ix>>1];
        }
  
        /* store it */
        W[ix] = (mp_digit)_W & MP_MASK;
  
        /* make next carry */
        W1 = _W >> (mp_word)MP_DIGIT_BIT;
     }
  
     /* setup dest */
     olduse  = b->used;
     b->used = a->used+a->used;
  
     {
       mp_digit_iter tmpb =mp_int_get_miter(b);
        for (ix = 0; ix < pa; ix++) {
           *tmpb++ = W[ix] & MP_MASK;
        }
  
        /* clear unused digits [that existed in the old copy of c] */
        MP_ZERO_DIGITS(tmpb, olduse - ix);
     }
     mp_clamp(b);
     return MP_OKAY;
  }
  mp_err s_mp_sub(const mp_int *a, const mp_int *b, mp_int *c)
  {
     int    olduse, min, max;
     mp_err err;
  
     /* find sizes */
     min = b->used;
     max = a->used;
  
     /* init result */
     if (c->alloc < max) {
        if ((err = mp_grow(c, max)) != MP_OKAY) {
           return err;
        }
     }
     olduse = c->used;
     c->used = max;
  
     {
       mp_digit u;
        int i;
  
        /* alias for digit pointers */
        mp_digit_const_iter     tmpa = mp_int_get_citer(a);
        mp_digit_const_iter     tmpb = mp_int_get_citer(b);
        mp_digit_iter     tmpc = mp_int_get_miter(c);
  
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
        MP_ZERO_DIGITS(tmpc, olduse - c->used);
     }
  
     mp_clamp(c);
     return MP_OKAY;
  }
  

};

#endif // BIGINT_TOMMATH_HPP_INCLUDED
