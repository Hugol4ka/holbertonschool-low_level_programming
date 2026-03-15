#include"main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes it with a char
 * @size: the size of the array to be created
 * @c: the char to initialize the array with
 *
 * Return: a pointer to the array, or NULL if it fails or size is 0
 */

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

		if (size == 0)
		{
			return (NULL);
		}
	str = malloc(sizeof(char) * size);
		if (str == NULL)
		{
			return (NULL);
		}
			i = 0;
			while (i < size)
			{
				str[i] = c;
				i++;
			}
		return (str);
}
