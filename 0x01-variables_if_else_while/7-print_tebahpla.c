#include <stdio.h>

/**
 * main - the main entry function
 *
 * Return: return 0 (success)
 */

int main(void)
{
	char i;

	for (i = 'z' ; i >= 'a' ; i--)
		putchar(i);
	putchar('\n');
	return (0);
}
