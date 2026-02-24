#include  <stdio.h>

/**
 *
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void) 
{
	char ch = 'a';

	while(ch <= 'z')
	{
	putchar(ch);
	ch++;
	printf("%c",ch)
	}

	putchar('\n');

	return 0;
}

