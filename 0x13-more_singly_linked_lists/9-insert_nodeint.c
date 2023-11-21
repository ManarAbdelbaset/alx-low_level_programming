#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head of the list
 * @idx: index of the list where the new node should be added
 * @n: value to be stored in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 * if it is not possible to add the new node at index idx,
 * do not add the new node and return NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current, *prev;
	unsigned int current_index = 0;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	current = *head;
	prev = NULL;

	while (current != NULL && current_index < idx)
	{
		prev = current;
		current = current->next;
		current_index++;
	}

	if (current == NULL && current_index > idx)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current;
	prev->next = new_node;

	return (new_node);
}
