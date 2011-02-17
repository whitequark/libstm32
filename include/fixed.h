#ifndef _FIXED_H_
#define _FIXED_H_

typedef signed short fixed;
typedef signed int   fixed_iv;
typedef signed char  fixed_pv;

#define f_PREC	8
#define f_NOM	(1<<f_PREC)
#define f_MASK	(f_NOM - 1)

#define f(in, fr)	(((in) << f_PREC) | ((fixed)(f_NOM * (fr))))
#define f_i(v)		((fixed_pv)((v) >> f_PREC))
#define f_f(v)		((fixed_pv)(f_NOM / ((v) & f_MASK));
#define f_add(v1, v2)	((v1) + (v2))
#define f_sub(v1, v2)	((v1) - (v2))
#define f_neg(v)	f_sub(0, v)
#define f_abs(v)	(v > 0 ? v : f_neg(v))
#define f_mul(v1, v2)	((((fixed_iv)(v1))*((fixed_iv)(v2))) >> f_PREC)
#define f_div(v1, v2)	(((((fixed_iv)(v1)) << f_PREC) / ((fixed_iv)(v2)))

#endif
