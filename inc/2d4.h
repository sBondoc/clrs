/* "2d4.h" - Prototypes for 2-4 functions. */
#ifndef TWO_DASH_FOUR_H
#define TWO_DASH_FOUR_H
/* Inversion count in array range brute force. */
int count_inversion_brute(int *arr, int p, int r);
/* Inversion count in array merge step. */
int count_inversion_merge(int *arr, int p, int q, int r);
/* Inversion count in array. */
int count_inversion(int *arr, int p, int r);
#endif
