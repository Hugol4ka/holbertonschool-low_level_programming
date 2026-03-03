#include"main.h"
/**
 * rev_string - inverse une chaîne de caractères
 * @s: pointeur vers la chaîne de caractères à modifier
 *
 * Return: void
 */

void rev_string(char *s)

{
	int i = 0;
	int id = 0;
	char temp;

	while (s[id] != '\0')
	{
		id++;
	}
	id--;

	while (i < id)
	{
		temp = s[i];
		s[i] = s[id];
		s[id] = temp;
		i++;
		id--;
	}

}


