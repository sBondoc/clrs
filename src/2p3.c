/* "2p3.c" - Implementation for 2.3 functions. */
#include <string.h>
#include <limits.h>
#include "2p3.h"
/* Recursive merge sort merge step. */
void sort_merge_merge(int *arr, int p, int q, int r)
{
	int nl = q - p + 1, nr = r - q;
	int left[nl + 1], right[nr + 1];
	memcpy(left, &arr[p], nl * sizeof(int));
	memcpy(right, &arr[q + 1], nr * sizeof(int));
	left[nl] = INT_MAX;
	right[nr] = INT_MAX;
	int j = 0, k = 0;
	for (int i = p; i < r + 1; i++)
	{
		arr[i] = (left[j] < right[k]) ? left[j++] : right[k++];
	}
}
/* Recursive merge sort. */
void sort_merge(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		sort_merge(arr, p, q);
		sort_merge(arr, q + 1, r);
		sort_merge_merge(arr, p, q, r);
	}
}
