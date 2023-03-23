/* "4p1d2.c" - Implementation for 4.1-2 functions. */
#include <limits.h>
#include "4p1d2.h"
/* Find maximum subarray brute force. */
struct Subarray max_subarray_brute(int *arr, int p, int r)
{
	int p_intermediate = p, r_intermediate = p, sum = INT_MIN;
	for (int i = p; i <= r; i++)
	{
		int sum_intermediate = 0;
		for (int j = i; j <= r; j++)
		{
			sum_intermediate += arr[j];
			if (sum < sum_intermediate)
			{
				p_intermediate = i;
				r_intermediate = j;
				sum = sum_intermediate;
			}
		}
	}
	struct Subarray ret =
	{
		.p = p_intermediate,
		.r = r_intermediate,
		.sum = sum,
	};
	return ret;
}
