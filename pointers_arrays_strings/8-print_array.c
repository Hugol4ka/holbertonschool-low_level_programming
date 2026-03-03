#include"main.h"
#include <stdio.h>
/**
 * print_array - imprime n éléments d'un tableau d'entiers,
 * suivis d'une nouvelle ligne.
 * @a: le pointeur vers le tableau d'entiers à imprimer.
 * @n: le nombre d'éléments à afficher.
 *
 * Return: void.
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)
		printf(", ");
	}
	printf("\n");
}
