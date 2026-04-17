#include "tnum.h"
#include "fls.c"


#define TNUM(_v, _m)	(struct tnum){.value = _v, .mask = _m}


struct tnum tnum_cast(struct tnum a, u8 size)
{
	a.value &= (1ULL << (size * 8)) - 1;
	a.mask &= (1ULL << (size * 8)) - 1;
	return a;
}


struct tnum tnum_subreg(struct tnum a)
{
	return tnum_cast(a, 4);
}


u64 tnum_step(struct tnum t, u64 z)
{
	u64 tmax, d, carry_mask, filled, inc;

	tmax = t.value | t.mask;

	/* if z >= largest member of t, return largest member of t */
	if (z >= tmax)
		return tmax;

	/* if z < smallest member of t, return smallest member of t */
	if (z < t.value)
		return t.value;

	d = z - t.value;
	carry_mask = (1ULL << fls64___(d & ~t.mask)) - 1;
	filled = d | carry_mask | ~t.mask;
	inc = (filled + 1) & t.mask;
	return t.value | inc;
}
