#include"main.h"

/**
 * leet - Encodes a string into 1337
 * @s: The string to encode
 *
 * Return: A pointer to the encoded string
 */

char *leet(char *s)
{
	int i = 0;
	int j;
	char letter[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	while (s[i] != '\0')
	{
	j = 0;
		while (letter[j] != '\0')
		{
			if (s[i] == letter[j])
			{
			s[i] = numbers[j];
			}
			j++;
		}
		i++;
	}
	return (s);
}
