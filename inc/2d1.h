/* "2d1.h" - Prototypes for 2-1 functions. */
#ifndef TWO_DASH_ONE_H
#define TWO_DASH_ONE_H
/* Insertion sort on range. */
void sort_insertion_range(int *arr, int p, int r);
/* Hybrid recursive merge/iterative insertion sort merge step. */
void sort_merge_insertion_merge(int *arr, int p, int q, int r);
/* Hybrid recursive merge/iterative insertion sort. */
void sort_merge_insertion(int *arr, int p, int r, int k);
#endif
