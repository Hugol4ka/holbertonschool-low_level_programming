#include<stdio.h>
#include "main.h"

/**
* main - Entry Point
*
* Return: Always 0
*/
	int main(void)
	{
		int i;
		char str[] = {'_', 'p', 'u', 't', 'c', 'h', 'a', 'r'};

		for (i = 0; i < 8; i++)
			{
			_putchar(str[i]);
			}
		_putchar('\n');
		return (0);
	}
