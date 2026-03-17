#include"3-calc.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * main - effectuer des opérations simple
 * @argc: argument compter
 * @argv: argument vecteur
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int a, b, result;
	int (*f)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	f = get_op_func(argv[2]);

	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

		result = f(a, b);
		printf("%d\n", result);
		return (0);
}



















