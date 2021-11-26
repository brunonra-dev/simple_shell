#include <stdio.h>
#include <unistd.h>
/**
 * main - PID
 *
 * @ac: argument count
 * @av: arguments
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int i = 0;

	(void)(ac);

	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}

	printf("\n");

	return (0);
}
