#include"main.h"
/**
 * swap_int - swaps the values of two integers
 * @a: integer 1
 * @b: integer 2
 *
 * Return: void
 */

void swap_int(int *a, int *b)  /* a = 98  ; b = 42 */
{
	int memory;

	memory = *a; /*lecture de la valeur stocké : 98 et copie dans memory*/
	*a = *b; /*ecrasement: la valeur 42 va maintenant apparaitre en a*/
	*b = memory; /*nouvelle valeurs a = 42 ; b = 98*/
}
