#include"function_pointers.h"

/**
 * int_index - Cherche un entier dans un tableau.
 * @array: Pointeur vers le tableau d'entiers.
 * @size: Nombre d'éléments dans le tableau.
 * @cmp: Pointeur vers la fonction de comparaison.
 *
 * Return: L'index du premier élément pour lequel cmp ne retourne pas 0,
 * ou -1 si aucune correspondance n'est trouvée ou si size <= 0.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
	return (-1);
	if ((array == NULL) || (cmp == NULL))
	return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		return (i);
	}
	return (-1);
}
