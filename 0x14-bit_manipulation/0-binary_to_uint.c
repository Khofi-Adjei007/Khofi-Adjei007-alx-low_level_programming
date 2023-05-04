#include <stdio.h>
#include "main.h"

int _pow_recursion(int x, int y);

/**
* binary_to_uint - function with one argument
* @b: pointer to character
* Description: converts a binary number to an unsigned int
* Return: converted number or 0 if NULL or non-binary input
*/

unsigned int binary_to_uint(const char *b)
{
unsigned int value = 0;
unsigned int power = 0;
int count = 0;

if (!b)
return (0);

/* Get length of string */
while (b[count] != '\0')
{
if (b[count] != '0' && b[count] != '1')
return (0); /* if input is not binary, return 0 */
count++;
}
count -= 1;
while (count >= 0)
{
if (b[count] == '1')
value += _pow_recursion(2, power); /* compute power of 2 to get value */
power++;
count--;
}
return (value);
}

/**
* _pow_recursion - two function argument
* @x: base integer
* @y: exponent integer
* Description: returns the value of x raised to power of y
* Return: value of x raised to the power of y, or -1 if y is negative
*/

int _pow_recursion(int x, int y)
{
if (y == 0)
return (1); /* Base case */
else if (y < 0)
return (-1); /* Exponent must be non-negative */
else
return (x * _pow_recursion(x, y - 1));
/* Recursive call to compute power of x */
}
