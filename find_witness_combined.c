#include "intersection.h"
#include <stdint.h>
#include <stdbool.h>

static bool tnum_contains(struct tnum t, u64 v)
{
	return (v & ~t.mask) == t.value;
}

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
{
	u64 x_hi = a_min & UPPER_HALF;
	u64 y_hi = a_max & UPPER_HALF;
	u32 l, r;
	u64 w;

	/*
	 * Fast path: check if the tnum's absolute maximum is less than the required minimum.
	 * If so, no witness can possibly exist.
	 */
	if ((tnum.value | tnum.mask) < a_min)
		return false;

	if (x_hi == y_hi) {
		/*
		 * Single 32-bit subspace: [a_min, a_max] is fully contained in one block.
		 * Project to u32 bounds and intersect with [b_min, b_max].
		 */
		l = max((u32)a_min, b_min);
		r = min((u32)a_max, b_max);
		if (l > r)
			return false; /* 32-bit bounds don't overlap at all */

		w = x_hi | l;
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);

		/* 
		 * Verify the candidate against both 64-bit and 32-bit upper boundaries.
		 * Since we started at `l >= b_min` and `tnum_step` only increases `w`,
		 * `(u32)w >= b_min` is inherently satisfied as long as it doesn't overflow 
		 * the 32-bit block. `w <= a_max` guarantees it didn't overflow the block.
		 */
		if (w <= a_max && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
		return false;
	}

	/*
	 * Left Edge: [a_min, x_hi | U32_MAX]
	 * Project to u32 bounds and intersect with [b_min, b_max].
	 */
	l = max((u32)a_min, b_min);
	r = b_max;
	if (l <= r) {
		w = x_hi | l;
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);
			
		/* 
		 * Ensure `w` stayed in the left edge block. If it jumped to a higher block,
		 * we missed the left edge and should proceed to check the middle/right blocks.
		 */
		if (w <= (x_hi | 0xFFFFFFFFull) && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
	}

	/*
	 * Middle Parts: Full 32-bit subspaces between x_hi and y_hi.
	 * Intervals of the form [n<<32, (n<<32) | U32_MAX].
	 */
	if (x_hi + (1ULL << 32) < y_hi) {
		/* Move completely to the start of the first middle 32-bit block */
		w = x_hi + (1ULL << 32);
		
		/* Jump to the first block actually supported by the tnum's upper bits */
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);
			
		/* Clamp the lower 32 bits up to b_min to satisfy the 32-bit constraint */
		if ((u32)w < b_min)
			w = (w & UPPER_HALF) | b_min;
			
		/* Step one final time to align with the tnum constraints after the bump */
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);

		/* 
		 * If the witness is still strictly below y_hi, it remains in the middle parts.
		 * Because we checked the *first available* valid middle block, if this block 
		 * violates `b_max`, no other middle/right block will satisfy it either.
		 * We must explicitly check `b_min <= (u32)w` because the final `tnum_step` 
		 * might have jumped to a new block, wrapping its lower 32 bits to `< b_min`.
		 */
		if (w < y_hi && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
	}

	/*
	 * Right Edge: [y_hi, a_max]
	 * Project to u32 bounds and intersect with [b_min, b_max].
	 */
	l = b_min;
	r = min((u32)a_max, b_max);
	if (l <= r) {
		w = y_hi | l;
		if (!tnum_contains(tnum, w))
			w = tnum_step(tnum, w);
			
		/* 
		 * Since we started at `b_min`, we only need to ensure it didn't exceed 
		 * the upper bounds `a_max` or `b_max`.
		 */
		if (w <= a_max && b_min <= (u32)w && (u32)w <= b_max) {
			*out = w;
			return true;
		}
	}

	return false;
}

/*
 * find_witness32() - Resolves 32-bit sign boundaries (u32 ∩ s32).
 *
 * This function is the second phase of the successive subdivision. It receives a strictly
 * contiguous 64-bit range [a_min, a_max] from find_witness(). 
 *
 * It computes the exact algebraic intersection of the u32 bounds and the s32 bounds. 
 * Because the s32 bounds might cross the 0x80000000 sign boundary when evaluated 
 * as u32, this intersection splits into up to two fully contiguous 32-bit ranges.
 */
static bool find_witness32(u64 a_min, u64 a_max, struct bpf_reg_state *reg, u64 *out)
{
	u32 b_umin = reg->u32_min_value;
	u32 b_umax = reg->u32_max_value;
	u32 b_smin = (u32)reg->s32_min_value;
	u32 b_smax = (u32)reg->s32_max_value;
	u32 lo, hi;

	if (reg->s32_min_value >= 0 || reg->s32_max_value < 0) {
		/* 
		 * s32 range does not cross the sign boundary. 
		 * It maps to a single contiguous u32 interval. 
		 */
		lo = max(b_umin, b_smin);
		hi = min(b_umax, b_smax);
		if (lo <= hi) {
			if (find_witness_aux(a_min, a_max, lo, hi, reg->var_off, out))
				return true;
		}
	} else {
		/* 
		 * s32 range crosses the sign boundary.
		 * It maps to TWO disjoint u32 intervals: [0, smax] and [smin, U32_MAX].
		 */

		/* Interval 1: [0, (u32)smax] intersected with [b_umin, b_umax] */
		hi = min(b_umax, b_smax);
		if (b_umin <= hi) {
			if (find_witness_aux(a_min, a_max, b_umin, hi, reg->var_off, out))
				return true;
		}

		/* Interval 2: [(u32)smin, U32_MAX] intersected with [b_umin, b_umax] */
		lo = max(b_umin, b_smin);
		if (lo <= b_umax) {
			if (find_witness_aux(a_min, a_max, lo, b_umax, reg->var_off, out))
				return true;
		}
	}

	return false;
}

/*
 * find_witness() - Top-level entry point for witness construction.
 *                  Resolves 64-bit sign boundaries (u64 ∩ s64).
 *
 * It computes the exact algebraic intersection of the u64 bounds and the s64 bounds.
 * Because the s64 bounds might cross the 0x8000000000000000 sign boundary when 
 * evaluated as u64, this intersection splits into up to two fully contiguous 
 * 64-bit ranges.
 */
bool find_witness_combined(struct bpf_reg_state *reg, u64 *out)
{
	u64 umin = reg->umin_value;
	u64 umax = reg->umax_value;
	u64 smin = (u64)reg->smin_value;
	u64 smax = (u64)reg->smax_value;
	u64 lo, hi;

	if (reg->smin_value >= 0 || reg->smax_value < 0) {
		/* 
		 * s64 range does not cross the sign boundary.
		 * It maps to a single contiguous u64 interval. 
		 */
		lo = max(umin, smin);
		hi = min(umax, smax);
		if (lo <= hi) {
			if (find_witness32(lo, hi, reg, out))
				return true;
		}
	} else {
		/* 
		 * s64 range crosses the sign boundary.
		 * It maps to TWO disjoint u64 intervals: [0, smax] and [smin, U64_MAX].
		 */

		/* Interval 1: [0, (u64)smax] intersected with [umin, umax] */
		hi = min(umax, smax);
		if (umin <= hi) {
			if (find_witness32(umin, hi, reg, out))
				return true;
		}

		/* Interval 2: [(u64)smin, U64_MAX] intersected with [umin, umax] */
		lo = max(umin, smin);
		if (lo <= umax) {
			if (find_witness32(lo, umax, reg, out))
				return true;
		}
	}

	return false;
}
