#include "main.h"
/**
 * llpath - locates path on enviroment
 *
 * @env: enviroment.
 * @path: string to match.
 *
 * Return: a pointer to head of linked list or null on error
 */
path_t *llpath(char **env, char *path)
{
	int i, j, h, count, n_len;
	char *ret = NULL, *buffer;
	path_t *head = NULL;

	i = j = h = 0;
	count = n_len = 0;

	while (path[n_len] != '\0')
		n_len++;

	for (h = 0; env[h]; h++)
	{
		for (i = 0; env[h][i] != '\0'; i++)
		{
			count = 0;
			if (env[h][0] == path[0])
			{
				for (j = 0; path[j] != '\0'; j++)
				{
					if (env[h][j] == path[j])
					{
						count++;
					}
				}
				if (count == n_len)
				{
					ret = &env[h][i];
					break;
				}
				else
					ret = "PATH=";
			}
		}
	}

	buffer = _strdup(ret); /*copy string from enviroment*/
	head = token_path(buffer);
	free(buffer);
	return (head);
}

/**
 * token_path - tokenizer path and create linked list
 *
 * @path: string path
 *
 * Return: pointer to head
 */
path_t *token_path(char *path)
{
	path_t *head = NULL;
	char *pathcp[1024], *token;
	const char *del = ":";
	int i;

	i = 0;
	token = strtok(path, "PATH=");
	while (token)
	{
		pathcp[i] = token;
		token = strtok(NULL, "=");
		i++;
	}
	pathcp[i] = NULL;
	i = 0;
	token = strtok(*pathcp, del);
	while (token)
	{
		add_node_end(&head, token); /*for each token create a new nodo*/
		token = strtok(NULL, del);
		i++;
	}

	return (head);
}
