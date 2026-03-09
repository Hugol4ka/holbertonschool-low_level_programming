#include"main.h"
#include<stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string, or NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *new_str;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL) /*traitement pour une chaine vide*/
	s1 = "";
	if (s2 == NULL)
	s2 = "";
		while (s1[len1] != '\0')
		{
			len1++;
		}
		while (s2[len2] != '\0')
		{
			len2++;
		}
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
	return (NULL);
	i = 0;
		while (s1[i] != '\0')
		{
			new_str[i] = s1[i];
			i++;
		}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
