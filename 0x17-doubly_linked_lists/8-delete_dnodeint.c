#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
* delete_dnodeint_at_index - Deletes the node
* at a given index of a dlistint_t linked list.
* @head: Double pointer to the head of the list.
* @index: Index of the node
* that should be deleted. Index starts at 0.
* Return: 1 if it succeeded, -1 if it failed.
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current, *temp;
unsigned int count = 0;

if (head == NULL || *head == NULL)
return (-1);  /* Empty list */

current = *head;

if (index == 0)
{
*head = current->next;
if (current->next != NULL)
current->next->prev = NULL;
free(current);
return (1);
}

while (current != NULL && count < index)
{
current = current->next;
count++;
}

if (current == NULL)
return (-1);  /* Index out of range */

temp = current->prev;
temp->next = current->next;

if (current->next != NULL)
current->next->prev = temp;

free(current);
return (1);
}
