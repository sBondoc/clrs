/* "util.h" - Prototypes for utility functions. */
#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
/* Print function name as "comment". */
void fprintfunc(FILE *stream, const char *s);
/* Print int array. */
void fprintarr_int(FILE *stream, int *arr, int size);
/* Generate random int array. */
void randarr_int(int *arr, int size);
#endif
