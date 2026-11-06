#include "main.h"
#define NULL ((void *)0)
/**
* _strchr - localise un caractère dans une chaîne
* @s: pointeur vers la chaîne de caractères
* @c: caractère à rechercher
* Return: un pointeur vers la première occurrence de c, ou NULL si non trouvé
*/
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}
if (*s == c)
{
return (s);
}
return (NULL);
}
