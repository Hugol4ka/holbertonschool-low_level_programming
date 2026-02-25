#include"main.h"

/**
 * print_sign - checks for number positive or negative
 * @n: the character to be checked
 * int n for variable number.
 * Return: '+' if c is a positiv, else if return '-' if return 0
 */

int print_sign(int n)

	{
		if (n > 0)
		{
			_putchar ('+');
			return (1);
		}
			else if (n < 0)
			{
				_putchar ('-');
				return (-1);
			}
				else
				_putchar ('0');
				return (0);
	}
