#include "main.h"

/**
 * main - Shell.
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[])
{
	int bytes_read, i;
	size_t size = 0;
	char *string = NULL, *token;
	const char *d = " \n";
	char *buffer[1024];
	(void)argc, (void)argv;

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
