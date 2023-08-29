#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list,
 *                      even if it has a loop
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;
	size_t count = 0, i, j;

	if (!head)
		exit(98);

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
		{
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			for (i = 0; i < count; i++)
			{
				if (head == hare)
				{
					printf("-> [%p] %d\n", (void *)hare, hare->n);
					return (count);
				}
				head = head->next;
				hare = hare->next;
			}
			count++;
			exit(0);
		}
		count++;
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}

	if (tortoise && (!hare || !hare->next))
	{
		count++;
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	return (count);
}
