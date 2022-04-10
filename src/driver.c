#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../inc/include.h"

void test_2p1(void)
{
	fprintfunc(stdout, __func__);
	int size = 10;
	int arr[size];
	randarr_int(arr, size);
	fprintarr_int(stdout, arr, size);
	sort_insertion(arr, size);
	fprintarr_int(stdout, arr, size);
}

void test_2p1d2(void)
{
	fprintfunc(stdout, __func__);
	int size = 10;
	int arr[size];
	randarr_int(arr, size);
	fprintarr_int(stdout, arr, size);
	sort_insertion_nonincreasing(arr, size);
	fprintarr_int(stdout, arr, size);
}

void test_2p1d3(void)
{
	fprintfunc(stdout, __func__);
	int size = 10;
	int arr[size];
	randarr_int(arr, size);
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
	fprintfunc(stdout, __func__);
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
	fprintfunc(stdout, __func__);
	int size = 10;
	int arr[size];
	randarr_int(arr, size);
	fprintarr_int(stdout, arr, size);
	sort_selection(arr, size);
	fprintarr_int(stdout, arr, size);
}

void test_2p3(void)
{
	fprintfunc(stdout, __func__);
	int size = 10;
	int arr[size];
	randarr_int(arr, size);
	fprintarr_int(stdout, arr, size);
	sort_merge(arr, 0, size - 1);
	fprintarr_int(stdout, arr, size);
}

int main(int argc, char *argv[])
{
	fprintf(stdout, FG_BLACK_BRIGHT "================\n");
	fprintf(stdout, "argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		fprintf(stdout, "%s\n", argv[i]);
	}
	fprintf(stdout, "================\n" ANSI_RESET);
	srand(time(NULL));
	// test_2p1();
	// test_2p1d2();
	// test_2p1d3();
	// test_2p1d4();
	// test_2p2d2();
	test_2p3();
	return EXIT_SUCCESS;
}
