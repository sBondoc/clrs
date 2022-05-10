/* "2d1.c" - Implementation for 2-1 functions. */
#include <string.h>
#include <limits.h>
#include "2d1.h"
/* Insertion sort on range. */
void sort_insertion_range(int *arr, int p, int r)
{
	for (int i = p + 1; i < r + 1; i++)
	{
		int j = i - 1, key = arr[i];
		for (; (-1 < j) && (key < arr[j]); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
/* Hybrid recursive merge/iterative insertion sort merge step. */
void sort_merge_insertion_merge(int *arr, int p, int q, int r)
{
	int nl = q - p + 1, nr = r - q;
	int left[nl + 1], right[nr + 1];
	memcpy(left, &arr[p], nl * sizeof(int));
	memcpy(right, &arr[q + 1], nr * sizeof(int));
	left[nl] = INT_MAX;
	right[nr] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r; k++)
	{
		arr[k] = (left[i] < right[j]) ? left[i++] : right[j++];
	}
}
/* Hybrid recursive merge/iterative insertion sort. */
void sort_merge_insertion(int *arr, int p, int r, int k)
{
	if (p < r)
	{
		if (r - p <= k)
		{
			sort_insertion_range(arr, p, r);
		}
		else
		{
			int q = (p + r) / 2;
			sort_merge_insertion(arr, p, q, k);
			sort_merge_insertion(arr, q + 1, r, k);
			sort_merge_insertion_merge(arr, p, q, r);
		}
	}
}
