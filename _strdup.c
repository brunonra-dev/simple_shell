#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 *
 * @str: new allocated array.
 *
 * Return: pointer to the new allocated array, or NULL if it fails.
 */

char *_strdup(char *str)
{
	char *new_str;
	int str_len;
	int i = 0;

	if (str != 0)
	{
		for (str_len = 0; str[str_len] != 0; str_len++)
			;

		str_len++;

		new_str = malloc(str_len);

		if (new_str != 0)
		{
			while (i < str_len)
			{
				new_str[i] = str[i];
				i++;
			}
			return (new_str);
		}
		else
			return (NULL);
	}
	else
		return (NULL);

}
