#include <stddef.h>  /* For size_t */
#include "lists.h"

size_t dlistint_len(const dlistint_t *h)
{
const dlistint_t *current = h;
/* Create a pointer to iterate through the list */
size_t count = 0;
/* Variable to keep track of the number of elements */

while (current != NULL)
{
count++;
/* Increment the count of elements */
current = current->next;
/* Move to the next node */
}

return (count);
}
