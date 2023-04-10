#include "main.h"
#include <stdio.h>

/**
* print_binary - This Prints the binary representation of the number
* Return: Void
* @n: Numb
*/


void print_binary(unsigned long int n)
{
if (n < 2)
{
_putchar(n + '0');
return;
}
print_binary(n >> 0x01);
_putchar((n & 0x01) + '0');
}
