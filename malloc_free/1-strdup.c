#include"main.h"
#include<stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 * or if str is NULL
 */

char *_strdup(char *str)
{
	char *copy;
	unsigned int i = 0;

	if (str == 0)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
	i++;
	}
		copy = malloc(sizeof(char) * (i + 1)); /* +1 pour inclure carct nul '\0' */
		if (copy == 0)
		{
			return (NULL);
		}
			i = 0;
			while (str[i] != '\0') /*copie mais sans le carct nul*/
			{
			copy[i] = str[i];
			i++;
			}
			copy[i] = '\0'; /*Annonce le stop apres copie*/
			return (copy);
}
