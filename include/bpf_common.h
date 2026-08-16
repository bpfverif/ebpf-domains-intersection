#ifndef BPF_COMMON_H
#define BPF_COMMON_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint64_t u64;
typedef int64_t  s64;
typedef uint32_t u32;
typedef int32_t  s32;

#define U8_MAX		((u8)~0U)
#define S8_MAX		((s8)(U8_MAX >> 1))
#define S8_MIN		((s8)(-S8_MAX - 1))
#define U16_MAX		((u16)~0U)
#define S16_MAX		((s16)(U16_MAX >> 1))
#define S16_MIN		((s16)(-S16_MAX - 1))
#define U32_MAX		((u32)~0U)
#define U32_MIN		((u32)0)
#define S32_MAX		((s32)(U32_MAX >> 1))
#define S32_MIN		((s32)(-S32_MAX - 1))
#define U64_MAX		((u64)~0ULL)
#define S64_MAX		((s64)(U64_MAX >> 1))
#define S64_MIN		((s64)(-S64_MAX - 1))


/* Indirect macros required for expanded argument pasting, eg. __LINE__. */
#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)

#define __typecheck(x, y) \
	(!!(sizeof((typeof(x) *)1 == (typeof(y) *)1)))

#define __is_constexpr(x) \
	(sizeof(int) == sizeof(*(8 ? ((void *)((long)(x) * 0l)) : (int *)8)))

#define __no_side_effects(x, y) \
		(__is_constexpr(x) && __is_constexpr(y))

#define __safe_cmp(x, y) \
		(__typecheck(x, y) && __no_side_effects(x, y))

#define __cmp(x, y, op)	((x) op (y) ? (x) : (y))

#define __cmp_once(x, y, unique_x, unique_y, op) ({	\
		typeof(x) unique_x = (x);		\
		typeof(y) unique_y = (y);		\
		__cmp(unique_x, unique_y, op); })

#define __careful_cmp(x, y, op) \
	__builtin_choose_expr(__safe_cmp(x, y), \
		__cmp(x, y, op), \
		__cmp_once(x, y, __UNIQUE_ID(__x), __UNIQUE_ID(__y), op))

#define min_t(type, x, y)	__careful_cmp((type)(x), (type)(y), <)
#define max_t(type, x, y)	__careful_cmp((type)(x), (type)(y), >)

#define min(x, y)	__careful_cmp(x, y, <)

/**
 * max - return maximum of two values of the same or compatible types
 * @x: first value
 * @y: second value
 */
#define max(x, y)	__careful_cmp(x, y, >)


/* ---------- tnum (from include/linux/tnum.h, kernel/bpf/tnum.c) ---------- */

struct tnum {
	u64 value;
	u64 mask;
};

#define TNUM(_v, _m)	((struct tnum){.value = (_v), .mask = (_m)})

/* fls64: find last (most significant) set bit, 1-indexed; returns 0 if v==0 */
static inline int fls64(u64 v)
{
	int r = 0;

	if (!v)
		return 0;
	if (v & 0xFFFFFFFF00000000ULL) { r += 32; v >>= 32; }
	if (v & 0x00000000FFFF0000ULL) { r += 16; v >>= 16; }
	if (v & 0x000000000000FF00ULL) { r +=  8; v >>=  8; }
	if (v & 0x00000000000000F0ULL) { r +=  4; v >>=  4; }
	if (v & 0x000000000000000CULL) { r +=  2; v >>=  2; }
	if (v & 0x0000000000000002ULL) { r +=  1; v >>=  1; }
	return r + (int)v;
}

static inline u64 tnum_step(struct tnum t, u64 z)
{
	u64 tmax, d, carry_mask, filled, inc;

	tmax = t.value | t.mask;

	if (z >= tmax)
		return tmax;

	if (z < t.value)
		return t.value;

	d = z - t.value;
	carry_mask = (1ULL << fls64(d & ~t.mask)) - 1;
	filled = d | carry_mask | ~t.mask;
	inc = (filled + 1) & t.mask;
	return t.value | inc;
}

static inline bool tnum_contains(struct tnum t, u64 v)
{
	return (v & ~t.mask) == t.value;
}

static inline struct tnum tnum_cast(struct tnum a, u8 size)
{
	a.value &= (1ULL << (size * 8)) - 1;
	a.mask &= (1ULL << (size * 8)) - 1;
	return a;
}

static inline struct tnum tnum_subreg(struct tnum a)
{
	return tnum_cast(a, 4);
}


/* ---------- bpf_reg_state (subset from include/linux/bpf_verifier.h) ----- */

struct bpf_reg_state {
	s64 smin_value;
	s64 smax_value;
	u64 umin_value;
	u64 umax_value;
	s32 s32_min_value;
	s32 s32_max_value;
	u32 u32_min_value;
	u32 u32_max_value;
	struct tnum var_off;
};

#define UPPER_HALF 0xffffFFFF00000000ull


#endif /*BPF_VERIFIER_H*/