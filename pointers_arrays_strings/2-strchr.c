#include"main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: the string to check
 * @c: the character to find
 *
 * Return: a pointer to the first occurrence of the character c in s,
 * or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	i++;
	}
		if (s[i] == c)
		{
			return (&s[i]);
		}
	return (NULL);
}
