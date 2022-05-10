/* "2d3.c" - Implementation for 2-3 functions. */
#include "2d3.h"
/* Horner's rule for polynomial evaluation. */
int horner(int a[], int n, int x)
{
	int ret = 0;
	for (int i = n - 1; -1 < i; i--)
	{
		ret = a[i] + x * ret;
	}
	return ret;
}
/* Polynomial evaluation. */
int polynomial(int a[], int n, int x)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		int term = 1;
		for (int j = 0; j < i; j++)
		{
			term *= x;
		}
		ret += a[i] * term;
	}
	return ret;
}
