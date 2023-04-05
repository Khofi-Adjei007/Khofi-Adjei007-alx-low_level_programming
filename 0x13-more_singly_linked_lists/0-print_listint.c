#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/*
* print_listint - prints list
* Return: size_t
*
* Description: print all the nodes
* And Return: Number of  nodes
*/

size_t print_listint(const listint_t *h)

{
int count = 0;
while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
count++;
}


return (count);
}
