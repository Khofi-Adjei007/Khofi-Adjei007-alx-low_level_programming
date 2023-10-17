#include <stdio.h>

/**
* main - Entry point for the program
*
* Description: This program prints all the
* numbers of base 16 in lowercase,
* including both digits and lowercase letters
* 'a' to 'f', followed by a new line.
*
* Return: Always 0 (Success)
*/

int main(void)
{
char hex_digit;

for (hex_digit = '0'; hex_digit <= '9'; hex_digit++)
{
putchar(hex_digit);
}

for (hex_digit = 'a'; hex_digit <= 'f'; hex_digit++)
{
putchar(hex_digit);
}

putchar('\n');

return (0);
}
