/* "2p3d2.c" - Implementation for 2.3-2 functions. */
#include <string.h>
#include <stdio.h>
#include "../inc/2p3d2.h"
#include "../inc/util.h"
/* Recursive merge sort no sentinel merge step. */
void sort_merge_no_sentinel_merge(int *arr, int p, int q, int r)
{
	int nl = q - p + 1, nr = r - q;
	int left[nl], right[nr];
	memcpy(left, &arr[p], nl * sizeof(int));
	memcpy(right, &arr[q + 1], nr * sizeof(int));
	int i = 0, j = 0, k = p;
	for (; (i < nl) && (j < nr) && (k < r + 1); k++)
	{
		arr[k] = (left[i] < right[j]) ? left[i++] : right[j++];
	}
	if (i < nl)
	{
		memcpy(&arr[k], &left[i], (nl - i) * sizeof(int));
	}
	if (j < nr)
	{
		memcpy(&arr[k], &right[j], (nr - j) * sizeof(int));
	}
}
/* Recursive merge sort no sentinel. */
void sort_merge_no_sentinel(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		sort_merge_no_sentinel(arr, p, q);
		sort_merge_no_sentinel(arr, q + 1, r);
		sort_merge_no_sentinel_merge(arr, p, q, r);
	}
}
