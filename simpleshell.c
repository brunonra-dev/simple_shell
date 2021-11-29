#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 * main - hola
 *
 * Return: 0
 */

int main(void)
{
	int bytes_read, status, ex;
	size_t size = 0;
	char *string = NULL, *token;
	const char *d = " ";
	char *str[1024];
	int i = 0;
	pid_t child_pid;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&string, &size, stdin);
		if (bytes_read == -1)
		{
			perror("ERROR!");
			return (-1);
		}

		/* tokenizer */
		token = strtok(string, d);
		while (token)
		{
			str[i] = token;
			token = strtok(NULL, d);
			i++;
		}

		/* subprocess */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("ERROR!");
			return (-1);
		}

		/* subprocess execve */
		if (child_pid == 0)
		{
			ex = execve(str[0], &string, NULL);
			if (ex == -1)
			{
				perror("ERROR!");
				return (-1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(string);
	return (0);
}
