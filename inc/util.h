/* "util.h" - Prototypes for utility functions. */
#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdbool.h>
/* Print function name as "comment". */
void fprintfunc(FILE *stream, const char *s);
/* Print int array. */
void fprintarr_int(FILE *stream, int *arr, int size);
/* Generate random int array. */
void randarr_int(int *arr, int size, int low, int high);
/* Return index of smallest array element in range (inclusive). */
int index_min(int *arr, int p, int r);
/* Return index of largest array element in range (inclusive). */
int index_max(int *arr, int p, int r);
/* Return lesser of two values. */
int min(int a, int b);
/* Return greater of two values. */
int max(int a, int b);
/* Swap array elements by index. */
void swap(int *arr, int i, int j);
/* Return whether or not indices in an array are an inversion. */
bool inversion(int *arr, int i, int j);
#endif
