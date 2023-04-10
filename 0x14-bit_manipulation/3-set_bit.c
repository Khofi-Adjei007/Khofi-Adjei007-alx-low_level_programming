#include <stdio.h>
#include "main.h"

/**
* set_bit - set bit to 1
* Return: 1 if pass, -1 if failed
* @n: pointer to a number
* @index: given index
*/

int set_bit(unsigned long int *n, unsigned int index)
{
unsigned int copy;

if (index > 64)
	return (-1);

copy = *n;
copy = get_bit(copy, index);

if (copy == 0x1)
	return (1);
*n = (*n) + power(2, index);
return (1);
}

/**
* power - power of base
* @base: base
* @exp: exponent
* Return: base raised to exp
*/

unsigned int power(unsigned int base, unsigned int exp)
{
unsigned int i = 0;
unsigned int raised = 1;


if (exp == 0)
	return (1);

for (i = 0; i < exp; i++)
	raised = raised * base;
return (raised);
}

/**
* get_bit - This gets the bit value at an index
* Return: value
* @n: num
* @index: index given
*/

int get_bit(unsigned long int n, unsigned int index)
{
unsigned int c;

for (c = 0; c < index; c++)
	n >>= 0x1;

return (n & 0x1);
}
