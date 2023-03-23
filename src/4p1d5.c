/* 4p1d5.c - Implementation for 4.1-5 functions. */
#include "4p1d5.h"
/* Maximum subarray in linear time. */
/*
	THIS IS NOT DONE YET!!!
*/
struct Subarray max_subarray_linear(int *arr, int p, int r)
{
	int
	p_intermediate = p,
	r_intermediate = p - 1,
	sum_intermediate = 0,
	p_ret = p,
	r_ret = p,
	sum_ret = 0;
	for (int i = p; i <= r; i++)
	{
		sum_intermediate += arr[i];
		r_intermediate++;
		if (sum_intermediate < 0)
		{
			sum_intermediate = 0;
			p_intermediate = i + 1;
			r_intermediate = i;
		}
		if (sum_ret < sum_intermediate)
		{
			p_ret = p_intermediate;
			r_ret = r_intermediate;
			sum_ret = sum_intermediate;
		}
	}
	struct Subarray ret =
	{
		.arr = arr,
		.p = p_ret,
		.r = r_ret,
		.sum = sum_ret,
	};
	return ret;
}
