#include "kernel.h"
#include "limits.h"
#include "tnum.h"
#include "types.h"

struct u64_interval {
	u64 min;
	u64 max;
};

struct u32_interval {
	u32 min;
	u32 max;
};

static inline bool u64_intersects_tnum(u64 umin, u64 umax, struct tnum t)
{
	u64 tmin = t.value;
	u64 tmax = t.value | t.mask;

	if ((tmin > umax) || (tmax < umin))
		return false;

	if (t.value != (umin & ~t.mask))
		if (tnum_step(t, umin) > umax)
			return false;

	return true;
}

static inline bool u32_intersects_tnum32(u32 u32_min, u32 u32_max,
										 struct tnum t)
{
	struct tnum t32 = tnum_subreg(t);
	u32 t32_min = t32.value;
	u32 t32_max = t32.value | t32.mask;

	if ((t32_min > u32_max) || (t32_max < u32_min))
		return false;

	if (t32.value != (u32_min & ~t32.mask))
		if (tnum_step(t32, u32_min) > u32_max)
			return false;

	return true;
}

static int intersect_u64_s64(s64 smin, s64 smax, u64 umin, u64 umax,
							 struct u64_interval *out_u64_intervals)
{

	int num_u64_intervals = 0;

	if ((u64) smin <= (u64) smax) {
		/* smin <= smax, s64 maps to one interval in u64 */
		u64 l = max_t(u64, umin, (u64) smin);
		u64 r = min_t(u64, umax, (u64) smax);
		if (l <= r) {
			/* there is an intersection */
			out_u64_intervals[num_u64_intervals].min = l;
			out_u64_intervals[num_u64_intervals].max = r;
			num_u64_intervals++;
		}
	} else {
		/* smin > smax, s64 maps to two intervals in u64, [0, smax] and
		 * [smin, U64_MAX]*/
		u64 l1 = umin;
		u64 r1 = min_t(u64, umax, (u64) smax);
		if (l1 <= r1) {
			out_u64_intervals[num_u64_intervals].min = l1;
			out_u64_intervals[num_u64_intervals].max = r1;
			num_u64_intervals++;
		}

		u64 l2 = max_t(u64, umin, (u64) smin);
		u64 r2 = umax;
		if (l2 <= r2) {
			out_u64_intervals[num_u64_intervals].min = l2;
			out_u64_intervals[num_u64_intervals].max = r2;
			num_u64_intervals++;
		}
	}

	return num_u64_intervals;
}

static int decompose_u64_intervals(const struct u64_interval *u64_intervals,
								   int num_u64_intervals,
								   struct u64_interval *out_u64_intervals)
{
	int num_out_u64_intervals = 0;

	for (int i = 0; i < num_u64_intervals; i++) {
		u64 x = u64_intervals[i].min;
		u64 y = u64_intervals[i].max;

		u64 x_hi = x >> 32;
		u64 y_hi = y >> 32;

		if (x_hi == y_hi) {
			/* the interval is fully contained in a 32-bit subspace
			 */
			out_u64_intervals[num_out_u64_intervals].min = x;
			out_u64_intervals[num_out_u64_intervals].max = y;
			num_out_u64_intervals++;
		} else {
			/* the interval is split across multiple 32-bit
			 * subspaces */

			/* left edge, i.e. [x, x_hi<<32 | U32_MAX] */
			out_u64_intervals[num_out_u64_intervals].min = x;
			out_u64_intervals[num_out_u64_intervals].max =
					(x_hi << 32) | U32_MAX;
			num_out_u64_intervals++;

			/* middle part, i.e. intervals of the form [n<<32,
			 * (n+1<<32)-1] */
			if (x_hi + 1 <= y_hi - 1) {
				out_u64_intervals[num_out_u64_intervals].min = (x_hi + 1) << 32;
				out_u64_intervals[num_out_u64_intervals].max = (y_hi << 32) - 1;
				num_out_u64_intervals++;
			}

			/* right edge, i.e. [y_hi << 32, y] */
			out_u64_intervals[num_out_u64_intervals].min = y_hi << 32;
			out_u64_intervals[num_out_u64_intervals].max = y;
			num_out_u64_intervals++;
		}
	}
	return num_out_u64_intervals;
}

static int intersect_u32_s32(u32 l, u32 r, s32 s32_min, s32 s32_max,
							 struct u32_interval *out_u32_intervals)
{
	int num_out_u32_intervals = 0;

