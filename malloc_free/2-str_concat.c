#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated space
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the newly allocated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int size, len1, len2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	len2 = 0;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	size = len1 + len2 + 1;

	concat = malloc(sizeof(char) * size);
	if (concat == NULL)
		return (NULL);

	i = 0;
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}
