/* "4p2.c" - Implementation for 4.2 functions. */
#include "4p2.h"
#include "util.h"
void square_matrix_multiply(int *matrix_c, int *matrix_a, int *matrix_b, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			matrix_c[matrix_index(i, j, rows)] = 0;
			for (int k = 0; k < rows; k++)
			{
				matrix_c[matrix_index(i, j, rows)] += matrix_a[matrix_index(i, k, rows)] * matrix_b[matrix_index(k, j, rows)];
			}
		}
	}
}
