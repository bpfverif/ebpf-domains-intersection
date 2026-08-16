#include "bpf_common.h"

static bool find_witness_aux(u64 a_min, u64 a_max, u32 b_min, u32 b_max, struct tnum tnum, u64 *out)
{
	/* The 64-bit range [a_min, a_max] may span multiple 32-bit blocks.
	 * In the first block, tnum may only partially overlap with
	 * [b_min, b_max] (due to clamping to a_min).  But for any middle
	 * block that intersects with tnum, the set of low-32 tnum values
	 * is identical, so checking one middle block is enough.
	 */
	u64 w, tmax;
	u32 b_lo;

	tmax = tnum.value | tnum.mask;
	if (tmax < a_min)
		return false;

	/* check if tnum intersects with b_min/b_max in the first 32-bit block,
	 * clamp lower bound to (u32)a_min since lower values would give w < a_min.
	 */
	b_lo = max((u32)a_min, b_min);
	if (b_lo > b_max)
		goto next_block;

	w = (a_min & UPPER_HALF) | b_lo;
	if (!tnum_contains(tnum, w))
		w = tnum_step(tnum, w);
	if (a_min <= w && w <= a_max && b_min <= (u32)w && (u32)w <= b_max) {
		*out = w;
		return true;
	}

next_block:
	/* true if there are no more 32-bit blocks */
	if ((a_min & UPPER_HALF) == UPPER_HALF)
		return false;
	/* find the next 32-bit block intersecting with tnum,
	 * w is a minimal value in tnum within this block.
	 */
	w = (a_min & UPPER_HALF) + (1ull << 32);
	if (!tnum_contains(tnum, w))
		w = tnum_step(tnum, w);
	/* if (u32)w is to the left of b_min/b_max, try first b_min within this 32-bit block */
	if ((u32)w < b_min)
		w = (w & UPPER_HALF) | b_min;
	if (!tnum_contains(tnum, w))
		w = tnum_step(tnum, w);
	if (w <= a_max && b_min <= (u32)w && (u32)w <= b_max) {
		*out = w;
		return true;
	}
	return false;
}

static bool find_witness32(u64 a_min, u64 a_max, struct bpf_reg_state *reg, u64 *out)
{
	u32 b_umin = reg->u32_min_value;
	u32 b_umax = reg->u32_max_value;
	u32 b_smin = (u32)reg->s32_min_value;
	u32 b_smax = (u32)reg->s32_max_value;
	u32 lo, hi;

	if (reg->s32_min_value >= 0 || reg->s32_max_value < 0) {
		lo = max(b_umin, b_smin);
		hi = min(b_umax, b_smax);
		if (lo > hi)
			return false;
		return find_witness_aux(a_min, a_max, lo, hi, reg->var_off, out);
	}

	/* s32 range crosses sign boundary:
	 * two u32 intervals [0, smax] and [smin, U32_MAX]
	 */

	/* interval 1: [0, smax] intersected with [b_umin, b_umax] */
	hi = min(b_umax, b_smax);
	if (b_umin <= hi && find_witness_aux(a_min, a_max, b_umin, hi, reg->var_off, out))
		return true;

	/* interval 2: [smin, U32_MAX] intersected with [b_umin, b_umax] */
	lo = max(b_umin, b_smin);
	if (lo <= b_umax && find_witness_aux(a_min, a_max, lo, b_umax, reg->var_off, out))
		return true;

	return false;
}

bool find_witness(struct bpf_reg_state *reg, u64 *out)
{
	u64 umin = reg->umin_value;
	u64 umax = reg->umax_value;
	u64 smin = (u64)reg->smin_value;
	u64 smax = (u64)reg->smax_value;
	u64 lo, hi;

	if (reg->smin_value >= 0 || reg->smax_value < 0) {
		/* s64 range does not cross sign boundary:
		 * single u64 interval [smin, smax]
		 */
		lo = max(umin, smin);
		hi = min(umax, smax);
		if (lo > hi)
			return false;
		return find_witness32(lo, hi, reg, out);
	}

	/* s64 range crosses sign boundary:
	 * two u64 intervals [0, smax] and [smin, U64_MAX]
	 */

	/* interval 1: [0, smax] intersected with [umin, umax] */
	hi = min(umax, smax);
	if (umin <= hi && find_witness32(umin, hi, reg, out))
		return true;

	/* interval 2: [smin, U64_MAX] intersected with [umin, umax] */
	lo = max(umin, smin);
	if (lo <= umax && find_witness32(lo, umax, reg, out))
		return true;

	return false;
}

