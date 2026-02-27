#include"main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character \ should be printed
 *
 * Return: void
 */

void print_diagonal(int n)
{
	int s;
	int e;

	if (n <= 0)
	{
	_putchar('\n');
	}
		else
		{
			for (e = 0; e < n; e++)
			{
				for (s = 0; s < e; s++)
				{
				_putchar(' ');
				}
				_putchar('\\');
				_putchar('\n');
			}
		}
}
