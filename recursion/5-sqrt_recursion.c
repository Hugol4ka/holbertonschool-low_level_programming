#include "main.h"

/**
 * _sqrt_helper - fonction auxiliaire pour tester les nombres un par un
 * @n: le nombre cible
 * @i: le candidat actuel à tester
 *
 * Return: la racine carrée ou -1
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
	return (-1);

	if (i * i == n)
	return (i);

	return (_sqrt_helper(n, i + 1));
}



/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the natural square root, or -1 if it doesn't exist
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 0));
}
