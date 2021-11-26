#include <stdio.h>
#include <stdlib.h>

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

	while (1)
	{
		printf("$ ");

		bytes_read = getline(&string, &size, stdin);

		if (bytes_read == -1)
		{
			puts("ERROR!");
		}
		else
		{
			printf("%s", string);
		}
	}

	free(string);

	return (0);
}
