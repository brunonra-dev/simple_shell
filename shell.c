#include "main.h"
/**
 * main - Shell.
 *
 * @ac: agrument count
 * @va: arguments
 * @env: environment
 *
 * Return: 0 on success
 */
int main(int ac, char **va, char **env)
{
	int bytes_read, i, isa = 1;
	size_t size = 0;
	char *string = NULL, *token, *buffer[1024];
	const char *d = " \n";
	(void)ac, (void)va;

	isa = isatty(STDIN_FILENO);
	do {
		if (isa)
			printf("$ ");

		bytes_read = getline(&string, &size, stdin);
		if (bytes_read == -1)
		{
			perror("ERROR: getline");
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
		buffer[i] = token;

		if (buffer[0] == NULL) /**space and new line*/
			continue;
		if (check(buffer, env, string))
			continue;
		else if ((subprocess(buffer, string)))
		{
			printf("entree\n");
			continue;
		}
	} while (isa);
	return (0);
}
