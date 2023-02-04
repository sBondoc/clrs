/* "2p3d5.c" - Implementation for 2.3-5 functions. */
#include "2p3d5.h"
/* Binary search. */
int binary_search(int *arr, int key, int p, int r)
{
	int q = (p + r) / 2;
	if (arr[q] == key)
	{
		return q;
	}
	if (r <= p)
	{
		return -1;
	}
	if (arr[q] < key)
	{
		return binary_search(arr, key, q + 1, r);
	}
	else
	{
		return binary_search(arr, key, p, q - 1);
	}
}
