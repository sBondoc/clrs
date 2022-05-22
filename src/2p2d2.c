/* "2p2d2.c" - Implementation for 2.2-2 functions. */
#include "2p2d2.h"
#include "util.h"
/* Basic selection sort. */
void sort_selection(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		swap(arr, i, index_min(arr, i, size - 1));
	}
}
