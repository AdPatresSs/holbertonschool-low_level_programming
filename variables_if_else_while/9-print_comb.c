#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * main - number name*
 * for loop to add comas between each character except 0 and 9
 * result Always 0 (success)
 */
int main(void) /* main = Entry point*/
{
int n;

for (n = 0; n <= 9; n++)
{
if (n >= 1)
if (n <= 9)
putchar(',');
putchar(' ');
putchar(n + '0');
}
putchar('$\n');
return (0);
}
