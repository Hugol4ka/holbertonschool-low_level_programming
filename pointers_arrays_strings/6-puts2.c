#include"main.h"

/**
 * puts2 - imprime un caractère sur deux d'une chaîne,
 * en commençant par le premier.
 * @str: la chaîne de caractères à traiter.
 *
 * Return: void.
 */

void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
	i++;
	}
	_putchar('\n');
}
