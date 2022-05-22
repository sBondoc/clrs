#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "include.h"

int main(int argc, char *argv[])
{
	#ifdef DEBUG
	fprintf(stdout, FG_BLACK_BRIGHT "================\n");
	fprintf(stdout, "argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		fprintf(stdout, "%s\n", argv[i]);
	}
	fprintf(stdout, "================\n");
	srand(time(NULL));
	#endif
	fprintf(stdout, ANSI_RESET);
	fprintf(stderr, ANSI_RESET);
	if (1 < argc)
	{
		for (int i = 1; i < argc; i++)
		{
			test_by_name(argv[i]);
		}
	}
	else
	{
		fprintf(stderr, "Error: No tests specified.\n");
	}
	return EXIT_SUCCESS;
}
