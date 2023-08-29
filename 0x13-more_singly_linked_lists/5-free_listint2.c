#include "lists.h"

/**
 * free_listint2 - free a listint_t list and sets the head to NULL
 * @head: pointer to pointer to head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head)
		return;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}