/* "2d4.c" - Implementation for 2-4 functions. */
#include <string.h>
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
	int left[nl], right[nr];
	memcpy(left, &arr[p], nl * sizeof(int));
	memcpy(left, &arr[q + 1], nr * sizeof(int));
	int ret = 0;
	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nr; j++)
		{
			if (right[j] < left[i])
			{
				ret++;
			}
		}
	}
	return ret;
}
/* Inversion count in array. */
int count_inversion(int *arr, int p, int r)
{
	if (1 < r - p)
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
