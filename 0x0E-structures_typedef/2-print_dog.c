#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the values of a struct dog.
 * @d: Pointer to the struct dog.
*/

void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	if (d->name == NULL)
		d->name == "NULL";
	if (d->owner == NULL)
		d->owner == "NULL";
	printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
}
