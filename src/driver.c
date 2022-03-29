#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../inc/include.h"

void test_2p1(void)
{
	fprintf(stdout, "test_2p1();\n");
	int size = 10;
	int arr[size];
	randarr_int(arr, size);
	fprintarr_int(stdout, arr, size);
	sort_insertion(arr, size);
	fprintarr_int(stdout, arr, size);
}

void test_2p1d2(void)
{
	fprintf(stdout, "test_2p1d2();\n");
	int size = 10;
	int arr[size];
	randarr_int(arr, size);
	fprintarr_int(stdout, arr, size);
	sort_insertion_nonincreasing(arr, size);
	fprintarr_int(stdout, arr, size);
}

void test_2p1d3(void)
{
	fprintf(stdout, "test_2p1d3();\n");
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

int main(int argc, char *argv[])
{
	fprintf(stdout, "================\n");
	fprintf(stdout, "argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		fprintf(stdout, "%s\n", argv[i]);
	}
	fprintf(stdout, "================\n");
	srand(time(NULL));
	// test_2p1();
	// test_2p1d2();
	test_2p1d3();
	return EXIT_SUCCESS;
}
