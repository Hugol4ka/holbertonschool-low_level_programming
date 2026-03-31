#include"hash_tables.h"
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *next_node;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			/*On mémorise la suite */
			next_node = node->next;

			/*On libère la clé */
			free(node->key);

			/*On libère la valeur */
			free(node->value);

			/*On libère le nœud lui-même */
			free(node);

			/*On passe à la suite mémorisée */
			node = next_node;
		}
	}
	/*On libère le tableau de pointeurs et la structure */
	free(ht->array);
	free(ht);
}

