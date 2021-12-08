#include "main.h"
/**
 * _printenv - print on screen the enviroment
 *
 * @env: enviroment
 */
void _printenv(char **env)
{
	int h, i;
	(void)(env);

	for (h = 0; environ[h]; h++)
	{
		for (i = 0; environ[h][i] != '\0'; i++)
		{
			_putchar(environ[h][i]);
		}
		_putchar('\n');
	}

}

/**
 * _exitshell - exit shell and free string
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
 * @head: pointer to begining linked list
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
/**
 * ctrlD - exit on ctrl+d
 *
 * @head: pointer to path linked list
 * @string: user input
 */
void ctrlD(path_t *head, char *string)
{
	write(1, "exit\n", 5);
	free_list(head);
	_exitshell(string);
}
