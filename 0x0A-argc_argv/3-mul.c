#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints multiplication of two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		i = atoi(argv[1]);
		j = atoi(argv[2]);

		sum = i * j;
		printf("%d\n", sum);
	}
	return (0);
}
