#include "main.h"
/**
* _memset - remplit les n premiers octets de la zone mémoire
* pointée par s avec l'octet b
* @s: pointeur vers la zone mémoire à remplir
* @b: l'octet constant avec lequel remplir la mémoire
* @n: nombre d'octets à modifier
* Return: un pointeur vers la zone mémoire s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}
