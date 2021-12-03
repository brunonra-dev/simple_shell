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
	while (head)
	{
		free(head->path);
		free(head);
		head = head->next;
	}
}
