#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the start of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	slow = head;
	fast = head;

	while (slow && fast && fast->next)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;

		if (slow == fast && count > 1)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			break;
		}

		slow = slow->next;
		fast = fast->next->next;
	}

	if (!slow || !fast)
		return (count);

	return (count);
}
