#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees a dog and its attributes
 * @d: Pointer to the dog struct
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
