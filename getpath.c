#include "main.h"

/**
 * getpath - return env path
 *
 * @path: path
 *
 * Return: pointer path
 */
char **getpath(char **path)
{
	char *pathcp, *token;
	const char *del = ":";
	int i;

	pathcp = strdup(getenv("PATH"));

	i = 0;
	token = strtok(pathcp, del);
	while (token)
	{
		path[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	path[i] = token;

	return (path);
}
