#include "main.h"
#include <stdlib.h>
/**
 * _strdup - Duplique une chaîne de caractères dans le Heap.
 * @str: La chaîne source à dupliquer.
 *
 * Return: Pointeur vers la nouvelle chaîne, ou NULL en cas d'échec.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len = 0;
	unsigned int i;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
