#include <stdlib.h>
#include "lists.h"

/**
* free_dlistint - Frees a dlistint_t list.
* @head: Pointer to the head of the list.
*/
void free_dlistint(dlistint_t *head)
{
dlistint_t *current;

while (head != NULL)
{
current = head;  /* Store the current node */
head = head->next;  /* Move to the next node */
free(current);  /* Free the memory of the current node */
}
}
