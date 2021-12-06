#include "main.h"
/**
 * freeisa - free all on the NON-INTERACTIVE mode
 *
 * @head: pointer to linked list
 * @string: user imput
 */
void freeisa(path_t *head, char *string)
{
	free_list(head);
	free(string);
}
