#include <stdio.h>

/**
* main - Entry point for the program
*
* Description: This program prints all
* single-digit numbers in base 10 (0 to 9)
* followed by a new line.
*
* Return: Always 0 (Success)
*/

int main(void)
{
int digit = 0;

while (digit <= 9)
{
putchar(digit + '0');
/* Convert the integer to its ASCII character representation */
digit++;
}

putchar('\n');

return (0);
}
