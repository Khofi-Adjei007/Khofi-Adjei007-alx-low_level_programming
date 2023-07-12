#include "hash_tables.h"

/**
* hash_table_set - Adds an element to a hash table.
* @ht: The hash table to add/update the key/value pair.
* @key: The key to add/update.
* @value: The value associated with the key.
*
* Return: 1 if successful, 0 otherwise.
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *new_node, *temp;

/* Check if the key or hash table is NULL */
if (key == NULL || ht == NULL)
return (0);

/* Check if the key is an empty string */
if (key[0] == '\0')
return (0);

/* Calculate the index for the given key */
index = key_index((const unsigned char *)key, ht->size);

/* Check if there is an existing node at the index */
temp = ht->array[index];
while (temp != NULL)
{
/* If the key already exists, update the value */
if (strcmp(temp->key, key) == 0)
{
free(temp->value);
temp->value = strdup(value);
return (1); /* Success: Key updated */
}
temp = temp->next;
}

/* Create a new node and add it to the beginning of the list */
new_node = malloc(sizeof(hash_node_t));
if (new_node == NULL)
return (0); /* Failure: Memory allocation failed */

new_node->key = strdup(key);
new_node->value = strdup(value);
new_node->next = ht->array[index];
ht->array[index] = new_node;

return (1); /* Success: New key added */
}
