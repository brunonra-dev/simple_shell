#include "main.h"
/**
 * commandex - Find command and execute
 *
 * @head: Pointer to path linked list
 * @buffer: Tokenized string
 * @string: User imput
 * @va: arguments
 *
 * Return: 0 on success or -1 on error
 */
int commandex(path_t *head, char **buffer, char *string, char **va)
{
	struct stat st;
	int flag = 0, i = 0;
	path_t *h = head;
	char *fullpath = NULL, *path = NULL, *slash = "/", *pathslash = NULL;

	while (h)
	{
		path = _strdup(h->path);

		for (i = 0; path[i]; i++)
			;
		if (path[i - 1] != '/') /*add slash at the end if don't exit*/
			pathslash = str_concat(path, slash);

		fullpath = str_concat(pathslash, buffer[0]); /*add command to the path*/

		if (!stat(fullpath, &st)) /*check if the file exist*/
		{
			buffer[0] = _strdup(fullpath);
			subprocess(buffer, string); /*execute command*/
			free(buffer[0]);
			free(path);
			free(fullpath);
			free(pathslash);
			flag = 1;
			break;
		}
		free(pathslash);
		free(fullpath);
		free(path);
		h = h->next;
	}
	if (flag == 0)
	{
		error(va, buffer, -3);
		return (-1);
	}

	return (0);
}
/**
 * str_concat - concatenates two strings.
 *
 * @s1: first array.
 * @s2: second array.
 *
 * Return: pointer to the concatenated array, or NULL if it fails.
 */
char *str_concat(char *s1, char *s2)
{
	char *con_str;
	int s1_len, s2_len;
	int i, j;

	i = j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (s1_len = 0; s1[s1_len] != 0; s1_len++)
		;
	for (s2_len = 0; s2[s2_len] != 0; s2_len++)
		;

	con_str = malloc(s1_len + s2_len + 1);
	if (con_str == 0)
	{
		return (NULL);
	}

	while (i <= s1_len)
	{
		con_str[i] = s1[i];
		i++;
	}

	while (j <= s2_len)
	{
		con_str[j + s1_len] = s2[j];
		j++;
	}

	return (con_str);
}
