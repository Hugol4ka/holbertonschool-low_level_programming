#include"main.h"
/**
 * _atoi - convertit une chaîne de caractères en entier.
 * @s: la chaîne à convertir.
 *
 * Description: prend en compte tous les signes - et + précédant
 * le nombre. Si aucun nombre n'est présent, retourne 0.
 *
 * Return: l'entier converti depuis la chaîne.
 */


int _atoi(char *s)
{
int i = 0;
int result = 0;
int sign = 1;
int found = 0;

while (s[i] != '\0')
{
	if (found == 0 && s[i] == '-')
	{
		sign *= -1;
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
		found = 1;
		result = result * 10 - (s[i] - '0');
	}
	else if (found == 1)
	{
		break;
	}
	i++;
}
if (sign == 1)
	return (-result);
else
	return (result);
}
