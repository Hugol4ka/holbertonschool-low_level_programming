#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *tmp, *new_node;

    /* 1. Sécurité */
    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    /* 2. Trouver l'index */
    index = key_index((const unsigned char *)key, ht->size);

    /* 3. UPDATE : Si la clé existe déjà */
    tmp = ht->array[index];
    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = strdup(value);
            if (tmp->value == NULL)
                return (0);
            return (1); /* On s'arrête ici si on a mis à jour */
        }
        tmp = tmp->next;
    }

    /*CRÉATION : Si la clé n'existe pas encore */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    /* On ajoute au début de la liste */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}

