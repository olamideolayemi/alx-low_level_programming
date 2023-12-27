#include "hash_tables.h"

/**
 * hash_table_get - the function retrives a value associated with a key
 * @ht: the hash table
 * @key: they key to look for
 *
 * Return: Returns the value associated with the element,
 * NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *temp;
	unsigned long int i;

	if (key == NULL || ht == NULL)
		return (NULL);

	i = key_index((unsigned const char*) key, ht->size);
	temp = ht->array[i];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
