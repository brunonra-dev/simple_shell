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
	size_t size = 10;
	char *string = NULL, *token, *buffer[1024], *path = "PATH=";
	const char *d = " \n";
	path_t *head = NULL;
	(void)ac, (void)va;

	head = _getpath(env, path);/*crea linked list*/
	isa = isatty(STDIN_FILENO); /*verifica si es INTERACTIV/NON-INTERACTIV*/
	do {
		if (isa)
			printf("$ ");
		bytes_read = getline(&string, &size, stdin); /*paste stdin in string*/
		if (bytes_read == -1)
		{
			perror("ERROR: getline");
			return (-1);
		}
		/* tokenizer */
		i = 0;
		token = strtok(string, d); /*separa string por delimitador*/
		while (token)
		{
			buffer[i] = token;
			token = strtok(NULL, d);
			i++;
		}
		buffer[i] = token;

		if (buffer[0] == NULL) /**space and new line*/
			continue;
		if (check(buffer, env, string, head)) /*check if is built-in or no*/
		{
			continue;
		}
		else
		{
			rutecheck(head, buffer, string); /**si el comando no tiene / se le agrega y
		se corrobora la existencia d ela ruta, si exite se ejecuta**/
		}
	} while (isa);
	return (0);
}
