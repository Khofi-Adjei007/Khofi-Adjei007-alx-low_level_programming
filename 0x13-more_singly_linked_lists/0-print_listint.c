#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* Only print listint
* Description: print all the nodes
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
