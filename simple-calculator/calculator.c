#include <stdio.h>
/**
* main - Entry point for simple calculator program
*
* Return: Always 0 (Success)
*/
int main(void)
{
int choice;

printf("Simple Calculator\n");
printf("1) Add\n");
printf("2) Subtract\n");
printf("3) Multiply\n");
printf("4) Divide\n");
printf("0) Quit\n");

scanf("%d", &choice);
if (choice == 0)
printf("Bye!\n");
if (choice > 4)
printf("Invalid choice\n");

return (0);
}
