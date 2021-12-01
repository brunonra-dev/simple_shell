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
	char *path = _getpath(env, "PATH");
	(void)ac, (void)va, (void)path;

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

		if (!(_strcmp(buffer[0], "env")))
			_printenv(env);
		else if (!(_strcmp(buffer[0], "exit")))
			_exitshell(string);
		else if (subprocess(buffer, string))
			continue;
		else
			perror("ERROR: no es un comando");
	}
	return (0);
}
