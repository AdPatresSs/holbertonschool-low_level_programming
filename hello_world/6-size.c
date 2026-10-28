#include <stdio.h>
/**
 * main - Entry point
 * main - Prints the size of various types on the computer
 * Return: Always 0 (Success)
 */
int main(void)
{
printf("Sizeofachar:%lubytes\n", sizeof(char));
printf("Sizeofanint:%lubytes\n", sizeof(int));
printf("Sizeofalongint:%lubytes\n", sizeof(long int));
printf("Sizeofalonglongint:%lubytes\n", sizeof(long long int));
printf("Sizeofafloat:%lubytes\n", sizeof(float));
return (0);
}
