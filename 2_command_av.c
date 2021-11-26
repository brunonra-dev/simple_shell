#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - print line
 *
 * Return: Always 0.
 */

int main(void)
{
	int bytes_read;
	size_t size = 0;
	char *string = NULL;
	char *token;
	const char *d = " ";

	printf("$ ");

	bytes_read = getline(&string, &size, stdin);

	if (bytes_read == -1)
	{
		puts("ERROR!");
		return (-1);
	}

	token = strtok(string, d);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, d);
	}

	free(string);

	return (0);
}
