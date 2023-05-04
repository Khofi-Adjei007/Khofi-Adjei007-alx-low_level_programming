#include <stdio.h>
#include "main.h"

/**
* main - entry point for program
*
* This program demonstrates the functionality of the `set_bit` function.
* It sets a bit at a given index in an unsigned long int variable and
* prints the updated value of the variable.
*
* Return: Always 0 indicating successful execution of the program.
*/

int main(void)
{
unsigned long int n;

/* Initialize variable n to 1024 and set bit at index 5 */
n = 1024;
set_bit(&n, 5);
printf("%lu\n", n);

/* Initialize variable n to 0 and set bit at index 10 */
n = 0;
set_bit(&n, 10);
printf("%lu\n", n);

/* Initialize variable n to 98 and set bit at index 0 */
n = 98;
set_bit(&n, 0);
printf("%lu\n", n);

return (0);
}
