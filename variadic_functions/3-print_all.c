#include"variadic_functions.h"
#include<stdio.h>
#include<stdarg.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: variable number of arguments to be printed
 *
 * Return: void
 */

void print_all(const char * const format, ...)
{
	va_list bag;
	unsigned int i = 0;
	char *str, *sep = "";

	va_start(bag, format);

	if (format)
	{


		while (format[i] != '\0')
		{
			switch (format[i])
			{
			case 'c':
				printf("%s%c", sep, va_arg(bag, int));
				break;
			case 'i':
				printf("%s%d", sep, va_arg(bag, int));
				break;
			case 'f':
				printf("%s%f", sep, va_arg(bag, double));
				break;
			case 's':
				str = va_arg(bag, char *);
				if (str == NULL)
				str = "(nil)";
				printf("%s%s", sep, str);
				break;
					default:
					i++;
					continue;
			}
			i++;
			sep = ", ";
		}
	}
	va_end(bag);
	printf("\n");
}
