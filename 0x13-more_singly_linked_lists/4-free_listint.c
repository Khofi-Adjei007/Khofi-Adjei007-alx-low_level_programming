#include <stdlib.h>
#include "lists.h"

/**
* free_listint - gives a free space in a list
* @head: head of node
* Return: void
*/

void free_listint(listint_t *head)
{
while (head)
{
listint_t *tmp = head;
head = head->next;
free(tmp);
}

}
