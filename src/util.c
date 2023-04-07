/* "util.c" - Implementation for utility functions. */
#include <stdlib.h>
#include <math.h>
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
/* Print matrix. */
void fprintmatrix(FILE *stream, int *arr, int rows, int cols)
{
	int max_candidate = floor(log10(arr[index_max(arr, 0, rows * cols - 1)])) + 1,
	min_candidate = arr[index_min(arr, 0, rows * cols - 1)];
	if (min_candidate < 0)
	{
		min_candidate = floor(log10(-1 * min_candidate)) + 2;
	}
	int max_length = max(max_candidate, min_candidate);
	fprintf(stream, "\u250c%*s\u2510\n", (max_length + 1) * cols + 1, "");
	for (int i = 0; i < rows; i++)
	{
		fprintf(stream, "\u2502 %*d ", max_length, arr[matrix_index(i, 0, cols)]);
		for (int j = 1; j < cols - 1; j++)
		{
			fprintf(stream, "%*d ", max_length, arr[matrix_index(i, j, cols)]);
		}
		fprintf(stream, "%*d \u2502\n", max_length, arr[matrix_index(i, cols - 1, cols)]);
	}
	fprintf(stream, "\u2514%*s\u2518\n", (max_length + 1) * cols + 1, "");
}
/* Transform matrix index. */
int matrix_index(int i, int j, int cols)
{
	return i * cols + j;
}
/* Generate random int array */
void randarr_int(int *arr, int size, int low, int high)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = low + rand() % (high - low);
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
