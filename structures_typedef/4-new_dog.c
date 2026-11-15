#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - Calcule la longueur d'une chaîne de caractères
 * @s: La chaîne à analyser
 * Return: La longueur de la chaîne
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _strcpy - Copie une chaîne de caractères vers une autre
 * @dest: Le buffer de destination
 * @src: La chaîne source
 * Return: Pointeur vers la destination
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - Crée une nouvelle structure dog_t
 * @name: Nom du chien
 * @age: Âge du chien
 * @owner: Propriétaire du chien
 *
 * Return: Pointeur vers le nouveau dog_t, ou NULL en cas d'échec
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int name_len, owner_len;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	name_len = _strlen(name);
	d->name = malloc(sizeof(char) * (name_len + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	owner_len = _strlen(owner);
	d->owner = malloc(sizeof(char) * (owner_len + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	d->age = age;
	_strcpy(d->owner, owner);

	return (d);
}