	if ((u32) s32_min <= (u32) s32_max) {
		/* s32 is a single interval in u32 */
		u32 a2 = max_t(u32, l, (u32) s32_min);
		u32 b2 = min_t(u32, r, (u32) s32_max);
		if (a2 <= b2) {
			out_u32_intervals[num_out_u32_intervals].min = a2;
			out_u32_intervals[num_out_u32_intervals].max = b2;
			num_out_u32_intervals++;
		}
	} else {
		/* s32 is two intervals in u32, i.e. [0, smax] and [smin,
		 * U32_MAX] */
		u32 a2 = l;
		u32 b2 = min_t(u32, r, (u32) s32_max);
		if (a2 <= b2) {
			out_u32_intervals[num_out_u32_intervals].min = a2;
			out_u32_intervals[num_out_u32_intervals].max = b2;
			num_out_u32_intervals++;
		}

		u32 a3 = max_t(u32, l, (u32) s32_min);
		u32 b3 = r;
		if (a3 <= b3) {
			out_u32_intervals[num_out_u32_intervals].min = a3;
			out_u32_intervals[num_out_u32_intervals].max = b3;
			num_out_u32_intervals++;
		}
	}
	return num_out_u32_intervals;
}

static bool check_allwise_32(const struct u32_interval *u32_intervals,
							 int num_u32_intervals, u32 u32_min, u32 u32_max,
							 s32 s32_min, s32 s32_max, struct tnum t)
{
	for (int i = 0; i < num_u32_intervals; i++) {
		u32 l = u32_intervals[i].min;
		u32 r = u32_intervals[i].max;

		/* Intersect with u32 bounds */
		u32 l1 = max_t(u32, l, u32_min);
		u32 r1 = min_t(u32, r, u32_max);

		if (l1 > r1)
			continue;

		/* Intersect with s32 bounds */
		struct u32_interval u32_s32_intervals[2];
		int num_u32_s32_interavals =
				intersect_u32_s32(l1, r1, s32_min, s32_max, u32_s32_intervals);

		/* Intersect with tnum32 */
		for (int j = 0; j < num_u32_s32_interavals; j++) {
			if (u32_intersects_tnum32(u32_s32_intervals[j].min,
									  u32_s32_intervals[j].max, t)) {
				/* Found a non-empty all-wise intersection */
				return true;
			}
		}
	}
	return false;
}

bool reg_bounds_intersect_allwise(struct tnum t, s64 smin, s64 smax, u64 umin,
								  u64 umax, s32 s32_min, s32 s32_max,
								  u32 u32_min, u32 u32_max)
{
	/* 1: Compute u64 s64 intersection. Yields at most 2 u64 intervals
	 * representing the intersection*/
	struct u64_interval u64_intervals[2];
	int num_u64_intervals =
			intersect_u64_s64(smin, smax, umin, umax, u64_intervals);

	if (num_u64_intervals == 0)
		return false;

	/* 2: Decompose each u64 interval. Each u64 interval is a union of at
	 * most 3 32-bit subspaces. We got at most 2 u64 intervals from above,
	 * so this step can yield at most 6 decomposed u64 intervals.
	 */
	struct u64_interval sub_u64_ints[6];
	int num_sub_u64_intervals = decompose_u64_intervals(
			u64_intervals, num_u64_intervals, sub_u64_ints);

	/* 3: Intersect each u64 interval from above with tnum. and save those that
	 * have an intersection as u32 intervals.
	 */
	struct u32_interval u32_ints[6];
	int num_u32_intervals = 0;
	for (int i = 0; i < num_sub_u64_intervals; i++) {
		u64 min_val = sub_u64_ints[i].min;
		u64 max_val = sub_u64_ints[i].max;

		if (u64_intersects_tnum(min_val, max_val, t)) {
			u32_ints[num_u32_intervals].min = (u32) min_val;
			u32_ints[num_u32_intervals].max = (u32) max_val;
			num_u32_intervals++;
		}
	}

	/* At this point, we have at most 6 broken up u32 intervals that
	 * represent the intersection of u64, s64, and tnum. We have discarded
	 * the u32 intervals whose high 32 bits disagree with the tnum.
	 */
	if (num_u32_intervals == 0)
		return false;

	/* 4: Check the (at most 6) u32 intervals from above for intersection
	 * with input u32, u32 and tnum32 */
	return check_allwise_32(u32_ints, num_u32_intervals, u32_min, u32_max,
							s32_min, s32_max, t);
}
