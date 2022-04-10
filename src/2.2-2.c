/* "2.2-2.h" - Implementation for 2.2-2 functions. */
#include "../inc/2.2-2.h"
/* Swap two array elements. */
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
/* Get index of smallest array element in range. */
int min(int *arr, int i, int j)
{
	int ret = i;
	for (int k = i + 1; k <= j; k++)
	{
		if (arr[k] < arr[ret])
		{
			ret = k;
		}
	}
	return ret;
}
/* Basic selection sort. */
void sort_selection(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(arr, i, min(arr, i, size - 1));
	}
}
