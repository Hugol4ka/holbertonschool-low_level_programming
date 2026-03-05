#include"main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers.
 * @a: pointer to the start of the matrix (vu comme un tableau simple)
 * @size: the width/height of the matrix
 *
 * Return: void
 */

void print_diagsums(int *a, int size)
{
	long i;
	int sum01 = 0;
	int sum02 = 0;

	for (i = 0; i < size; i++)
	{
		sum01 += a[i * (size + 1)];
		sum02 += a[(i + 1) * (size - 1)];
	}
	printf("%d, %d\n", sum01, sum02);
}
