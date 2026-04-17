#ifndef _INTERSECTION_H
#define _INTERSECTION_H

#include "types.h"
#include "tnum.h"

bool reg_bounds_intersect_allwise(struct tnum t, s64 smin, s64 smax, u64 umin, u64 umax,
    s32 s32_min, s32 s32_max, u32 u32_min, u32 u32_max);
bool reg_bounds_intersect_pairwise(struct tnum t, s64 smin, s64 smax, u64 umin, u64 umax,
    s32 s32_min, s32 s32_max, u32 u32_min, u32 u32_max);

#endif /* _INTERSECTION_H */