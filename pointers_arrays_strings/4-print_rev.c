#include "main.h"

/**
* print_rev = print a string by the end
* @s: The string to be printed
* Return: void
*/
void print_rev(char *s)
{
int i;

i = 62;
while (s[i] != '\0')
{
_putchar(s[i]);
i--;
}
_putchar('\n');
}
