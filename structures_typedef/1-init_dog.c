#include"dog.h"
#include<stdlib.h>

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to the struct dog to initialize
 * @name: string representing the dog's name
 * @age: float representing the dog's age
 * @owner: string representing the dog's owner
 *
 * Return: nothing
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
	return;
	}
	d->name = name;
	d->age = age;
	d->owner = owner;
}
