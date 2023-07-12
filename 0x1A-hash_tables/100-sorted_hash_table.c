#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table.
 *
 * Return: A pointer to the newly created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    /* Allocate memory for the hash table */
    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return NULL;

    /* Allocate memory for the array */
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return NULL;
    }

    /* Initialize the elements of the array to NULL */
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->size = size;
    ht->shead = NULL;
    ht->stail = NULL;

    return ht;
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: The sorted hash table to add/update the key/value pair.
 * @key: The key to add/update.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *node;

    /* Check if the key or hash table is NULL */
    if (key == NULL || ht == NULL)
        return 0;

    /* Check if the key is an empty string */
    if (key[0] == '\0')
        return 0;

    /* Calculate the index for the given key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Check if the key already exists in the hash table */
    node = ht->array[index];
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
        {
            free(node->value);
            node->value = strdup(value);
            return 1; /* Success: Key updated */
        }
        node = node->next;
    }

    /* Create a new node */
    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return 0; /* Failure: Memory allocation failed */

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Insert the node into the sorted linked list */
    if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
    {
        new_node->snext = ht->shead;
        ht->shead = new_node;
    }
    else
    {
        node = ht->shead;
        while (node->snext != NULL && strcmp(key, node->snext->key) > 0)
            node = node->snext;

        new_node->snext = node->snext;
        node->snext = new_node;
    }

    /* Update the tail of the sorted linked list */
    if (new_node->snext == NULL)
        ht->stail = new_node;

    return 1; /* Success: New key added */
}

/**
 * shash_table_get - Retrieves a value associated with a key in a sorted hash table.
 * @ht: The sorted hash table to look into.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *node;

    /* Check if the key or hash table is NULL */
    if (key == NULL || ht == NULL)
        return NULL;

    /* Check if the key is an empty string */
    if (key[0] == '\0')
        return NULL;

    /* Calculate the index for the given key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Traverse the linked list at the calculated index */
    node = ht->array[index];
    while (node != NULL)
    {
        /* If the key is found, return the associated value */
        if (strcmp(node->key, key) == 0)
            return node->value;

        node = node->next;
    }

    return NULL; /* Key couldn't be found */
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    int flag = 0;

    /* Check if the hash table is NULL */
    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;
    while (node != NULL)
    {
        if (flag == 1)
            printf(", ");

        /* Print the key/value pair in the desired format */
        printf("'%s': '%s'", node->key, node->value);

        flag = 1;
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table to print in reverse order.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    int flag = 0;

    /* Check if the hash table is NULL */
    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;
    while (node != NULL)
    {
        if (flag == 1)
            printf(", ");

        /* Print the key/value pair in the desired format */
        printf("'%s': '%s'", node->key, node->value);

        flag = 1;
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *node, *next_node;

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
