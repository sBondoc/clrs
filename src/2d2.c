/* "2d2.c" - Implementation for 2-2 functions. */
#include "../inc/2d2.h"
#include "../inc/util.h"
/* Bubble sort. */
void sort_bubble(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				swap(arr, i, j);
			}
		}
	}
}
