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

struct result {
	const char *name;
	bool intersect;
	double ns_call;
	bool has_witness;
	u64 witness;
};

int main()
{
	struct timespec start, end;
	double elapsed_ms;

	// Use volatile sinks so the compiler doesn't optimize the calls out
	volatile bool res_bool;
	volatile u64 witness_val;

	for (int t_idx = 0; t_idx < NUM_TESTS; t_idx++) {
		struct bpf_reg_state reg = tests[t_idx];
		struct result results[5];

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
		results[0] = (struct result){
			.name = "Pairwise (Baseline)",
			.intersect = res_bool,
			.ns_call = (elapsed_ms * 1000000.0) / ITERATIONS,
			.has_witness = false
		};

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
		results[1] = (struct result){
			.name = "Allwise",
			.intersect = res_bool,
			.ns_call = (elapsed_ms * 1000000.0) / ITERATIONS,
			.has_witness = false
		};

		// 3. Time Allwise Inline
		clock_gettime(CLOCK_MONOTONIC, &start);
		for (int i = 0; i < ITERATIONS; i++) {
			res_bool = reg_bounds_intersect_allwise_inline(&reg);
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
		elapsed_ms = get_time_diff_ms(start, end);
		results[2] = (struct result){
			.name = "Allwise Inline",
			.intersect = res_bool,
			.ns_call = (elapsed_ms * 1000000.0) / ITERATIONS,
			.has_witness = false
		};

		// 4. Time Find Witness
		clock_gettime(CLOCK_MONOTONIC, &start);
		for (int i = 0; i < ITERATIONS; i++) {
			u64 temp_witness;
			res_bool = find_witness(&reg, &temp_witness);
			witness_val = temp_witness;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
		elapsed_ms = get_time_diff_ms(start, end);
		results[3] = (struct result){
			.name = "Witness (original)",
			.intersect = res_bool,
			.ns_call = (elapsed_ms * 1000000.0) / ITERATIONS,
			.has_witness = res_bool,
			.witness = witness_val
		};

		// 5. Time Find Witness Combined
		clock_gettime(CLOCK_MONOTONIC, &start);
		for (int i = 0; i < ITERATIONS; i++) {
			u64 temp_witness;
			res_bool = find_witness_combined(&reg, &temp_witness);
			witness_val = temp_witness;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
		elapsed_ms = get_time_diff_ms(start, end);
		results[4] = (struct result){
			.name = "Witness Combined",
			.intersect = res_bool,
			.ns_call = (elapsed_ms * 1000000.0) / ITERATIONS,
			.has_witness = res_bool,
			.witness = witness_val
		};

		printf("\n============== Test Case %d ==============\n", t_idx);
		printf("%-20s | %-10s | %-18s | %-12s | %-12s\n", "Algorithm", "Intersect?", "Latency (ns/call)", "Speedup", "Witness");
		printf("------------------------------------------------------------------------------------\n");
		
		double baseline = results[0].ns_call;
		for (int j = 0; j < 5; j++) {
			char wit_str[32] = "-";
			if (results[j].has_witness) {
				snprintf(wit_str, sizeof(wit_str), "0x%llx", (unsigned long long)results[j].witness);
			}
			double speedup = baseline / results[j].ns_call;
			printf("%-20s | %-10s | %14.2f ns     | %10.2fx    | %-12s\n",
				   results[j].name,
				   results[j].intersect ? "Yes" : "No",
				   results[j].ns_call,
				   speedup,
				   wit_str);
		}
		printf("====================================================================================\n");
	}

	return 0;
}
