#include <stdio.h>

/**
* main - Entry point for the program
*
* Description: This program prints all
* single-digit numbers in base 10 (0 to 9)
* on the same line, followed by a new line
* to separate the output.
*
* Return: Always 0 (Success)
*/

int main(void)
{
int i;

for (i = 0; i <= 9; i++)
{
printf("%d", i);
}

printf("\n");

return (0);
}
