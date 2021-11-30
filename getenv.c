#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 *
 */
int main(void)
{
	char *pathcp, *token;
	const char *del = ":";
	char *buff[1024];
	int i;

	pathcp = strdup(getenv("PATH"));

	i = 0;
	token = strtok(pathcp, del);
	while (token)
	{
		buff[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	buff[i] = token;
	for (i = 0; buff[i]; i++)
	{
		status
		printf("buff: %s\n", buff[i]);
	}
	return (0);
}
