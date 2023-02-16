/* "2p3d7.h" - Implementation for 2.3-7 functions. */
#include <string.h>
#include "include.h"
#include "2p3d7.h"
/* Check if sum exists in array. */
bool sum_exists(int *arr, int size, int sum)
{
	int arr_copy[size];
	memcpy(arr_copy, arr, ((size_t) size) * sizeof(arr[0])); // Copy array to preserve original.
	sort_merge(arr_copy, 0, size - 1);
	fprintarr_int(stdout, arr_copy, size);
	int i = 0, j = size - 1;
	while (i < j)
	{
		if (arr_copy[i] + arr_copy[j] == sum)
		{
			return true;
		}
		if (arr_copy[i] + arr_copy[j] < sum)
		{
			i++;
		}
		if (sum < arr_copy[i] + arr_copy[j])
		{
			j--;
		}
	}
	return false;
}
