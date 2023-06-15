#include <stdio.h>
#include "lists.h"

size_t print_dlistint(const dlistint_t *h)
{
const dlistint_t *current = h;
/* Create a pointer to iterate through the list */
size_t count = 0;
/* Variable to keep track of the number of nodes */

while (current != NULL)
{
printf("%d\n", current->n);
/* Print the data of the current node */
count++;
/* Increment the count of nodes */
current = current->next;
/* Move to the next node */
}

return (count);
}
