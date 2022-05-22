/* "util.c" - Implementation for utility functions. */
#include <stdlib.h>
#include "util.h"
#include "color.h"
/* Print function name as "comment". */
void fprintfunc(FILE *stream, const char *s)
{
	fprintf(stream, FG_BLACK_BRIGHT "%s();\n" ANSI_RESET, s);
}
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
/* Generate random int array */
void randarr_int(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}
/* Return index of smallest array element in range (inclusive). */
int index_min(int *arr, int p, int r)
{
	int ret = p;
	for (int i = p; i <= r; i++)
	{
		if (arr[i] < arr[ret])
		{
			ret = i;
		}
	}
	return ret;
}
/* Return index of largest array element in range (inclusive). */
int index_max(int *arr, int p, int r)
{
	int ret = p;
	for (int i = p; i <= r; i++)
	{
		if (arr[ret] < arr[i])
		{
			ret = i;
		}
	}
	return ret;
}
/* Return lesser of two values. */
int min(int a, int b)
{
	return (a <= b) ? a : b;
}
/* Return greater of two values. */
int max(int a, int b)
{
	return (a >= b) ? a : b;
}
/* Swap array elements by index. */
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
/* Return whether or not indicies in an array are an inversion. */
bool inversion(int *arr, int i, int j)
{
	return (i < j) && (arr[j] < arr[i]);
}
