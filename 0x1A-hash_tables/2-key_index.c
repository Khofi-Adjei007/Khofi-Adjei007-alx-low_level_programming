#include "hash_tables.h"

/**
* key_index - Gives the index of a key in a hash table array.
* @key: The key to calculate the index for.
* @size: The size of the array of the hash table.
*
* Return: The index at which the key/value pair should be stored.
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash_value;
unsigned long int index;

/* Calculate the hash value using the djb2 hash function */
hash_value = hash_djb2(key);

/* Compute the index by performing modulo operation on the hash value */
index = hash_value % size;

return (index);
}
