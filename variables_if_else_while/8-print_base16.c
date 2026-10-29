#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 * main - putchar number
 * main - putchar letter
 * Return: Always 0 (Success)
 */
int main(void)
{
char number;
char letter;

for (number = '0'; number <= '9'; number++)
putchar(number);
for (letter = 'a'; letter <= 'f'; letter++)
putchar(letter);
putchar('\n');
return (0);
}
