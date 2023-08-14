#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - function
 * @str: the string
 * Return: length
*/


int _strlen(const char *str)
{
	int length = 0;

	while (*str++)
		length++;
	return (length);
}

/**
 * _strcopy - function
 * @src: string to copy from
 *@dest: destination
 *Return: dest
*/

char *_strcopy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - function
 *
 *@name: dog's name
 *@age: dog's age
 *@owner: dog's owner
 *Return: struct
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;


	if (!name || age < 0 || !owner)
		return (NULL);

	dog = (dog_t *) malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if ((*dog).name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->name = name;
	dog->age = age;
	dog->owner = owner;

	return (dog);
}
