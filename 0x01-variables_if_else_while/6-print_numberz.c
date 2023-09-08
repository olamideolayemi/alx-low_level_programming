#include <stdio.h>

/**
 * main - the main entry function
 *
 * Return: return 0 (success)
 */

int main(void)
{
	int i;

	for (i = 0 ; i < 10 ; i++)
		putchar(i + '0');
	putchar('\n');
	return (0);
}
