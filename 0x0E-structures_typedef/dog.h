#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog struct
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 *
 * Description: just a lone dog struct in a big kitty world
*/

/**
 * dog_t - Typedef for struct dog
*/

struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
*dog_t - Typedef for struct dog
*/

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
void free_dog(dog_t *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif
