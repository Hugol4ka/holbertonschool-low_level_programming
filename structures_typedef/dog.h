#ifndef DOG_H
#define DOG_H

/**
 * struct dog - stores information about a dog
 * @name: pointer to the dog's name
 * @age: pointer to the dog's age
 * @owner: pointer to the dog's owner's name
 */

struct dog
{
char *name;
float age;
char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
