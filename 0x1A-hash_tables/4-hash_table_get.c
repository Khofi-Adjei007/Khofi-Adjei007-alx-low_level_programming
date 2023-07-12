#include "hash_tables.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>


/**
* hash_table_get - Retrieves a value associated with a key in a hash table.
* @ht: The hash table to look into.
* @key: The key to search for.
*
* Return: The value associated with the element, or NULL if key couldn't be found.
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int index;
hash_node_t *temp;

/* Check if the key or hash table is NULL */
if (key == NULL || ht == NULL)
return NULL;

/* Check if the key is an empty string */
if (key[0] == '\0')
return NULL;

/* Calculate the index for the given key */
index = key_index((const unsigned char *)key, ht->size);

/* Traverse the linked list at the calculated index */
temp = ht->array[index];
while (temp != NULL)
{
/* If the key is found, return the associated value */
if (strcmp(temp->key, key) == 0)
return temp->value;

temp = temp->next;
}

return NULL; /* Key couldn't be found */
}
