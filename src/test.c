/* "test.c" - Implementation for test functions. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "include.h"

void test_by_name(const char *s)
{
	if (strcmp(s, "util") == 0)
	{
		test_util();
	}
	else if (strcmp(s, "2p1") == 0)
	{
		test_2p1();
	}
	else if (strcmp(s, "2p1d2") == 0)
	{
		test_2p1d2();
	}
	else if (strcmp(s, "2p1d3") == 0)
	{
		test_2p1d3();
	}
	else if (strcmp(s, "2p1d4") == 0)
	{
		test_2p1d4();
	}
	else if (strcmp(s, "2p2d2") == 0)
	{
		test_2p2d2();
	}
	else if (strcmp(s, "2p3") == 0)
	{
		test_2p3();
	}
	else if (strcmp(s, "2p3d2") == 0)
	{
		test_2p3d2();
	}
	else if (strcmp(s, "2p3d4") == 0)
	{
		test_2p3d4();
	}
	else if (strcmp(s, "2p3d5") == 0)
	{
		test_2p3d5();
	}
	else if (strcmp(s, "2p3d7") == 0)
	{
		test_2p3d7();
	}
	else if (strcmp(s, "2d1") == 0)
	{
		test_2d1();
	}
	else if (strcmp(s, "2d2") == 0)
	{
		test_2d2();
	}
	else if (strcmp(s, "2d3") == 0)
	{
		test_2d3();
	}
	else if (strcmp(s, "2d4") == 0)
	{
		test_2d4();
	}
	else if (strcmp(s, "4p1") == 0)
	{
		test_4p1();
	}
	else if (strcmp(s, "4p1d2") == 0)
	{
		test_4p1d2();
	}
	else if (strcmp(s, "4p1d3") == 0)
	{
		test_4p1d3();
	}
	else if (strcmp(s, "all") == 0)
	{
		test_all();
	}
	else
	{
		fprintf(stderr, "Invalid test ID \"%s\".\n", s);
	}
}
void test_util(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, size = sizeof(arr) / sizeof(arr[0]);
	int i = rand() % size, j = rand() % size;
	fprintarr_int(stdout, arr, size);
	randarr_int(arr, size, -100, 100);
	fprintarr_int(stdout, arr, size);
	fprintf(stdout, "Min index: %d\n", index_min(arr, 0, size - 1));
	fprintf(stdout, "(%d, %d) is %san inversion of arr.\n", i, j, (inversion(arr, i, j)) ? "" : "not ");
}
void test_2p1(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_insertion(arr, size);
	fprintarr_int(stdout, arr, size);
}
void test_2p1d2(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_insertion_nonincreasing(arr, size);
	fprintarr_int(stdout, arr, size);
}
void test_2p1d3(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	int key;
	if (rand () < RAND_MAX / 4)
	{
		key = arr[rand() % size];
	}
	else
	{
		key = rand() % 10;
	}
	fprintarr_int(stdout, arr, size);
	fprintf(stdout, "%d found at index %d\n", key, search_linear(arr, size, key));
}
void test_2p1d4(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int n = 4;
	int a[] = {1, 0, 1, 1}, b[] = {1, 1, 0, 0}, c[n + 1];
	add_binarr(a, b, c, n);
	fprintf(stdout, "\t   ");
	fprintarr_int(stdout, a, n);
	fprintf(stdout, "+\t   ");
	fprintarr_int(stdout, b, n);
	fprintf(stdout, "=\t");
	fprintarr_int(stdout, c, n + 1);
}
void test_2p2d2(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_selection(arr, size);
	fprintarr_int(stdout, arr, size);
}
void test_2p3(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_merge(arr, 0, size - 1);
	fprintarr_int(stdout, arr, size);
}
void test_2p3d2(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_merge_no_sentinel(arr, 0, size - 1);
	fprintarr_int(stdout, arr, size);
}
void test_2d1(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_merge_insertion(arr, 0, size - 1, 10);
	fprintarr_int(stdout, arr, size);
}
void test_2d2(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_bubble(arr, size);
	fprintarr_int(stdout, arr, size);
}
void test_2d3(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int a[] = {0, 1, 2, 3}, n = sizeof(a) / sizeof(a[0]), x = 2;
	fprintf(stdout, "a = ");
	fprintarr_int(stdout, a, n);
	fprintf(stdout, "n = %d\nx = %d\n", n, x);
	fprintf(stdout, "horner = %d\npolynomial = %d\n", horner(a, n, x), polynomial(a, n,x));
}
void test_2d4(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int arr[] = {2, 3, 8, 6, 1}, size = sizeof(arr) / sizeof(arr[0]);
	fprintarr_int(stdout, arr, size);
	fprintf(stdout, "Inversions: %d\n", count_inversion(arr, 0, size - 1));
}
void test_2p3d4(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	sort_insertion_recursive(arr, size - 1);
	fprintarr_int(stdout, arr, size);
}
void test_2p3d5(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	int key = arr[0];
	sort_merge(arr, 0, size - 1);
	fprintarr_int(stdout, arr, size);
	fprintf(stdout, "Found %d at index %d.\n", key, binary_search(arr, key, 0, size - 1));
}
void test_2p3d7(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int size = 10;
	int arr[size];
	randarr_int(arr, size, 0, 100);
	fprintarr_int(stdout, arr, size);
	int sum = arr[size - 2] + arr[size - 1];
	bool b = sum_exists(arr, size, sum);
	fprintf(stdout, "Sum of %d %s in the array.\n", sum, (b) ? "exists" : "does not exist");
}
void test_4p1(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}, size = sizeof(arr) / sizeof(arr[0]);
	fprintarr_int(stdout, arr, size);
	struct Subarray sa = max_subarray(arr, 0, size - 1);
	fprintf(stdout, "Max subarray: [%d, %d]\nSum: %d\n", sa.p, sa.r, sa.sum);
}
void test_4p1d2(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}, size = sizeof(arr) / sizeof(arr[0]);
	fprintarr_int(stdout, arr, size);
	struct Subarray sa = max_subarray_brute(arr, size);
	fprintf(stdout, "Max subarray: [%d, %d]\nSum: %d\n", sa.p, sa.r, sa.sum);
}
void test_4p1d3(void)
{
	#ifdef DEBUG
	fprintfunc(stdout, __func__);
	#endif
	for (int n = 1; n < 10; n++)
	{
		int arr[n];
		randarr_int(arr, n, -100, 100);
		fprintarr_int(stdout, arr, n);
	}
}
void test_all(void)
{
	test_util();
	test_2p1();
	test_2p1d2();
	test_2p1d3();
	test_2p1d4();
	test_2p2d2();
	test_2p3();
	test_2p3d2();
	test_2d1();
	test_2d2();
	test_2d3();
	test_2d4();
}
