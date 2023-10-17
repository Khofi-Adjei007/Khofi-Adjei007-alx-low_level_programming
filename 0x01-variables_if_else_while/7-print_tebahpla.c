#include <stdio.h>

/**
* main - Entry point for the program
*
* Description: This program prints the
* lowercase alphabet in reverse order,
* followed by a new line.
*
* Return: Always 0 (Success)
*/

int main(void)
{
char letter = 'z';

while (letter >= 'a')
{
putchar(letter);
letter--;
}

putchar('\n');

return (0);
}
