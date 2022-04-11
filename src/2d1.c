/* "2d1.c" - Implementation for 2-1 functions. */
#include <string.h>
#include "../inc/2d1.h"
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
	// code
}
/* Hybrid recursive merge/iterative insertion sort. */
void sort_merge_insertion(int *arr, int p, int r, int k)
{
	// code
}
