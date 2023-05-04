#include "main.h"
/**
* get_bit - function to retrieve the value of a bit at a given index
* @n: the unsigned long int to retrieve the bit from
* @index: the index of the bit to retrieve
*
* This function takes an unsigned long int and a bit index and returns
* the value of the bit at the given index. The bit index is 0-based,
* meaning that the least significant bit has an index of 0, and the
* most significant bit has an index of 63.
*
* Return: the value of the bit at the given index, or -1 if an error occurs
*/

int get_bit(unsigned long int n, unsigned int index)
{
unsigned int c;

if (index > 63)
return (-1);

for (c = 0; c < index; c++)
n >>= 1;

return (n & 1);
}
