/* "4p1d2.c" - Implementation for 4.1-2 functions. */
#include <limits.h>
#include "4p1d2.h"
/* Find maximum subarray brute force. */
struct Subarray max_subarray_brute(int *arr, int size)
{
	int p = 0, r = 0, sum = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		int sum_intermediate = 0;
		for (int j = i; j < size; j++)
		{
			sum_intermediate += arr[j];
			if (sum < sum_intermediate)
			{
				p = i;
				r = j;
				sum = sum_intermediate;
			}
		}
	}
	struct Subarray ret =
	{
		.p = p,
		.r = r,
		.sum = sum,
	};
	return ret;
}
