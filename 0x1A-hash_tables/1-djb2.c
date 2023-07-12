/**
* hash_djb2 - Hash function implementing the djb2 algorithm.
* @str: The input string to hash.
*
* Return: The hash value as an unsigned long int.
*/

unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash = 5381;  /* Initial hash value */
int c;

/* Iterate over each character in the string */
while ((c = *str++))
{
hash = ((hash << 5) + hash) +c;  /* hash = hash * 33 +c */
}

return (hash);
}
