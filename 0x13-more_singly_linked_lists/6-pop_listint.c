#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to pointer to head of the list
 *
 * Return: data (n) of the head node deleted, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!head || !*head)
		return (0);
	temp = *head;
	*head = (*head)->next;
	n = temp->n;
	free(temp);
	return (n);
}
