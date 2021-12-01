#include "main.h"
char **token_path(char **path);
/**
 * _getpath - locates path on enviroment.
 *
 * @env: enviroment.
 * @path: string to match.
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the character is not found.
 */
char **_getpath(char **env, char *path)
{
	int i, j, h, count, n_len;
	char *ret = NULL;

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
	return (token_path(&ret));
}

/**
 * token_path - tokenizer path
 *
 * @path: string path
 *
 * Return: pointer to string 2d path
 */
char **token_path(char **path)
{
	char *pathcp[1024], *token, *final[1024];
	const char *del = ":";
	int i;

	i = 0;
	token = strtok(*path, "PATH=");
	while (token)
	{
		pathcp[i] = token;
		token = strtok(NULL, "=");
		i++;
	}
	pathcp[i] = token;
	i = 0;
	token = strtok(*pathcp, del);
	while (token)
	{
		final[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	final[i] = token;
	path = final;

	return (path);
}
