/* "2d3.c" - Implementation for 2-3 functions. */
#include "../inc/2d3.h"
/* Horner's rule for polynomial evaluation. */
int horner(int a[], int n, int x)
{
	int ret = 0;
	for (int i = n - 1; -1 < i; i--)
	{
		ret = a[i] + (x * ret);
	}
	return ret;
}
