#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector (array of strings)
 *
 * Return: 0 if success, 1 if an error occurs
 */

int main(int argc, char *argv[])
{
	int i = 1;
	int j;
	int sum = 0;

	if (argc == 1)
		{
		printf("0\n");
		return (0);
		}

	while (i < argc)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
		i++;
	}
	printf("%d\n", sum);
	return (0);
}
