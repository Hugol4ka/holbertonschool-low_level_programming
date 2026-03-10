#include"main.h"
#include<stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes of s2 to concatenate
 *
 * Return: a pointer to the newly allocated space in memory
 * or NULL if the function fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int len1 = 0, len2 = 0, i, j;
char *result;

if (s1 == NULL)
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
		if (n >= len2)
		{
			n = len2;
		}
	result = malloc(len1 + n + 1);
		if (result == NULL)
		{
		return (NULL);
		}
			for (i = 0; s1[i] != '\0'; i++)
			result[i] = s1[i];
			for (j = 0; j < n; j++)
			result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}
