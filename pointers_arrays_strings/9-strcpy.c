#include"main.h"

/**
 * _strcpy - copie la chaîne pointée par src, y compris le
 * caractère nul (\0), vers le tampon pointé par dest.
 * @dest: le tampon de destination où la chaîne est copiée.
 * @src: la chaîne source à copier.
 *
 * Return: le pointeur vers dest.
 */


char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
