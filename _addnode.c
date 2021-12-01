#include "main.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 *
 * @head: pointer list_t head
 * @str: string to node
 *
 * Return: 0;
 */

path_t *add_node_end(path_t **head, const char *str)
{
	path_t *node, *tmp;

	if (!head)
		return (NULL);

	if (!str)
		str = NULL;

	node = malloc(sizeof(path_t));
	if (!node)
	{
		free(node);
		return (NULL);
	}

	node->path = strdup(str);
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (0);
	}

	tmp = *head;

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = node;

	return (node);
}
