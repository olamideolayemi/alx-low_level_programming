#include "hash_tables.h"

/**
 * hash_table_create - The function creates hash tables
 * @size: is the size of array
 *
 * Return: Returns a pointer to the newly created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned int i  0;
	hash_table_t *table;
	hash_node_t **item_array;

	if (size == 0)
		return (NULL);

	table = malloc(sizeof(hash_table_t));

	if (table == NULL)
		return (NULL);

	item_array = malloc(sizeof(*item_array) * size);

	if (item_array == NULL)
	{
		free(table);
		return (NULL);
	}
	while (i < size)
	{
		item_arrau[i] = NULL;
		i++;
	}
	table->size = size;
	table->array = item_array;

	return (table);
}
