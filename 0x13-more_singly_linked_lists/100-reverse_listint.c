#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: double pointer to the head of the list
 *
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current)
	{
		next = current->next; /* Store next node */
		current->next = prev; /* Reverse current node's pointer */
		prev = current; /* Move pointers one position ahead */
		current = next;
	}
	*head = prev; /* Update head of the list */

	return (*head);
}
