#include "main.h"
char *str_concat(char *s1, char *s2);
/**
 *
 *
 *
 *
 *
 */
int rutecheck(path_t *head, char **buffer, char *string)
{
	struct stat st;
	int flag = 0;
	path_t *h = head;
	char *fullpath = NULL, *path = NULL, *slash = "/", *pathslash = NULL;

	while (h)
	{
		path = _strdup(h->path);
		pathslash = str_concat(path, slash);

		fullpath = str_concat(pathslash, buffer[0]);

		if (!stat(fullpath, &st))
		{
			buffer[0] = _strdup(fullpath);
			subprocess(buffer, string);
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
		perror("ERROR: ");
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
