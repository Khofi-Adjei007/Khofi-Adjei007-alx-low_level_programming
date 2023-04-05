#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
 * listint_len - function having one argument
 * @h: pointer to a linked list
 * Description: line 13 returns number of elements
 * Return: numberof elements
 */


size_t listint_len(const listint_t *h)
{
unsigned int count = 0;
while (h != NULL)
{
h = h->next;
count++;
}
return (count);

}
