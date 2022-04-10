/* "2p1d2.c" - Implementation for 2.1-2 functions. */
#include "../inc/2p1d2.h"
/* Nonincreasing insertion sort */
void sort_insertion_nonincreasing(int *arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i], j = i - 1;
		for (; (-1 < j) && (arr[j] < key); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
