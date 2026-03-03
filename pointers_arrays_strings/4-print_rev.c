#include"main.h"
/**
 *print_rev - Affiche une chaine de caractère en reverse
 *@s: pointeur vers chaine de caractère
 */

void print_rev(char *s)
	{
		int i = 0;

		while (s[i] != '\0')
		{
			i++;
		}
			while (i > 0)
			{
			i--;
			_putchar (s[i]);
			}
		_putchar('\n');
	}
