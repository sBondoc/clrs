/* "util.c" - Definitions for utility functions. */
#include <stdio.h>
#include "util.h"

/* Print int array */
void fprintarr_int(FILE *stream, int *arr, int size)
{
	fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stream, "%d, ", arr[i]);
	}
	fprintf(stream, "%d}\n", arr[size - 1]);
}

/* Print char array */
void fprintarr_char(FILE *stream, char *arr, int size)
{
	fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stream, "\'%c\', ", arr[i]);
	}
	fprintf(stream, "\'%c\'}\n", arr[size - 1]);
}

/* Print str (char *) array */
void fprintarr_str(FILE *stream, char **arr, int size)
{
	fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stream, "\"%s\", ", arr[i]);
	}
	fprintf(stream, "\"%s\"}\n", arr[size - 1]);
}
