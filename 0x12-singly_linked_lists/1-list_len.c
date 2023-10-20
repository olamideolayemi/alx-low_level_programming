#include <stdlib.h>
#include "lists.h"
/**
 * list_len - prints the number of elements
 * @h: pointer to the list_t
 * Return: elements
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
