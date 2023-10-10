#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * init_dog - initializes a varible of type struct dog
 * @d: dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 * Return: 0
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
