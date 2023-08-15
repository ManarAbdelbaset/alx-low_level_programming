#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: A pointer to the new dog, or NULL if the function fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int name_length, owner_length;

	/* Calculate the lengths of the name and owner strings */
	name_length = strlen(name);
	owner_length = strlen(owner);

	/* Allocate memory for the new dog */
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	/* Allocate memory for the name and owner strings */
	new_dog->name = malloc((name_length + 1) * sizeof(char));
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	new_dog->owner = malloc((owner_length + 1) * sizeof(char));
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	/* Copy the name and owner strings to the new dog */
	strcpy(new_dog->name, name);
	strcpy(new_dog->owner, owner);

	/* Set the age of the new dog */
	new_dog->age = age;

	return (new_dog);
}
