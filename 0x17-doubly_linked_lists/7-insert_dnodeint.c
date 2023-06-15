#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
* insert_dnodeint_at_index - Inserts a new node
* at a given position in a dlistint_t linked list.
* @h: Double pointer to the head of the list.
* @idx: Index of the list where the new node
* should be added. Index starts at 0.
* @n: Data for the new node.
* Return: Address of the new node, or NULL if it failed.
*/


dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *current;
unsigned int count = 0;

if (h == NULL)
return (NULL);

if (idx == 0)
return (add_dnodeint(h, n));
/* Utilize the add_dnodeint function to add at the beginning */

current = *h;
while (current != NULL && count < idx - 1)
{
current = current->next;
count++;
}

if (current == NULL || current->next == NULL)
return (NULL);

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = current->next;
new_node->prev = current;
current->next->prev = new_node;
current->next = new_node;

return (new_node);
}
