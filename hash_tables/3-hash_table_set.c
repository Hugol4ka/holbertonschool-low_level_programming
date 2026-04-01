#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds or updates an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add (cannot be an empty string).
 * @value: The value associated with the key.
 *
 * Return: 1 if success, 0 otherwise.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *tmp, *new;
	char *val_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	/*Vérifier si la clé existe déjà pour la mettre à jour */
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = val_copy;
			return (1);
		}
		tmp = tmp->next;
	}
	/* Créer un nouveau nœud si la clé n'existe pas */
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(val_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(val_copy);
		free(new);
		return (0);
	}
	new->value = val_copy; /*Ajouter le nouveau nœud au DEBUT de la liste */
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}

