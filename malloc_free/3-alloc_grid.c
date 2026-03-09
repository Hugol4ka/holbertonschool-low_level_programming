#include"main.h"
#include<stdlib.h>

/**
 * alloc_grid - creates a 2D array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to 2D array, or NULL
 */

int **alloc_grid(int width, int height)

{
	int **grid;
	int i = 0;
	int j = 0;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
		grid = malloc(sizeof(int *) * height);
		if (grid == NULL) /*verification des adresses*/
		{
			return (NULL);
		}
		while (i < height)
		{
		grid[i] = malloc(sizeof(int) * width);
			if (grid[i] == NULL)
			{
				int k = 0;

				while (k < i) /*Debut du bloc de nettoyage*/
				{
				free(grid[k]);
				k++;
				}
				free(grid);
				return (NULL); /*fin du bloc de nettoyage*/
			}
			j = 0;
			while (j < width)
			{
				grid[i][j] = 0;
				j++;
			}
		i++;
		}
		return (grid);
	}
