#include "bpf_verifier.h"
#include "intersection.h"
#include <stdio.h>
#include <time.h>

#define ITERATIONS 10000000

#define NUM_TESTS 2
struct bpf_reg_state tests[] = {
		{.var_off = {.value = 42ULL, .mask = 0ULL},
		 .umin_value = 0ULL,
		 .umax_value = 100ULL,
		 .smin_value = 0LL,
		 .smax_value = 100LL,
		 .s32_min_value = 0,
		 .s32_max_value = 100,
		 .u32_min_value = 0,
		 .u32_max_value = 100},
		{.var_off =
				 {
						 .value = 571784718319620ULL,
						 .mask = 13835058055284785152ULL,
				 },
		 .umin_value = 4720916047744139360ULL,
		 .umax_value = 13835060254305419265ULL,
		 .smin_value = -4611686018425434112LL,
		 .smax_value = 4611686018427420672ULL,
		 .s32_min_value = -2127691517,
		 .s32_max_value = 17825792,
		 .u32_min_value = 4472834,
		 .u32_max_value = 2147483648}};

static double get_time_diff_ms(struct timespec start, struct timespec end)
{
	return (end.tv_sec - start.tv_sec) * 1000.0 +
		   (end.tv_nsec - start.tv_nsec) / 1000000.0;
}

int main()
{
	struct timespec start, end;
	double elapsed_ms;

	// Use volatile sinks so the compiler doesn't optimize the calls out
	volatile bool res_bool;
	volatile u64 witness_val;

	for (int t_idx = 0; t_idx < NUM_TESTS; t_idx++) {
		struct bpf_reg_state reg = tests[t_idx];
		printf("============== Test Case %d ==============\n", t_idx);

		// 1. Time Pairwise
		clock_gettime(CLOCK_MONOTONIC, &start);
		for (int i = 0; i < ITERATIONS; i++) {
			res_bool = reg_bounds_intersect_pairwise(
					reg.var_off, reg.smin_value, reg.smax_value, reg.umin_value,
					reg.umax_value, reg.s32_min_value, reg.s32_max_value,
					reg.u32_min_value, reg.u32_max_value);
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
		elapsed_ms = get_time_diff_ms(start, end);

		printf("  pairwise: %.2f ms total (%.2f ns/call)\n", elapsed_ms,
			   (elapsed_ms * 1000000.0) / ITERATIONS);
		printf("  pairwise intersection: %d\n", res_bool);
		printf("--------\n");

		// 2. Time Allwise
		clock_gettime(CLOCK_MONOTONIC, &start);
		for (int i = 0; i < ITERATIONS; i++) {
			res_bool = reg_bounds_intersect_allwise(
					reg.var_off, reg.smin_value, reg.smax_value, reg.umin_value,
					reg.umax_value, reg.s32_min_value, reg.s32_max_value,
					reg.u32_min_value, reg.u32_max_value);
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
		elapsed_ms = get_time_diff_ms(start, end);
		printf("  allwise:  %.2f ms total (%.2f ns/call)\n", elapsed_ms,
			   (elapsed_ms * 1000000.0) / ITERATIONS);
		printf("  allwise intersection: %d\n", res_bool);
		printf("--------\n");
	}

	return 0;
}
