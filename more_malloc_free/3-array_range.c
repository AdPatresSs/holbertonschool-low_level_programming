#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the minimum value (included)
 * @max: the maximum value (included)
 *
 * Return: pointer to the newly created array, or NULL if fails
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	if (min > max)
		return (NULL);

	/* +1 car on inclut à la fois min et max (ex: 0 à 10 = 11 éléments) */
	size = max - min + 1;

	/* On alloue la mémoire pour des entiers (sizeof(int)), pas des chars */
	arr = malloc(sizeof(int) * size);

	if (arr == NULL)
		return (NULL);

	/* Remplissage du tableau de façon contiguë */
	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}
