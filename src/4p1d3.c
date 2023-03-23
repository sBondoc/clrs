/* "4p1d3.c" - Implementation for 4.1-3 functions. */
#include <limits.h>
#include "4p1.h"
#include "4p1d2.h"
#include "4p1d3.h"
/* Find max subarray combining recursive and brute force methods. */
struct Subarray max_subarray_composite(int *arr, int p, int r, int crossover)
{
	if (p == r)
	{
		struct Subarray ret =
		{
			.p = p,
			.r = r,
			.sum = arr[p],
		};
		return ret;
	}
	if (r - p < crossover)
	{
		return max_subarray_brute(arr, p, r);
	}
	int q = (p + r) / 2;
	struct Subarray left = max_subarray(arr, p, q);
	struct Subarray right = max_subarray(arr, q + 1, r);
	struct Subarray cross = max_subarray_crossing(arr, p, q, r);
	if ((left.sum >= right.sum) && (left.sum >= cross.sum))
	{
		return left;
	}
	else if ((right.sum >= left.sum) && (right.sum >= cross.sum))
	{
		return right;
	}
	else
	{
		return cross;
	}
}
