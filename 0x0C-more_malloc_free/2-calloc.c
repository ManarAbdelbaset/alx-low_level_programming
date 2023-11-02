#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array using malloc.
 * @nmemb: Number of elements in the array.
 * @size: Size of each element.
 *
 * Return: Pointer to the allocated memory.
 *         NULL if nmemb or size is 0, or if malloc fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size;

	/* Check if nmemb or size is 0 */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Calculate the total size to allocate */
	total_size = nmemb * size;

	/* Allocate memory using malloc */
	ptr = malloc(total_size);

	if (ptr == NULL)
		return (NULL);

	/* Set the allocated memory to zero */
	char *char_ptr = ptr;
	unsigned int i;

	for (i = 0; i < total_size; i++)
		char_ptr[i] = 0;

	return (ptr);
}
