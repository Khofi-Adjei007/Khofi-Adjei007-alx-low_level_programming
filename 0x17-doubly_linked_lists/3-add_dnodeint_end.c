#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new_node = malloc(sizeof(dlistint_t));
/* Create a new node */
if (new_node == NULL)
{
return (NULL);
/* Failed to allocate memory for the new node */
}

new_node->n = n;
/* Set the data of the new node */
new_node->next = NULL;
/* The new node will be the last node, so its next pointer is set to NULL */

if (*head == NULL)
{
*head = new_node;
/* If the list is empty, the new node becomes the head */
}
else
{
dlistint_t *current = *head;
while (current->next != NULL)
{
current = current->next;
/* Traverse the list to find the last node */
}
current->next = new_node;
/* Set the next pointer of the last node to the new node */
new_node->prev = current;
/* Set the previous pointer of the new node to the last node */
}

return (new_node);
/* Return the address of the new element */
}
