#include "main.h"

/**
 * main - Shell.
 *
 * Return: 0 on success
 */

int main(void)
{
	int bytes_read, status, ex, i;
	size_t size = 0;
	char *string = NULL, *token;
	const char *d = " \n";
	char *str[1024];
	pid_t child_pid;

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
			str[i] = token;
			token = strtok(NULL, d);
			i++;
		}
		str[i] = token;

		/* subprocess */
		child_pid = fork();
		if (child_pid == -1)
			perror("ERROR: fork");

		/* subprocess execve */
		if (child_pid == 0)
		{
			ex = execve(str[0], str, NULL);
			if (ex == -1)
			{
				perror("ERROR: execve");
				free(string);
				return (-1);
			}
			free(string);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
