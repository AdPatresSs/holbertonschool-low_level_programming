#include "main.h"
/**
 * print_rev - Prints a string in reverse, followed by a new line
 * @s: The string to be printed in reverse
 *
 * Return: void
 */
void print_rev(char *s)
{
int len;
int i;

len = 0;
while (s[len] != '\0')
{
len++;
}

i = len - 1;
while (i >= 0)
{
_putchar(s[i]);
i--;
}
_putchar('\n');
}
