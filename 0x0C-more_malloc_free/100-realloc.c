#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the memory block to be reallocated.
 * @old_size: Size of the allocated space for ptr, in bytes.
 * @new_size: New size of the memory block, in bytes.
 *
 * Return: Pointer to the reallocated memory block.
 *         NULL if new_size is zero and ptr is not NULL, or if malloc fails.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr;
	unsigned int i, size;

	/* If new_size is zero, free ptr and return NULL */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* If ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	/* Allocate memory for the new size */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Get the minimum size between old_size and new_size */
	size = (old_size < new_size) ? old_size : new_size;

	/* Copy the contents from old_ptr to new_ptr */
	old_ptr = ptr;
	for (i = 0; i < size; i++)
		new_ptr[i] = old_ptr[i];

	/* Free the old memory block */
	free(ptr);

	return (new_ptr);
}
