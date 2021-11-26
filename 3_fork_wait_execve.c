#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;
	int i = 5;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	while (i)
	{
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	my_pid = getpid();
	printf("My pid is %u\n", my_pid);

	if (child_pid)
	{
		wait(&my_pid);
		printf("Termino todo ======\n");
	}
	else
	{
		printf("(%u) Nooooooooo!\n", my_pid);
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	i--;
	}
	return (0);
}
