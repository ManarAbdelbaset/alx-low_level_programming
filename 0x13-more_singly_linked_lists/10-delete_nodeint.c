#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a linked list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head, *tmp;
	unsigned int i;

	if (!*head)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	for (i = 0; i < index - 1; i++)
	{
		if (!current->next)
			return (-1);
		current = current->next;
	}

	tmp = current->next;
	current->next = tmp->next;
	free(tmp);

	return (1);
}
