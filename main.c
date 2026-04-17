#include "intersection.h"
#include <stdio.h>

int main() {
    struct tnum t = {
        .value = 571784718319620ULL,
        .mask = 13835058055284785152ULL,
    };
    u64 umin = 4720916047744139360ULL;
    u64 umax = 13835060254305419265ULL;
    s64 smin = -4611686018425434112LL;
    s64 smax = 4611686018427420672ULL;
    s32 s32min = -2127691517;
    s32 s32max = 17825792;
    u32 u32min = 4472834;
    u32 u32max = 2147483648;

    bool res_allwise = reg_bounds_intersect_allwise(t, smin, smax, umin, umax, s32min, s32max, u32min, u32max);
    printf("allwise: %d\n", res_allwise);

    bool res_pairwise = reg_bounds_intersect_pairwise(t, smin, smax, umin, umax, s32min, s32max, u32min, u32max);
    printf("pairwise: %d\n", res_pairwise);

    return 0;
}
