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
 * find_witness_aux() - Core engine for witness construction within flattened bounds.
 *
 * This function takes a single contiguous 64-bit range [a_min, a_max], a single 
 * contiguous 32-bit range [b_min, b_max], and a tnum constraint. Its goal is to 
 * find a concrete 64-bit value `w` that simultaneously satisfies:
 *   1. a_min <= w <= a_max
 *   2. b_min <= (u32)w <= b_max
 *   3. w \in tnum
 *
 * We decompose the 64-bit range into 32-bit subspaces (left edge, full middle 
 * subspaces, and right edge) to make the individual computations explicit and easy 
 * to follow. This avoids loops while leveraging the separability of the tnum's 
 * high and low 32 bits.
 */
static bool find_witness_aux(u64 a_min, u64 a_max, u32 b_min, u32 b_max, struct tnum tnum, u64 *out)
__CPROVER_assigns(*out)
__CPROVER_ensures(
	__CPROVER_return_value ==>
		(a_min <= *out && *out <= a_max &&
		 b_min <= (u32)*out && (u32)*out <= b_max &&
		 ((*out & ~tnum.mask) == tnum.value))
)
__CPROVER_ensures(
	!__CPROVER_return_value ==>
		__CPROVER_forall { u64 v;
			!(a_min <= v && v <= a_max) ||
			!(b_min <= (u32)v && (u32)v <= b_max) ||
			!((v & ~tnum.mask) == tnum.value)
		}
)
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
 * cnum_find_witness() - Unrolls the circular numbers into flat slices.
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

/* ---------- CBMC verification -------------------------------------------- */

u64 nondet_u64(void);
s64 nondet_s64(void);
u32 nondet_u32(void);
s32 nondet_s32(void);

static bool tnum_well_formed(struct tnum t)
{
	return (t.value & t.mask) == 0;
}

struct cnum_reg_state {
	struct cnum64 r64;
	struct cnum32 r32;
	struct tnum var_off;
};

static struct cnum_reg_state mk_cnum_reg(void)
{
	return (struct cnum_reg_state) {
		.r64 = { .base = nondet_u64(), .size = nondet_u64() },
		.r32 = { .base = nondet_u32(), .size = nondet_u32() },
		.var_off = { .value = nondet_u64(), .mask = nondet_u64() },
	};
}

#define in_all_cnum(v, reg)							\
	(cnum64_contains((reg)->r64, (v)) && \
	 cnum32_contains((reg)->r32, (u32)(v)) && \
	 tnum_contains((reg)->var_off, (v)))

static void assume_well_formed_cnum(struct cnum_reg_state *reg)
{
	__CPROVER_assume(tnum_well_formed(reg->var_off));
	__CPROVER_assume(!cnum64_is_empty(reg->r64));
	__CPROVER_assume(!cnum32_is_empty(reg->r32));
	/* Avoid degenerate cases where size exceeds maximum capacity */
	__CPROVER_assume(reg->r64.size <= 0xFFFFFFFFFFFFFFFFULL);
	__CPROVER_assume(reg->r32.size <= 0xFFFFFFFF);
}

static void check_fw_sound_cnum(void)
{
	struct cnum_reg_state reg = mk_cnum_reg();
	u64 v = nondet_u64();
	u64 w;

	assume_well_formed_cnum(&reg);
	__CPROVER_assume(in_all_cnum(v, &reg));

	__CPROVER_assert(cnum_find_witness(reg.r64, reg.r32, reg.var_off, &w),
			 "cnum_find_witness: should find a witness if one exists");
}

static void check_fw_complete_cnum(void)
{
	struct cnum_reg_state reg = mk_cnum_reg();
	u64 w;

	assume_well_formed_cnum(&reg);
	__CPROVER_assume(cnum_find_witness(reg.r64, reg.r32, reg.var_off, &w));

	__CPROVER_assert(in_all_cnum(w, &reg),
			 "cnum_find_witness: returned witness must satisfy all bounds");
}

static void check_sound(void)
{
	struct tnum tnum = { nondet_u64(), nondet_u64() };
	u64 a_min = nondet_u64();
	u64 a_max = nondet_u64();
	u32 b_min = nondet_u32();
	u32 b_max = nondet_u32();
	u64 v = nondet_u64();
	u64 w;

	__CPROVER_assume(tnum_well_formed(tnum));
	__CPROVER_assume(a_min <= a_max);
	__CPROVER_assume(b_min <= b_max);

	__CPROVER_assume(a_min <= v && v <= a_max);
	__CPROVER_assume(b_min <= (u32)v && (u32)v <= b_max);
	__CPROVER_assume(tnum_contains(tnum, v));

	__CPROVER_assert(find_witness_aux(a_min, a_max, b_min, b_max, tnum, &w),
			 "should always find a witness if one exists");
}

static void check_complete(void)
{
	struct tnum tnum = { nondet_u64(), nondet_u64() };
	u64 a_min = nondet_u64();
	u64 a_max = nondet_u64();
	u32 b_min = nondet_u32();
	u32 b_max = nondet_u32();
	u64 w;

	__CPROVER_assume(tnum_well_formed(tnum));
	__CPROVER_assume(a_min <= a_max);
	__CPROVER_assume(b_min <= b_max);
	__CPROVER_assume(find_witness_aux(a_min, a_max, b_min, b_max, tnum, &w));

	__CPROVER_assert(a_min <= w && w <= a_max, "witness in 64-bit range");
	__CPROVER_assert(b_min <= (u32)w && (u32)w <= b_max, "witness in 32-bit range");
	__CPROVER_assert(tnum_contains(tnum, w), "witness in tnum");
}

void main(void)
{
	check_sound();
	check_complete();
	check_fw_sound_cnum();
	check_fw_complete_cnum();
}
