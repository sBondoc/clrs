/* "2p1d3.c" - Prototypes for 2.1-3 functions. */
#include "../inc/2p1d3.h"
/* Linear search */
int search_linear(int *arr, int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}
