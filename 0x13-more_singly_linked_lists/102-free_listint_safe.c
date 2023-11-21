#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: double pointer to the start of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *prev = NULL;
	size_t count = 0;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}

	slow = *h;
	fast = *h;

	while (slow && fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
		count++;

		if (slow == fast) // Loop detected
		{
			slow = *h;
			while (slow != fast)
			{
				prev = slow;
				slow = slow->next;
				fast = fast->next;
				free(prev);
			}
            // Free the nodes in the loop
	do
	{
		prev = slow;
		slow = slow->next;
		free(prev);
	}
	while (slow != fast);
	*h = NULL; // Set the head to NULL
	return (count);
		}
		free(prev);
	}

	*h = NULL; // Set the head to NULL
	return (count);
}
