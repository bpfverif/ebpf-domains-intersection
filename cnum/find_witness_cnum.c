#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;
typedef int64_t  s64;
typedef uint32_t u32;
typedef int32_t  s32;

#define min(a, b)	((a) < (b) ? (a) : (b))
#define max(a, b)	((a) > (b) ? (a) : (b))

/* ---------- tnum ---------- */

struct tnum {
	u64 value;
	u64 mask;
};

#define TNUM(_v, _m)	((struct tnum){.value = (_v), .mask = (_m)})

static int fls64(u64 v)
{
	int r = 0;
	if (!v) return 0;
	if (v & 0xFFFFFFFF00000000ULL) { r += 32; v >>= 32; }
	if (v & 0x00000000FFFF0000ULL) { r += 16; v >>= 16; }
	if (v & 0x000000000000FF00ULL) { r +=  8; v >>=  8; }
	if (v & 0x00000000000000F0ULL) { r +=  4; v >>=  4; }
	if (v & 0x000000000000000CULL) { r +=  2; v >>=  2; }
	if (v & 0x0000000000000002ULL) { r +=  1; v >>=  1; }
	return r + (int)v;
}

static u64 tnum_step(struct tnum t, u64 z)
{
	u64 tmax, d, carry_mask, filled, inc;
	tmax = t.value | t.mask;
	if (z >= tmax) return tmax;
	if (z < t.value) return t.value;
	d = z - t.value;
	carry_mask = (1ULL << fls64(d & ~t.mask)) - 1;
	filled = d | carry_mask | ~t.mask;
	inc = (filled + 1) & t.mask;
	return t.value | inc;
}

static bool tnum_contains(struct tnum t, u64 v)
{
	return (v & ~t.mask) == t.value;
}

/* ---------- cnum ---------- */

struct cnum64 {
	u64 base;
	u64 size;
};

struct cnum32 {
	u32 base;
	u32 size;
};

#define CNUM64_EMPTY ((struct cnum64){ .base = 0xFFFFFFFFFFFFFFFFULL, .size = 0xFFFFFFFFFFFFFFFFULL })
#define CNUM32_EMPTY ((struct cnum32){ .base = 0xFFFFFFFF, .size = 0xFFFFFFFF })

static inline bool cnum64_is_empty(struct cnum64 cnum)
{
	return cnum.base == 0xFFFFFFFFFFFFFFFFULL && cnum.size == 0xFFFFFFFFFFFFFFFFULL;
}

static inline bool cnum32_is_empty(struct cnum32 cnum)
{
	return cnum.base == 0xFFFFFFFF && cnum.size == 0xFFFFFFFF;
}

static bool cnum64_contains(struct cnum64 c, u64 v)
{
	return (u64)(v - c.base) <= c.size;
}

static bool cnum32_contains(struct cnum32 c, u32 v)
{
	return (u32)(v - c.base) <= c.size;
}

/* ---------- intersection logic ---------- */

#define UPPER_HALF 0xffffFFFF00000000ull


/*
 * This function takes a single contiguous 64-bit range [a_min, a_max], a single contiguous 32-bit
 * range [b_min, b_max], and a tnum constraint. Its goal is to find a concrete 64-bit value `w` that
 * simultaneously satisfies:
 *   1. a_min <= w <= a_max
 *   2. b_min <= (u32)w <= b_max
 *   3. w \in tnum
 *
 * We decompose the 64-bit range into 32-bit subspaces (left edge, full middle subspaces, and right
 * edge) to make the individual computations explicit and easy to follow. This avoids loops while
 * leveraging the separability of the tnum's high and low 32 bits.
 */
static bool find_witness_aux(u64 a_min, u64 a_max, u32 b_min, u32 b_max, struct tnum tnum, u64 *out)
{
	u64 x_hi = a_min & UPPER_HALF;
	u64 y_hi = a_max & UPPER_HALF;
	u32 l, r;
	u64 w;

	if ((tnum.value | tnum.mask) < a_min)
		return false;

	if (x_hi == y_hi) {
		l = max((u32)a_min, b_min);
		r = min((u32)a_max, b_max);
		if (l > r)
			return false;

		w = x_hi | l;
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);

		if (w <= a_max && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
		return false;
	}

	l = max((u32)a_min, b_min);
	r = b_max;
	if (l <= r) {
		w = x_hi | l;
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);
			
		if (w <= (x_hi | 0xFFFFFFFFull) && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
	}

	if (x_hi + (1ULL << 32) < y_hi) {
		w = x_hi + (1ULL << 32);
		
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);
			
		if ((u32)w < b_min)
			w = (w & UPPER_HALF) | b_min;
			
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);

		if (w < y_hi && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
	}

	l = b_min;
	r = min((u32)a_max, b_max);
	if (l <= r) {
		w = y_hi | l;
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);
			
		if (w <= a_max && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
	}

	return false;
}

/*
 * cnum64 essentially handles the intersection of u64 and s64, and a cnum32 handles the intersection
 * of the u32 and s32. The cnum64 can represent one flat u64 interval ([base, base + size]), or two
 * flat intervals if the cnum wraps around ([base, umax], [0, base + size]). The same for the
 * cnum32. So we have at most 4 pairs of combinations of flat u64 and u32 intervals. For each of
 * these combinations, we deploy find_witness_aux() to find the intersection with the tnum.
 */
static bool cnum_find_witness(struct cnum64 r64, struct cnum32 r32, struct tnum var_off, u64 *out)
{
	u64 a1_min, a1_max, a2_min, a2_max;
	u32 b1_min, b1_max, b2_min, b2_max;
	bool split64 = false, split32 = false;

	if (cnum64_is_empty(r64) || cnum32_is_empty(r32))
		return false;

	a1_min = r64.base;
	a1_max = r64.base + r64.size;
	if (a1_max < a1_min) {
		split64 = true;
		a1_max = 0xFFFFFFFFFFFFFFFFULL;
		a2_min = 0;
		a2_max = r64.base + r64.size;
	}

	b1_min = r32.base;
	b1_max = r32.base + r32.size;
	if (b1_max < b1_min) {
		split32 = true;
		b1_max = 0xFFFFFFFF;
		b2_min = 0;
		b2_max = r32.base + r32.size;
	}

	if (find_witness_aux(a1_min, a1_max, b1_min, b1_max, var_off, out)) return true;
	if (split32 && find_witness_aux(a1_min, a1_max, b2_min, b2_max, var_off, out)) return true;
	if (split64) {
		if (find_witness_aux(a2_min, a2_max, b1_min, b1_max, var_off, out)) return true;
		if (split32 && find_witness_aux(a2_min, a2_max, b2_min, b2_max, var_off, out)) return true;
	}

	return false;
}

