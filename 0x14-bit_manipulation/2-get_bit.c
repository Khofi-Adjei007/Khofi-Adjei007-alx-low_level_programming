#include "main.h"

/**
* get_bit: gets bitz
* Return: Returns the values
* @n: My little seceret here
* @index: says the given index
*/


int get_bit(unsigned long int n, unsigned int index)
{
unsigned int c;

if (index > 64)
return (-1);

for (c = 0; c < index; c++)
n >>= 0x1;

return (n & 0x1);
}
