#include "main.h"
/**
 *
 *
 *
 */
int check(char **buffer, char **env, char *string, path_t *head)
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
		return (1);
	case 2:
		free_list(head);
		_exitshell(string);
		return (1);

	default:
		ret = ruta(buffer, string);
	}
	return (ret);
}
/**
 *
 *
 */

int ruta(char **buffer, char *string)
{
	int i = 0, ret = 0;

	while (buffer[0][i])
	{
		if (buffer[0][i] == '/')
		{
			ret = subprocess(buffer, string);
			break;
		}
		i++;
	}
	return (ret);
}
