#include "operations.h"

/**
 * add - adds two integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtracts two integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiplies two integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - divides two integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int div(int a, int b)
{
	return (a / b);
}

/**
 * mod - Modulo of two integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int mmod(int a, int b)
{
	if (b != 0)
		return (a % b);
	fprintf(stderr, "%d %% %d: Modulo by zero\n", a, b);
	return (0);
}
