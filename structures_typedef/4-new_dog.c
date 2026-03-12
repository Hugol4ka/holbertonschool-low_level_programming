#include"dog.h"
#include<stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (Success), NULL otherwise
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int name_len = 0;
	int owner_len = 0;
	int i;

	if (name == NULL || owner == NULL)
	return (NULL);
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
	{
		return (NULL);
	}

	while (name[name_len])
	name_len++;
	new_dog->name = malloc(sizeof(char) * (name_len + 1));
		if (new_dog->name == NULL)
		{
			free(new_dog);
			return (NULL);
		}
	for (i = 0; i <= name_len; i++)
	new_dog->name[i] = name[i];

	while (owner[owner_len])
	owner_len++;
	new_dog->owner = malloc(sizeof(char) * (owner_len + 1));
		if (new_dog->owner == NULL)
		{
			free(new_dog->name);
			free(new_dog);
			return (NULL);
		}
	for (i = 0; i <= owner_len; i++)
	new_dog->owner[i] = owner[i];

	new_dog->age = age;
	return (new_dog);
}
