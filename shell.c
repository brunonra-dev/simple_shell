#include "main.h"
#include <errno.h>
/**
 * main - Pseudo-Shell, main function
 *
 * @ac: agrument count
 * @va: arguments
 * @env: environment
 *
 * Return: 0 on success
 */
int main(int ac, char **va, char **env)
{
	int bytes_read = 0, i = 0, isa = 1;
	size_t size = 0;
	char *string = NULL, *token, *buffer[1024], *path = "PATH=";
	const char *d = " \n\t";
	path_t *head = NULL;
	(void)ac, (void)va;

	head = llpath(env, path);/*create linked list*/
	isa = isatty(STDIN_FILENO); /*INTERACTIVE/NON-INTERACTIVE*/
	do {
		if (isa)
			printf("$ ");
		bytes_read = getline(&string, &size, stdin);
		if (bytes_read == -1)
		{
			if (EOF == -1)
			{
				write(1, "exit\n", 5);
				free_list(head);
				_exitshell(string);
			}
			perror("ERROR:");
			return (-1);
		}
		/* tokenizer */
		i = 0;
		token = strtok(string, d);
		while (token)
		{
			buffer[i] = token;
			token = strtok(NULL, d);
			i++;
		}
		buffer[i] = NULL;

		if (buffer[0] == NULL) /**space, tab and new line*/
			continue;
		if (check(buffer, env, string, head)) /*check if is built-in or no*/
			continue;
		else
			commandex(head, buffer, string);
	} while (isa);
	if (!isa)
		freeisa(head, string); /*free NON-INTERACTIVE*/
	return (0);
}
