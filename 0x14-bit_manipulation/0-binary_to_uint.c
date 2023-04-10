#include <stdio.h>
#include "main.h"


unsigned int binary_to_uint(const char *b)

{
unsigned int dec, size, i, exp;
if (!b)
return (0);
size = _strlen(b);
i = 0;
dec = 0;
exp = size - 1;

while (b[i])
{
if (b[i] == '1')
dec += power(2, exp);
else if (b[i] != '0')
return (0);
exp--;
i++;
}
return (dec);
}

/**
* _strlen - lenght of a string.
* @s: This is a pointer to a character
* Return: The Acquired Lenght.
*/

unsigned int _strlen(const char *s)
{
unsigned int i = 0;

while (*(s + i) != '\0')
{
i++;
}
return (i);
}
