#include <stdio.h>

/**
* main - Entry point for the program
*
* Description: This program prints all possible
* combinations of single-digit numbers,
* separated by ", " and in ascending order.
*
* Return: Always 0 (Success)
*/

int main(void)
{
int num;

for (num = 0; num <= 9; num++)
{
putchar(num + '0');

/* Convert the integer to its ASCII character representation */
if (num < 9)
{
putchar(','); /* Print the comma */
putchar(' '); /* Print the space */
}
}

putchar('\n'); /* Print a new line */

return (0);
}
