#include "bpf_common.h"

/* Returns true if @a is a known constant */
static inline bool tnum_is_const(struct tnum a)
{
	return !a.mask;
}

/* Returns true if 32-bit subreg @a is a known constant*/
static inline bool tnum_subreg_is_const(struct tnum a)
{
	return !(tnum_subreg(a)).mask;
}

static bool u64_intersects_tnum(u64 umin, u64 umax, struct tnum t)
{
	u64 tmin = t.value;
	u64 tmax = t.value | t.mask;

	return !((tmin > umax) || (tmax < umin) ||
			 ((t.value != (umin & ~t.mask)) && (tnum_step(t, umin) > umax)));
}

static bool u32_intersects_tnum(u32 u32_min, u32 u32_max, struct tnum t)
{
	struct tnum t32 = tnum_subreg(t);
	u32 t32_min = t32.value;
	u32 t32_max = t32.value | t32.mask;

	return !((t32_min > u32_max) || (t32_max < u32_min) ||
			 ((t32.value != (u32_min & ~t32.mask)) &&
			  (tnum_step(t32, u32_min) > u32_max)));
}

static bool process_u32_interval(u32 l, u32 r, u32 u32_min, u32 u32_max,
								 s32 s32_min, s32 s32_max, struct tnum t)
{
	u32 l1 = max_t(u32, l, u32_min);
	u32 r1 = min_t(u32, r, u32_max);

	if (l1 > r1)
		return false;

	if (!u32_intersects_tnum(l1, r1, t))
		return false;

	if ((u32) s32_min <= (u32) s32_max) {
		u32 a2 = max_t(u32, l1, (u32) s32_min);
		u32 b2 = min_t(u32, r1, (u32) s32_max);
		if (a2 <= b2) {
			if (u32_intersects_tnum(a2, b2, t))
				return true;
		}
	} else {
		u32 a2 = l1;
		u32 b2 = min_t(u32, r1, (u32) s32_max);
		if (a2 <= b2) {
			if (u32_intersects_tnum(a2, b2, t))
				return true;
		}

		u32 a3 = max_t(u32, l1, (u32) s32_min);
		u32 b3 = r1;
		if (a3 <= b3) {
			if (u32_intersects_tnum(a3, b3, t))
				return true;
		}
	}

	return false;
}

static bool process_u64_subinterval(u64 min_val, u64 max_val, u32 u32_min,
									u32 u32_max, s32 s32_min, s32 s32_max,
									struct tnum t)
{
	if (u64_intersects_tnum(min_val, max_val, t)) {
		return process_u32_interval((u32) min_val, (u32) max_val, u32_min,
									u32_max, s32_min, s32_max, t);
	}
	return false;
}

static bool process_u64_interval(u64 x, u64 y, u32 u32_min, u32 u32_max,
								 s32 s32_min, s32 s32_max, struct tnum t)
{
	u64 x_hi = x >> 32;
	u64 y_hi = y >> 32;

	if (x_hi == y_hi) {
		if (process_u64_subinterval(x, y, u32_min, u32_max, s32_min, s32_max,
									t))
			return true;
	} else {
		if (process_u64_subinterval(x, (x_hi << 32) | U32_MAX, u32_min, u32_max,
									s32_min, s32_max, t))
			return true;

		if (x_hi + 1 <= y_hi - 1) {
			if (process_u64_subinterval((x_hi + 1) << 32, (y_hi << 32) - 1,
										u32_min, u32_max, s32_min, s32_max, t))
				return true;
		}

		if (process_u64_subinterval(y_hi << 32, y, u32_min, u32_max, s32_min,
									s32_max, t))
			return true;
	}

	return false;
}

static bool range_bounds_violation(struct bpf_reg_state *reg)
{
	return (reg->umin_value > reg->umax_value || reg->smin_value > reg->smax_value ||
		reg->u32_min_value > reg->u32_max_value ||
		reg->s32_min_value > reg->s32_max_value);
}

bool reg_bounds_intersect_allwise_inline(struct bpf_reg_state *reg)
{
	u64 umin = reg->umin_value, umax = reg->umax_value;
	s64 smin = reg->smin_value, smax = reg->smax_value;
	u32 u32_min = reg->u32_min_value, u32_max = reg->u32_max_value;
	s32 s32_min = reg->s32_min_value, s32_max = reg->s32_max_value;
	struct tnum t = reg->var_off;

	if (range_bounds_violation(reg))
		return false;

	if ((u64) smin <= (u64) smax) {
		u64 l = max_t(u64, umin, (u64) smin);
		u64 r = min_t(u64, umax, (u64) smax);
		if (l <= r) {
			if (process_u64_interval(l, r, u32_min, u32_max, s32_min, s32_max,
									 t))
				return true;
		}
	} else {
		u64 l1 = umin;
		u64 r1 = min_t(u64, umax, (u64) smax);
		if (l1 <= r1) {
			if (process_u64_interval(l1, r1, u32_min, u32_max, s32_min, s32_max,
									 t))
				return true;
		}

		u64 l2 = max_t(u64, umin, (u64) smin);
		u64 r2 = umax;
		if (l2 <= r2) {
			if (process_u64_interval(l2, r2, u32_min, u32_max, s32_min, s32_max,
									 t))
				return true;
		}
	}

	return false;
}
