/* "2p1d4.c" - Implementation for 2.1-4 functions. */
#include "../inc/2p1d4.h"
/* Add binary digits */
void add_binarr(int *a, int *b, int *c, int n)
{
	int carry = 0;
	for (int i = n; 0 < i; i--)
	{
		c[i] = (a[i - 1] != b[i - 1]) != carry;
		carry = (a[i - 1] && b[i - 1]) || (a[i - 1] && carry) || (b[i - 1] && carry);
	}
	c[0] = carry;
}
