#include "main.h"
/**
 * check - check if is a built-in or a route
 *
 * @va: argument
 * @buffer: stdin tokenized
 * @env: enviroment
 * @string: user input
 * @head: pointer to path linked list
 *
 * Return: 0 on success or -1 on error
 */
int check(char **va, char **buffer, char **env, char *string, path_t *head)
{
	int c = 0, ret = 0;

	if (!(_strcmp(buffer[0], "env")))
		c = 1;
	if (!(_strcmp(buffer[0], "exit")))
		c = 2;

	switch (c)
	{
	case 1:
		_printenv(env);
		return (0);
	case 2:
		free_list(head);
		_exitshell(string);
		return (0);

	default:
		ret = route(va, buffer, string);
	}
	return (ret);
}
/**
 * route - check if is a route and execute
 *
 * @va: arguments
 * @buffer: stdin tokenized
 * @string: user input
 *
 * Return: 0 on success or -1 on error
 */

int route(char **va, char **buffer, char *string)
{
	struct stat st;
	int i = 0, ret = -1;

	while (buffer[0][i])
	{
		if (buffer[0][i] == '/')
		{
			if (!stat(buffer[0], &st) && S_ISDIR(st.st_mode))
			{
				error(va, buffer, -4);
				return (-4);
			}
			if (!stat(buffer[0], &st)) /*check if route and file exist*/
				ret = subprocess(buffer, string);
			else
			{
				error(va, buffer, -2);
				return (-2);
			}
			break;
		}
		i++;
	}
	return (ret);
}
