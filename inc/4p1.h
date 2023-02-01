/* "4p1.h" - Prototypes for 4.1 functions. */
#ifndef FOUR_POINT_ONE_H
#define FOUR_POINT_ONE_H
/* Subarray struct */
struct Subarray
{
	int p;
	int r;
	int sum;
};
/* Find max subarray crossing midpoint. */
struct Subarray max_subarray_crossing(int *arr, int p, int q, int r);
/* Find max subarray. */
struct Subarray max_subarray(int *arr, int p, int r);
#endif
