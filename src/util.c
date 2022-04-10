/* "util.h" - Implementation for utility functions. */
#include <stdlib.h>
#include "../inc/util.h"
#include "../inc/color.h"
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
