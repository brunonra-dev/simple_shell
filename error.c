#include "main.h"

/**
 * error - print error on screen
 *
 * @va: agruments
 * @buffer: tokenized string
 * @errtype: error type
 */

void error(char **va, char **buffer, int errtype)
{
	int i;
	char *filedir = "No such file or directory\n";
	char *command = "command not found\n";
	char *dir = "Is a directory\n";

	for (i = 0; va[0][i]; i++)
		_putchar(va[0][i]);

	_putchar(':');
	_putchar(' ');

	for (i = 0; buffer[0][i]; i++)
		_putchar(buffer[0][i]);

	_putchar(' ');

	if (errtype == -2)
		for (i = 0; filedir[i]; i++)
			_putchar(filedir[i]);
	if (errtype == -3)
		for (i = 0; command[i]; i++)
			_putchar(command[i]);
	if (errtype == -4)
		for (i = 0; dir[i]; i++)
			_putchar(dir[i]);
}
