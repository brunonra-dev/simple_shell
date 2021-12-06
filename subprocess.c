#include "main.h"
/**
 * subprocess - create a child process and execute command
 *
 * @buffer: tokenized string
 * @string: string getline
 *
 * Return: 1 on Success or 0 on error
 */
int subprocess(char *buffer[], char *string)
{
	pid_t child_pid;
	int ex, status;

	child_pid = fork();
	if (child_pid == -1)
		perror("ERROR: fork");

	/* subprocess execve */
	if (child_pid == 0)
	{
		ex = execve(buffer[0], buffer, NULL);
		if (ex == -1)
		{
			perror("ERROR:");
			free(string);
			return (0);
		}
		free(string);
	}
	else
	{
		wait(&status);
	}
	return (1);
}
