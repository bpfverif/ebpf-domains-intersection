#include "limits.h"
#include "tnum.h"
#include "types.h"
#include "kernel.h"

struct u64_interval {
    u64 min;
    u64 max;
};

struct u32_interval {
    u32 min;
    u32 max;
};

bool intersection_u64_tnum(u64 umin, u64 umax, struct tnum t) {
  u64 tmin = t.value;
  u64 tmax = t.value | t.mask;

  return !((tmin > umax) || (tmax < umin) ||
           ((t.value != (umin & ~t.mask)) && (tnum_step(t, umin) > umax)));
}

bool intersection_u32_tnum(u32 u32_min, u32 u32_max, struct tnum t) {
  struct tnum t32 = tnum_subreg(t);
  u32 t32_min = t32.value;
  u32 t32_max = t32.value | t32.mask;

  return !((t32_min > u32_max) || (t32_max < u32_min) ||
           ((t32.value != (u32_min & ~t32.mask)) &&
            (tnum_step(t32, u32_min) > u32_max)));
}


bool reg_bounds_intersect_allwise(struct tnum t, s64 smin, s64 smax, u64 umin, u64 umax,
    s32 s32_min, s32 s32_max, u32 u32_min, u32 u32_max)
{
    // 1: compute u64 s64 intersection
    struct u64_interval u64_ints[2];
    int num_u64_intervals = 0;

    if ((u64)smin <= (u64)smax) {
        // smin <= smax, s64 maps to one interval in u64
        u64 l = max_t(u64, umin, (u64)smin);
        u64 r = min_t(u64, umax, (u64)smax);
        if (l <= r) { 
            // there is an intersection
            u64_ints[num_u64_intervals].min = l;
            u64_ints[num_u64_intervals].max = r;
            num_u64_intervals++;
        }
    } else {
        // smin > smax, s64 maps to two intervals in u64, 
        // [0, smax] and [smin, U64_MAX]
        u64 l1 = umin;
        u64 r1 = min_t(u64, umax, (u64)smax);
        if (l1 <= r1) {
            u64_ints[num_u64_intervals].min = l1;
            u64_ints[num_u64_intervals].max = r1;
            num_u64_intervals++;
        }
        
        u64 l2 = max_t(u64, umin, (u64)smin);
        u64 r2 = umax;
        if (l2 <= r2) {
            u64_ints[num_u64_intervals].min = l2;
            u64_ints[num_u64_intervals].max = r2;
            num_u64_intervals++;
        }
    }

    // at this point, we have at most 2 u64 intervals that 
    // represent u64 and s64 intersection. 
    if (num_u64_intervals == 0)
        return false;

    // 2: decompose each u64 interval into 32-bit subspaces
    struct u64_interval sub_ints[6];
    int num_sub_intervals = 0;

    for (int i = 0; i < num_u64_intervals; i++) {
        u64 x = u64_ints[i].min;
        u64 y = u64_ints[i].max;
        
        u64 x_hi = x >> 32;
        u64 y_hi = y >> 32;
        
        if (x_hi == y_hi) {
            // the interval is fully contained in a 32-bit subspace
            sub_ints[num_sub_intervals].min = x;
            sub_ints[num_sub_intervals].max = y;
            num_sub_intervals++;
        } else {
            // the interval is split across multiple 32-bit subspaces

            // left edge, i.e. [x, x_hi<<32 | U32_MAX]
            sub_ints[num_sub_intervals].min = x;
            sub_ints[num_sub_intervals].max = (x_hi << 32) | U32_MAX;
            num_sub_intervals++;
            
            // middle part, i.e. intervals of the form [n<<32, (n+1<<32)-1]
            if (x_hi + 1 <= y_hi - 1) {
                sub_ints[num_sub_intervals].min = (x_hi + 1) << 32;
                sub_ints[num_sub_intervals].max = (y_hi << 32) - 1;
                num_sub_intervals++;
            }
            
            // right edge, i.e. [y_hi << 32, y]
            sub_ints[num_sub_intervals].min = y_hi << 32;
            sub_ints[num_sub_intervals].max = y;
            num_sub_intervals++;
        }
    }

    
    // at this point, we have at most 6 broken up u64 intervals that represent
    // the intersection of u64 and s64. 

    // 3: Pre-intersect with tnum and Project to u32
    struct u32_interval u32_ints[6];
    int num_u32_intervals = 0;

    for (int i = 0; i < num_sub_intervals; i++) {
        u64 min_val = sub_ints[i].min;
        u64 max_val = sub_ints[i].max;
        
        if (intersection_u64_tnum(min_val, max_val, t)) {
            u32_ints[num_u32_intervals].min = (u32)min_val;
            u32_ints[num_u32_intervals].max = (u32)max_val;
            num_u32_intervals++;
        }
    }

    // at this point, we have at most 6 broken up u32 intervals that represent
    // the intersection of u64, s64, and tnum. we have discarded the u32 intervals 
    // whose high 32 bits disagree with the tnum
    if (num_u32_intervals == 0)
        return false;

    // 4: All-wise 32-bit Intersection
    for (int i = 0; i < num_u32_intervals; i++) {
        u32 l = u32_ints[i].min;
        u32 r = u32_ints[i].max;
        
        // Intersect with u32 bounds
        u32 l1 = max_t(u32, l, u32_min);
        u32 r1 = min_t(u32, r, u32_max);
        
        if (l1 > r1)
            continue;
            
        // Intersect with s32 bounds
        struct u32_interval temp_ints[2];
        int num_temp = 0;
        
        if ((u32)s32_min <= (u32)s32_max) {
            // s32 is a single interval in u32
            u32 a2 = max_t(u32, l1, (u32)s32_min);
            u32 b2 = min_t(u32, r1, (u32)s32_max);
            if (a2 <= b2) {
                temp_ints[num_temp].min = a2;
                temp_ints[num_temp].max = b2;
                num_temp++;
            }
        } else {
            // s32 is two intervals in u32, i.e. [0, smax] and [smin, U32_MAX]
            u32 a2 = l1;
            u32 b2 = min_t(u32, r1, (u32)s32_max);
            if (a2 <= b2) {
                temp_ints[num_temp].min = a2;
                temp_ints[num_temp].max = b2;
                num_temp++;
            }
            
            u32 a3 = max_t(u32, l1, (u32)s32_min);
            u32 b3 = r1;
            if (a3 <= b3) {
                temp_ints[num_temp].min = a3;
                temp_ints[num_temp].max = b3;
                num_temp++;
            }
        }
        
        // Intersect with tnum32
        for (int j = 0; j < num_temp; j++) {
            if (intersection_u32_tnum(temp_ints[j].min, temp_ints[j].max, t)) {
                // Found a non-empty all-wise intersection
                return true;
            }
        }
    }

    return false;
}


