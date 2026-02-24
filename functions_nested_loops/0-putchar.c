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
			putchar(str[i]);
			}
		putchar('\n');
		return (0);
	}
