#include "types.h"
#include "tnum.h"
#include "limits.h"

static bool range_bounds_violation(s64 smin, s64 smax, u64 umin, u64 umax,
	s32 s32_min, s32 s32_max, u32 u32_min, u32 u32_max)
{
	return (umin > umax ||
		smin > smax ||
		u32_min > u32_max ||
		s32_min > s32_max);
}


bool reg_bounds_intersect_pairwise(struct tnum t, s64 smin, s64 smax, u64 umin, u64 umax,
	s32 s32_min, s32 s32_max, u32 u32_min, u32 u32_max)
{
	struct tnum t32 = tnum_subreg(t);
	u64 tmin = t.value, tmax = t.value | t.mask;
	u32 t32_min = t32.value, t32_max = t32.value | t32.mask;

	if (range_bounds_violation(smin, smax, umin, umax, s32_min, s32_max, u32_min, u32_max))
		return false;

	if ((t.value & t.mask) != 0)
		return false;

    /* u64-s64 */
	if ((u64)smin <= (u64)smax) {
		if ((u64)smax < umin || umax < (u64)smin)
			return false;
	} else {
		if ((u64)smin > umax && (u64)smax < umin)
			return false;
	}

	/* u32-s32 */
	if ((u32)s32_min <= (u32)s32_max) {
		if ((u32)s32_max < u32_min || u32_max < (u32)s32_min)
			return false;
	} else {
		if ((u32)s32_min > u32_max && (u32)s32_max < u32_min)
			return false;
	}

    /* u64-tnum */
    if (tmax < umin || tmin > umax)
		return false;
	if (t.value != (umin & ~t.mask)) {
		if (tnum_step(t, umin) > umax)
			return false;
	}

    /* u32-tnum */
    if (t32_max < u32_min || t32_min > u32_max)
		return false;
	if (t32.value != (u32_min & ~t32.mask)) {
		if (tnum_step(t32, u32_min) > u32_max)
			return false;
	}

    /* s64-tnum */
	if ((u64)smin <= (u64)smax) {
		if (tmax < (u64)smin || tmin > (u64)smax)
			return false;
		if (t.value != ((u64)smin & ~t.mask)) {
			if (tnum_step(t, (u64)smin) > (u64)smax)
				return false;
		}
	} else {
		if (tmin > (u64)smax && tmax < (u64) smin)
			return false;
	}

    /* s32-tnum */
	if ((u32)s32_min <= (u32)s32_max) {
		if (t32_min > (u32)s32_max || t32_max < (u32)s32_min)
			return false;
		if (t32.value != ((u32)s32_min & ~t32.mask)) {
			if (tnum_step(t32, (u32)s32_min) > (u32)s32_max)
				return false;
		}
	} else {
		if (t32_min > (u32)s32_max && t32_max < (u32)s32_min)
			return false;
	}

    /* u64-u32 */
	if (umax - umin < U32_MAX) {
		if ((u32)umin <= (u32)umax) {
			if ((u32)umax < u32_min || u32_max < (u32)umin)
				return false;
		} else {
			if ((u32)umin > u32_max && (u32)umax < u32_min)
				return false;
		}
	}

    /* s64-u32 */
	if ((u64)smax - (u64)smin < U32_MAX) {
		if ((u32)smin <= (u32)smax) {
			if ((u32)smax < u32_min || u32_max < (u32)smin)
				return false;
		} else {
			if ((u32)smin > u32_max && (u32)smax < u32_min)
				return false;
		}
	}

    /* u64-s32 */
	if (umax - umin < U32_MAX) {
		if ((s32)umin <= (s32)umax) {
			if ((s32)umax < s32_min || s32_max < (s32)umin)
				return false;
		} else {
			if ((s32)umin > s32_max && (s32)umax < s32_min)
				return false;
		}
	}

    /* s64-s32 */
	if ((u64)smax - (u64)smin < U32_MAX) {
		if ((s32)smin <= (s32)smax) {
			if ((s32)smax < s32_min || s32_max < (s32)smin)
				return false;
		} else {
			if ((s32)smin > s32_max && (s32)smax < s32_min)
				return false;
		}
	}

	return true;
}