#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 * main - putchar number
 * Return: Always 0 (Success)
 */
int main(void)
{
char number;

for (number = '1'; number <= '9'; number++)
putchar(number);
putchar('\n');
return (0);
}
