#include "main.h"
path_t *token_path(char *path);
/**
 * _getpath - locates path on enviroment.
 *
 * @env: enviroment.
 * @path: string to match.
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the character is not found.
 */
path_t *_getpath(char **env, char *path)
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
			if (env[h][i] == path[0])
			{
				for (j = 0; path[j] != '\0'; j++)
				{
					if (env[h][i + j] == path[j])
					{
						count++;
					}
				}
				if (count == n_len)
				{
					ret = &env[h][i];
					break;
				}
			}
		}
	}
	buffer = _strdup(ret);
	head = token_path(buffer);
	free(buffer);
	return (head);
}

/**
 * token_path - tokenizer path
 *
 * @path: string path
 *
 * Return: pointer to string 2d path
 */
path_t *token_path(char *path)
{
	path_t *head = NULL;
	char *pathcp[1024], *token, *final[1024];
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
		final[i] = token;
		add_node_end(&head, token);
		token = strtok(NULL, del);
		i++;
	}
	final[i] = NULL;

	return (head);
}
