#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - Create an arrary from min to max numbers.
 * @min: Minimum number.
 * @max: Maximum number.
 *
 * Return: The array.
 */
int *array_range(int min, int max)
{
	int *tmp;
	int size = (max - min) + 1, i;

	if (min > max)
	{
		return (NULL);
	}

	tmp = malloc(sizeof(int) * ((max - min) + 1));

	if (tmp == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		tmp[i] =  min;
		min++;
	}

	return (tmp);
}
