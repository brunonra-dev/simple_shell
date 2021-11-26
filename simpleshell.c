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
	int bytes_read;
	size_t size = 0;
	char *string = NULL, *token;
	const char *d = " ";
	char *str[1024];
	int i = 0, j = 0;
	pid_t child_pid;
	int ex;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&string, &size, stdin);
		if (bytes_read == -1)
		{
			perror("ERROR!");
		}

		token = strtok(string, d);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (-1);
		}

		while (token)
		{
			printf("token = %s", token);
			str[i] = token;
			token = strtok(NULL, d);
			i++;
		}
		printf("\n");
		while (str[j])
		{
			printf("str = %s", str[j]);
			j++;
		}
		printf("\n");

		if (child_pid == 0)
		{
			ex = execve(str[0], str, NULL);
			if (ex == -1)
			{
				perror("Error:");
			}
			printf("soy el hijo");
		}
		else
		{
			wait(&child_pid);
			printf("I'm father");
		}
	}
	free(&ex);
	free(string);
	return (0);
}
