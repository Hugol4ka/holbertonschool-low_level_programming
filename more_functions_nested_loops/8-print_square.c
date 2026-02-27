#include"main.h"

/**
 * print_square - prints a square, followed by a new line
 * @size: size of the square
 *
 * Return: void
 */

void print_square(int size)
{
int height;
int weight;
	if (size <= 0)
	{
		_putchar ('\n');
	}
		else
		{
			for (height = 0; height < size; height++)
			{
				for (weight = 0; weight < size; weight++)
				{
					_putchar('#');
				}
				_putchar('\n');
			}
		}
}
