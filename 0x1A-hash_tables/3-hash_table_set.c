#include "hash_tables.h"

/**
 * create_item - a fucntion that creates items for the hashtable array
 * @key: key for the hashtable
 * @value: the equivalent value for the key
 * Return: The node or the item created
 */

hash_node_t *create_item(const char *key, const char *value)
{
	hash_node_t *item;

	item = malloc(sizeof(hash_node_t));

	if (item == NULL)
		return (NULL);
	if (strlen(key) == 0 || value == NULL || key == NULL)
		return (NULL);

	item->key = malloc(sizeof(char) * (strlen(key) + 1));
	if (item->key == NULL)
	{
		free(item);
		return (NULL);
	}

	item->value = malloc(sizeof(char) * (strlen(value) + 1));
	if (item->value == NULL)
	{
		free(item->key);
		free(item);
		return (NULL);
	}
	strcpy(item->key, key);
	strcpy(item->value, value);
	item->next = NULL;

	return (item);
}

/**
 * hash_table_set - a function that adds an element to the hash table.
 * @ht: is the hash table you want to add or update the key/value to
 * @key: is the key. key can not be an empty string
 * @value: is the value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *item, *temp;
	char *new_value;
	unsigned long int i;

	if (ht == NULL || ht->array == NULL)
		return (0);
	item = create_item(key, value);
	if (item == NULL)
		return (0);

	i = key_index((const unsigned char *) key, ht->size);
	temp = ht->array[i];
	if (temp == NULL)
	{
		if (i >= ht->size)
		{
			free(item);
			return (0);
		}
		ht->array[i] = item;
		return (1);
	}
	else
	{
		while (temp != NULL)
		{
			if (strcmp(temp->key, key) == 0)
			{
				new_value = strdup(value);
				free(ht->array[i]->value);
				ht->array[i]->value = new_value;
				return (1);
			}
			temp = temp->next;
		}
		item->next = ht->array[i];
		ht->array[i] = item;
		return (1);
	}
}
