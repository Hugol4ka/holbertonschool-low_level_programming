#include"3-calc.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * get_op_func - lien entre l'operateur choisis et le calcul.
 * @s: pointeur vers la chaîne de caractères contenant l'opérateur ex: "+"
 * @op_t ops - lien entre l'opérateur et la fonction qui correspond.
 *
 * Return: NULL
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};
	int i = 0;
}
