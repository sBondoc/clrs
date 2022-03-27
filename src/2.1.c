/* "2.1.h" - Implementation for 2.1 functions. */
#include <stdio.h>
#include "../inc/util.h"
#include "../inc/2.1.h"
/* Basic insertion sort. */
void sort_insertion(int *arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i], j = i - 1;
		for (; (-1 < j) && (key < arr[j]); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
