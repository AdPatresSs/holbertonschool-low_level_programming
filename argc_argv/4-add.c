#include <stdio.h>
#include <stdlib.h>

/**
 * main - add two numbers passed to the programm
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 if fewer or more than two arguments are passed
 */
int main(int argc, char *argv[])
{
	int num1, num2, sum;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	sum = num1 + num2;

	printf("%d\n", sum);
	return (0);
}
