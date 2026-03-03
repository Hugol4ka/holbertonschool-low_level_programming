#include"main.h"

/**
 * puts_half - imprime la seconde moitié d'une chaîne.
 * @str: la chaîne à traiter.
 */

void puts_half(char *str)
{
	int i = 0;
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	i = len - (len / 2); /*soustraction car nombre impairs*/

		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
	_putchar('\n');
}
