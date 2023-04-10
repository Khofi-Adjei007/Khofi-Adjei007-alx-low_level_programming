#include "main.h"

/**
* int set_bit - a function that has two arguments
* @n: a pointer to value
* @index: the position to change bit
* Description: sets the value of a bit to 1 at a given index
* Return: 1 if pass and -1 if fail
*/
int set_bit(unsigned long int *n, unsigned int index)
{
if (index >= (sizeof(*n) * 8))
return (-1);

*n |= 1 << index;
return (1);

}
