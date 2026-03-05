#include"main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the initial segment
 * @accept: the bytes to include
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	int i = 0;
	int j;
	int equal = 0;

	while (s[i] != '\0')
		{
			j = 0;
			while (accept[j])
			{
				if (s[i] == accept[j])
				{
					equal = 1;
					break;   /*Arret de boucle*/
				}
				j++;
			}
			if (equal == 0)
			{
				return (i);
			}
			i++;
			equal = 0;
		}
	return (i);
}
