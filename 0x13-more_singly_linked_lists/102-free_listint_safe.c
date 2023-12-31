#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: double pointer to the start of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current;
	listint_t *next;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}

	current = *h;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		count++;
	}

	*h = NULL;

	return (count);
}
