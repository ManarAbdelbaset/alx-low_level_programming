#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head
 * pointer to NULL
 * @head: double pointer to the head of the list
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
