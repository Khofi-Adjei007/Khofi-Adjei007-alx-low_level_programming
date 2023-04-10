#include <stdio.h>
#include "main.h"

/**
* flip_bits - two function argument
* @n: number to compare bits
* @m: second number to compare bits
* Description: returns the number of bits needed to flip
* Return: total flip
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int value;
unsigned int count = 0;

value = n ^ m;

while (value != 0)
{
if ((value & 1) == 1)
	count++;
value = value >> 1;
}
return (count);
}
