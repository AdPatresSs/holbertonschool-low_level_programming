#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * _str_len - computes the length of a string
 * @str: non-NULL string
 *
 * Return: length as unsigned int
 */
static unsigned int _str_len(const char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to be duplicated and stored in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *last;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	if (str != NULL)
	{
		new->str = strdup(str);
		if (new->str == NULL)
		{
			free(new);
			return (NULL);
		}
		new->len = _str_len(str);
	}
	else
	{
		new->str = NULL;
		new->len = 0;
	}
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}

	return (new);
}
