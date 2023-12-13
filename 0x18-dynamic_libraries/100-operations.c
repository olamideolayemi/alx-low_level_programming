#include "operations.h"

/**
 * add - adds integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtract integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiply integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - divides integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int div(int a, int b)
{
	return (a / b);
}

/**
 * mod - module of integers
 * @a: input int
 * @b: input int
 * Return: Result of the operation
 */
int mod(int a, int b)
{
	if (b != 0)
		return (a % b);
	fprintf(stderr, "%d %% %d: Modulo by zero\n", a, b);
	return (0);
}
