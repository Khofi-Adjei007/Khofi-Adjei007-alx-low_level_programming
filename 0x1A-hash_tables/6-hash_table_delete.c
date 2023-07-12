#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node, *next_node;

    /* Check if the hash table is NULL */
    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            next_node = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next_node;
        }
    }

    free(ht->array);
    free(ht);
}
