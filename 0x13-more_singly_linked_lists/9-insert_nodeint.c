#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: data of the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current = *head;
	unsigned int i;

	if (idx == 0)
		return (add_nodeint(head, n));

	for (i = 0; current && i < idx - 1; i++)
		current = current->next;

	if (!current)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
