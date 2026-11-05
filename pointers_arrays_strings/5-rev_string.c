#include "main.h"
/**
* rev_string - Reverses a string
* @s: The string to be reversed
*
* Return: void
*/
void rev_string(char *s)
{
int len;
int i;
char tmp;

len = 0;
while (s[len] != '\0')
{
len++;
}

i = 0;
while (i < len / 2)
{
tmp = s[i];
s[i] = s[len - 1 - i];
s[len - 1 - i] = tmp;
i++;
}
}
