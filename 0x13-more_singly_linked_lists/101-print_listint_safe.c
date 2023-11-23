#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	if (head == NULL)
	{
		printf("-> %p\n", (void *)head);
		return (0);
	}

	printf("[%p] %d\n", (void *)head, head->n);
	count++;

	while (head->next != NULL)
	{
		head = head->next;
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
	}

	printf("-> %p\n", (void *)head->next);

	return (count);
}
