#include <stdlib.h>
#include <stdio.h>
#include "../inc/include.h"

int main(int argc, char *argv[])
{
	fprintf(stdout, "================\n");
	fprintf(stdout, "argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		fprintf(stdout, "%s\n", argv[i]);
	}
	fprintf(stdout, "================\n");
	int arr[] = {8, 7, 6, 5, 4, 3, 2, 1}, size = sizeof(arr) / sizeof(arr[0]);
	fprintarr_int(stdout, arr, size);
	sort_insertion(arr, size);
	fprintarr_int(stdout, arr, size);
	return EXIT_SUCCESS;
}
