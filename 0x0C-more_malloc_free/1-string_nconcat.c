#include <stdio.h>
#include <stdlib.h>

/**
  * _strlen - Find the lenght of a string.
  * @s: String.
  * Return: The lenght, integer.
  */
int _strlen(char *s)
{
	int count = 0, i = 0;

	while (s[i])
	{
		count++;
		i++;
	}

	return (count);
}

/**
  * string_nconcat - Concat one string and n bytes of the second string.
  * @s1: String.
  * @s2: String.
  * @n: Number of bytes.
  * Return: Strings concated.
  */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *tmp;
	unsigned int i, j;
	unsigned int count1, count2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	count1 = _strlen(s1);
	count2 = _strlen(s2);

	if (n >= count2)
	{
		n = count2;
	}
	tmp = malloc((sizeof(char) * count1) + (sizeof(char) * n) + 1);
	if (tmp != NULL)
	{
		for (i = 0; i < count1; i++)
		{
			tmp[i] = s1[i];
		}
		for (j = 0; j < n; j++)
		{
			tmp[i] = s2[j];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	else
	{
		return (NULL);
	}
}
