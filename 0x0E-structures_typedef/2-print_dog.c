#include <stdio.h>
#include "dog.h"

/**
 *print_dog - prints the values of a struct dog.
 *@d: pointer to the struct dog.
*/

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %f\n", d->age);
		printf("owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}
