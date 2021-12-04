#include "main.h"

/**
 * _printenv - show enviroment
 *
 * @env: env array
 */

void _printenv(char **env)
{
	int h, i;

	for (h = 0; env[h]; h++)
	{
		for (i = 0; env[h][i] != '\0'; i++)
		{
			_putchar(env[h][i]);
		}
		_putchar('\n');
	}

}

/**
 * _exit - exit shell
 *
 * @string: string to free
 */

void _exitshell(char *string)
{
	free(string);
	exit(0);
}

/**
 * free_list - free linked list
 *
 * @head: pointer to list_t
 */

void free_list(path_t *head)
{
	path_t *buffer;

	while (head)
	{
		buffer = head->next;
		free(head->path);
		free(head);
		head = buffer;
	}
}
