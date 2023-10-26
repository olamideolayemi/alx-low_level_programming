#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get
 * from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int num;
	unsigned long int dig = n ^ m;

	for (i = 48; i >= 0; i--)
	{
		num = dig >> i;
		if (num & 1)
			count++;
	}
	return (count);
}
