#include<stdarg.h>
#include"variadic_functions.h"
#include<stdio.h>

/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: the string to be printed between numbers
 * @n: the number of integers passed to the function
 * @...: a variable number of numbers to be printed
 *
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list bag;
	unsigned int i = 0;

	va_start(bag, n);

	while (i < n)
	{
		printf("%d", va_arg(bag, int));
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
		i++;
	}
	va_end(bag);
	printf("\n");
}
