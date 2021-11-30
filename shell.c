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
	int bytes_read, i;
	size_t size = 0;
	char *string = NULL, *token, *buffer[1024];
	const char *d = " \n";
	(void)ac, (void)va;

	if (findsubstring(env, "HOSTNAME"))
		printf("path encontrado");

	while (1)
	{
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

		subprocess(buffer, string);
	}
	return (0);
}
