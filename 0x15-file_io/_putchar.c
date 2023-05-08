#include <unistd.h>

/**
 * _putchar - This writes C as a character to stdout
 * @c: This is the haracter to print
 * Return: When success print 1.
 * When error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
