/* "4p1.c" - Implementation for 4.1 functions. */
#include <limits.h>
#include "4p1.h"
/* Find max subarray crossing midpoint. */
struct Subarray max_subarray_crossing(int *arr, int p, int q, int r)
{
	int sum = 0;
	int left_sum = INT_MIN, left_max = q;
	for (int i = q; p <= i; i--)
	{
		sum += arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			left_max = i;
		}
	}
	sum = 0;
	int right_sum = INT_MIN, right_max = q + 1;
	for (int j = q + 1; j <= r; j++)
	{
		sum += arr[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			right_max = j;
		}
	}
	struct Subarray ret =
	{
		.p = left_max,
		.r = right_max,
		.sum = left_sum + right_sum,
	};
	return ret;
}
/* Find max subarray. */
struct Subarray max_subarray(int *arr, int p, int r)
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
