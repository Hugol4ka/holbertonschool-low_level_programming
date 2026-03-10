#include"main.h"
#include<stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: a pointer to the allocated memory, or NULL if it fails
 * or if nmemb or size is 0
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i = 0;
	unsigned int total_byte = nmemb * size;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(total_byte);
	if (ptr == 0)
	{
		return (NULL);
	}
	for (i = 0; i < total_byte; i++)
	{
		ptr[i] = 0;
	}
		return ((void *)ptr);
}
