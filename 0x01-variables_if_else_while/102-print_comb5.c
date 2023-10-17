#include <stdio.h>

/**
* main - Entry point for the program
*
* Description: This program prints all possible
* combinations of two two-digit numbers,
* separated by a space and a comma, in ascending order.
*
* Return: Always 0 (Success)
*/

int main(void)
{
int num1;
int num2;

for (num1 = 0; num1 <= 99; num1++)
{
for (num2 = num1 + 1; num2 <= 99; num2++)
{
putchar((num1 / 10) + '0');  /* Tens digit of num1 */
putchar((num1 % 10) + '0');  /* Ones digit of num1 */
putchar(' ');                /* Space separator */
putchar((num2 / 10) + '0');  /* Tens digit of num2 */
putchar((num2 % 10) + '0');  /* Ones digit of num2 */

if (num1 != 98 || num2 != 99)
{
putchar(',');  /* Comma separator */
putchar(' ');  /* Space separator */
}
}
}

putchar('\n');  /* Print a new line */

return (0);
}
