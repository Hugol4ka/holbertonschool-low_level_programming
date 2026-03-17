#include<stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of parameters
 * Return: sum or 0 if n is 0
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i = 0;
	int sum = 0;

	va_list bag;

	if (n == 0)
	return (0);

	va_start(bag, n);

	while (i < n)
	{
		sum = sum + va_arg(bag, int);
		i++;
	}
	va_end(bag);

	return (sum);
}

