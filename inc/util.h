/* "util.h" - Prototypes for utility functions. */
#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
/* Print int array. */
void fprintarr_int(FILE *stream, int *arr, int size);
/* Generate random int array. */
void randarr_int(int *arr, int size);
#endif
