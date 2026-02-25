#include"main.h"

/**
* print_last_digit - prints the last digit of a number
* @n: the number to extract the last digit from
*
* Return: the value of the last digit
*/

int print_last_digit(int n)

{
	int last = n % 10;

	if (last < 0)

		{
		last = last * -1;
		}
			_putchar(last + '0'); /*le (c+'0') permet d'eviter d'avoir la valeur ASCII*/
			return (last);
	}
