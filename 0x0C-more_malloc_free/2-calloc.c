#include <stdlib.h>

/**
  * _calloc - Calloc function.
  * @nmemb: Number of arguments.
  * @size: Size of the argument.
  *
  * Return: Pointer.
  */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *tmp;
	unsigned int i, var = nmemb * size;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	tmp = malloc(nmemb * size);

	if (tmp == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < var; i++)
	{
		tmp[i] = 0;
	}

	return (tmp);
}
