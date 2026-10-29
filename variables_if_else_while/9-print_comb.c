#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * main - number name*
 * for loop to add comas between each character except 0 and 9
 * Return: Always 0 (Success)
 */
int main(void) /* main = Entry point*/
{
int n;

for (n = 0; n <= 9; n++)
{
putchar(n + '0');
if (n != 9)
{putchar(',');
putchar(' '); }
}
putchar('\n');
return (0);
}
