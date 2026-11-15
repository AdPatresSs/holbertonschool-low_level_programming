#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Libère la mémoire allouée pour une structure struct dog
 * @d: Pointeur vers la structure dog_t à libérer
 *
 * Return: Rien (void)
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
