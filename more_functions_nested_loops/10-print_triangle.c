#include"main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: size of the triangle
 *
 * Return: void
 */

void print_triangle(int size)
{
int l, s, d;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (l = 1; l <= size; l++)
		{
			for (s = 0; s < (size - l); s++)
			{
				_putchar(' ');
			}
			for (d = 0; d < l; d++)
			{
				_putchar('#');
			}
				_putchar('\n');
		}
	}
}
