/* "2p3d7.h" - Implementation for 2.3-7 functions. */
#include <string.h>
#include "include.h"
#include "2p3d7.h"
/* Check if sum exists in array. */
bool sum_exists(int *arr, int size, int sum)
{
	int arr_copy[size];
	memcpy(arr_copy, arr, sizeof(arr[0] * sizeof(arr)));
	sort_merge(arr, 0, size - 1);
	int i = 0, j = size - 1;
	while (i < j)
	{
		if (arr[i] + arr[j] == sum)
		{
			return true;
		}
		if (arr[i] + arr[j] < sum)
		{
			i++;
		}
		if (sum < arr[i] + arr[j])
		{
			j--;
		}
	}
	return false;
}
