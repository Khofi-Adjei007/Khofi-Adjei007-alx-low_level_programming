#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
* free_listint2 - frees a list
* @head: head node
* Return: void
*/


void free_listint2(listint_t **head)
{
if (!head || !*head)
return;
while (*head)
{
listint_t *tmp = *head;
*head = (*head)->next;
free(tmp);
}
*head = 0;
}
