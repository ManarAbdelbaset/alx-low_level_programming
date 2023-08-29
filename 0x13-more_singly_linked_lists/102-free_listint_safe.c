#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list,
 *                     even if it has a loop
 * @h: double pointer to the head of the list
 *
 * Return: the number of nodes in the list that were freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *next = NULL;
	size_t count = 0, i, j;

	while (current)
	{
		count++;
		if (current->next >= current)
		{
			free(current);
			*h = NULL;
			break;
		}
		next = current->next;
		current->next = NULL;
		free(current);
		current = next;
		*h = NULL;
	}

	return (count);
}
