#include "main.h"
/**
 * findsubstring - locates a substring.
 *
 * @string: string.
 * @needle: characters to match.
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the character is not found.
 */
char *findsubstring(char **string, char *needle)
{
	int i, j, h, count, n_len;
	char *ret = '\0';

	i = j = h = 0;
	count = n_len = 0;

	while (needle[n_len] != '\0')
		n_len++;

	for (h = 0; string[h]; h++)
	{
		for (i = 0; string[h][i] != '\0'; i++)
		{
			count = 0;
			if (string[h][i] == needle[0])
			{
				for (j = 0; needle[j] != '\0'; j++)
				{
					if (string[h][i + j] == needle[j])
					{
						count++;
					}
				}
				if (count == n_len)
				{
					ret = &string[h][i];
					break;
				}
			}
		}
	}
	return (ret);
}

/**
*
*
*
*/
char **getpath(char **path)
{
	char *pathcp = *path, *token;
	const char *del = ":";
	int i;

	printf("soypathcp %s\n", pathcp);
	i = 0;
	token = strtok(pathcp, "=");
	while (token)
	{
		path[i] = token;
		token = strtok(NULL, "=");
		i++;
	}
	path[i] = token;
	i = 0;
	token = strtok(pathcp, del);
	while (token)
	{
		path[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	path[i] = token;
	return (path);
}
