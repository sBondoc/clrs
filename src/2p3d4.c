/* "2p3d4.c" - Implementation for 2.3-4 functions. */
#include "include.h"
/* Recursive insertion sort. */
void sort_insertion_recursive(int *arr, int n)
{
	if (n == 0)
	{
		return;
	}
	sort_insertion_recursive(arr, n - 1);
	int temp = arr[n], i = n - 1;
	for (; (0 <= i) && (temp < arr[i]); i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[++i] = temp;
}
