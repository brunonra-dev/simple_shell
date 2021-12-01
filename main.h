#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct list_s - singly linked list
 * 
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */

typedef struct list_s
{
    char *str;
    struct list_s *next;
} path_t;

/* Prototypes */
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int subprocess(char *buffer[], char *string);
char *findsubstring(char **string, char *needle);
char **getpath(char **path);

/* Prototypes Built-in*/
int get_builtin(char *token, va_list args);
void _printenv(char **env);

#endif
