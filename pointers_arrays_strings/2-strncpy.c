#include "main.h"
/**
* _strncpy - copie une chaîne de caractères jusqu'à n octets
* @dest: tampon de destination
* @src: chaîne source à copier
* @n: nombre maximum d'octets à copier
* Return: pointeur vers la chaîne de destination dest
*/
char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}
for ( ; i < n; i++)
{
dest[i] = '\0';
}
return (dest);
}
