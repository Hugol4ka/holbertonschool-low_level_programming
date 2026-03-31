#include"hash_tables.h"
#include<stdio.h>

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table.
 *
 * Description: Prints the key/value pairs in the order they appear
 * in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int comma = 0;
	hash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
	node = ht->array[i];
		while (node != NULL)
		{
			if (comma == 1)
			{
				printf(", ");
			}
			comma = 1;
			printf("'%s': '%s'", node->key, node->value);
			node = node->next;
		}
	}
	printf("}\n");
}
