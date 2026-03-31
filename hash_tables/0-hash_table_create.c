#include"hash_tables.h"
#include<stdlib.h>

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table,
 * or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	if (size == 0)
		return (NULL);

	/*Allocation de la structure*/
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
	return (NULL);

	/*Création du tableau ht->array*/
	ht->array = calloc(size, sizeof(hash_node_t *));
	if (ht->array == NULL)
	{
		free(ht); /*Libérer la mémoire pour déchets*/
		return (NULL);
	}

	ht->size = size;
	return (ht);
}
