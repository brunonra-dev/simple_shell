#include "main.h"
char *_strcat(char *dest, char *src);
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
	int i = 0, s = 0;
	path_t *h = head;
	char *dest, *aux;

	while (h)
	{
		aux = _strdup(h->path);
		while (aux[i])
			i++;
		if (aux[i - 1] != '/')
			dest = _strcat(aux, "/");

		free(aux);

		dest = _strcat(dest, buffer[0]);
		/**LIBERAR AUx*/

		if (!stat(dest, &st))
		{
			buffer[0] = _strdup(dest);
			s = subprocess(buffer, string);
			printf("BUFFER= %s\n", buffer[0]);
			free(buffer[0]);
			break;
		}
		h = h->next;
	}

	return (0);
}
/**
  *_strcat - une dos strings
  *@src: string inicial
  *@dest: string final
 *Return: retorna string final
 */
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != 0; a++)
	{
	}
		for (b = 0; src[b] != 0; b++)
		{
			dest[a] = src[b];
			a++;
		}
		return (dest);
}
