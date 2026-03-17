#include"variadic_functions.h"
#include<stdio.h>
#include<stdarg.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: the string to be printed between the strings
 * @n: the number of strings passed to the function
 * @...: a variable number of strings to be printed
 *
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list bag;
	char *str;
	unsigned int i = 0;

	va_start(bag, n);

	while (i < n)
	{
	str = va_arg(bag, char *);

		if (str == NULL)
		printf("(nil)");
		else
		printf("%s", str);

		if (separator != NULL && i < n - 1)
		printf("%s", separator);

	i++;
	}
	va_end(bag);
	printf("\n");
}
