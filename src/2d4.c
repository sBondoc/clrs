/* "2d4.c" - Implementation for 2-4 functions. */
#include <string.h>
#include <limits.h>
#include "../inc/2d4.h"
/* Inversion count in array range brute force. */
int count_inversion_brute(int *arr, int p, int r)
{
	int ret = 0;
	for (int j = p + 1; j <= r; j++)
	{
		for (int i = p; i < j; i++)
		{
			if (arr[j] < arr[i])
			{
				ret++;
			}
		}
	}
	return ret;
}
/* Inversion count in array merge step. */
int count_inversion_merge(int *arr, int p, int q, int r)
{
	int nl = q - p + 1, nr = r - q;
	int left[nl + 1], right[nr + 1];
	memcpy(left, &arr[p], nl * sizeof(int));
	memcpy(right, &arr[q + 1], nr * sizeof(int));
	left[nl] = INT_MAX;
	right[nr] = INT_MAX;
	int ret = 0, i = 0, j = 0;
	for (int k = p; k <= r; k++)
	{
		if (left[i] < right[j])
		{
			arr[k] = left[i++];
		}
		else
		{
			/*
			If selecting from right array, must be inversion because
			everything in the right array is supposed to be greater
			than everything in the left array.
			*/
			arr[k] = right[j++];
			ret++;
		}
	}
	return ret;
}
/* Inversion count in array. */
int count_inversion(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		return
			count_inversion(arr, p, q) +
			count_inversion(arr, q + 1, r) +
			count_inversion_merge(arr, p, q, r)
		;
	}
	else
	{
		return 0;
	}
}
