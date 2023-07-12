#include "hash_tables.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/**
* hash_table_print - Prints a hash table.
* @ht: The hash table to print.
*/

void hash_table_print(const hash_table_t *ht)
{
unsigned long int i;
hash_node_t *node;
int flag = 0;

/* Check if the hash table is NULL */
if (ht == NULL)
return;

printf("{");
for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node != NULL)
{
if (flag == 1)
printf(", ");

/* Print the key/value pair in the desired format */
printf("'%s': '%s'", node->key, node->value);

flag = 1;
node = node->next;
}
}
printf("}\n");
}
