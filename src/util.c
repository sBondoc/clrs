/* "util.h" - Implementation for utility functions. */
#include <stdio.h>
#include "../inc/util.h"
/* Print int array. */
void fprintarr_int(FILE *stream, int *arr, int size)
{
	fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stream, "%d, ", arr[i]);
	}
	fprintf(stream, "%d}\n", arr[size - 1]);
}
