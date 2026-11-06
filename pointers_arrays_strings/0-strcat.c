#include "main.h"

/**
 * _strcat - concatène deux chaînes de caractères
 * @dest: chaîne de destination
 * @src: chaîne source
 * Return: pointeur vers la chaîne résultante dest
 */
char *_strcat(char *dest, char *src)
{
int i, j;
for (i = 0; dest[i] != '\0'; i++)
;
for (j = 0; src[j] != '\0'; j++)
{
dest[i + j] = src[j];
}

dest[i + j] = '\0';

return (dest);
}
