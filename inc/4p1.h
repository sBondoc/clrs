/* "4p1.h" - Prototypes for 4.1 functions. */
#ifndef FOUR_POINT_ONE_H
#define FOUR_POINT_ONE_H
#include "subarray.h"
/* Find max subarray crossing midpoint. */
struct Subarray max_subarray_crossing(int *arr, int p, int q, int r);
/* Find max subarray. */
struct Subarray max_subarray(int *arr, int p, int r);
#endif
