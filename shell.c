#include "main.h"
void sigintHandler(int n);
/**
 * main - Pseudo-Shell main function
 *
 * @ac: agrument count
 * @va: arguments
 * @env: environment
 *
 * Return: 0 on success
 */
int main(int ac, char **va, char **env)
{
	int bytes_read = 0, i = 0, isa = 1, checkret;
	size_t size = 0;
	char *string = NULL, *token, *buffer[1024], *path = "PATH=";
	const char *d = " \n\t";
	path_t *head = NULL;
	(void)ac, (void)va;

	head = llpath(env, path); /* Create linked list */
	isa = isatty(STDIN_FILENO); /* INTERACTIVE / NON-INTERACTIVE */
	signal(SIGINT, sigintHandler);
	do {
		if (isa)
		{
			_putchar('$');
			_putchar(' ');
		}
		bytes_read = getline(&string, &size, stdin);
		if (bytes_read == -1)
		{
			if (EOF == -1)
				ctrlD(head, string);
			perror("ERROR:");
			return (-1);
		}
		/* Tokenizer */
		token = strtok(string, d);
		for (i = 0; token; i++)
		{
			buffer[i] = token;
			token = strtok(NULL, d);
		}
		buffer[i] = NULL;

		if (buffer[0] == NULL) /**space, tab and new line*/
			continue;
		/* check if it's built-in or route */
		checkret = check(va, buffer, env, string, head);
		if (checkret == 0 || checkret == -4 || checkret == -2)
			continue;
		commandex(head, buffer, string, va);
	} while (isa);
	if (!isa)
		freeisa(head, string); /* NON-INTERACTIVE free */
	return (0);
}

/**
 * sigintHandler - cach ctrl+c
 *
 * @n: int
 */

void sigintHandler(int n)
{
	(void)n;

	signal(SIGINT, sigintHandler);
	_putchar('\n');
	_putchar('$');
	_putchar(' ');
}
