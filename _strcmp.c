#include "main.h"
/**
 * *_strcmp - compares two strings.
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: return difference.
 */
int _strcmp(char *s1, char *s2)
{
	int s1_len, s2_len, i, ret;

	for (s1_len = 0; s1[s1_len] != '\0'; s1_len++)

	for (s2_len = 0; s2[s2_len] != '\0'; s2_len++)

	for (i = 0; i < s1_len; i++)
	{
		if (s1[i] != s2[i])
		{
			ret = s1[i] - s2[i];
			break;
		}
		else
			ret = 0;
	}

	return (ret);
}
