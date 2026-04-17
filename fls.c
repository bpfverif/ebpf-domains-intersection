#include "types.h"

#define BITS_PER_LONG 64

static u32 generic___fls___(u64 word)
{
	u32 num = BITS_PER_LONG - 1;

#if BITS_PER_LONG == 64
	if (!(word & (~0ul << 32))) {
		num -= 32;
		word <<= 32;
	}
#endif
	if (!(word & (~0ul << (BITS_PER_LONG-16)))) {
		num -= 16;
		word <<= 16;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-8)))) {
		num -= 8;
		word <<= 8;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-4)))) {
		num -= 4;
		word <<= 4;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-2)))) {
		num -= 2;
		word <<= 2;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-1))))
		num -= 1;
	return num;
}

#define __fls___(word) generic___fls___(word)

#if BITS_PER_LONG == 32
static int fls64___(u64 x)
{
	__u32 h = x >> 32;
	if (h)
		return fls___(h) + 32;
	return fls___(x);
}
#elif BITS_PER_LONG == 64
static int fls64___(u64 x)
{
	if (x == 0)
		return 0;
	return __fls___(x) + 1;
}
#endif
