#include"function_pointers.h"
#include<stdlib.h>
#include<stdio.h>

/**
 * array_iterator - Exécute une fonction sur chaque élément d'un tableau.
 * @array: Pointeur vers le tableau d'entiers.
 * @size: Taille du tableau.
 * @action: Pointeur vers la fonction à utiliser pour chaque élément.
 *
 * Return: Rien.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if ((array == NULL) || (action == NULL))
	return;

	int i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
