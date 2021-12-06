#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct path_s - linked list path
 *
 * @path: path env
 * @next: points to the next path
 *
 * Description: singly linked list node structure
 */
typedef struct path_s
{
	char *path;
	struct path_s *next;
} path_t;


/* Prototypes */
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int check(char **buffer, char **env, char *string, path_t *head);
path_t *add_node_end(path_t **head, char *str);
int subprocess(char *buffer[], char *string);
path_t *_getpath(char **env, char *path);
int rutecheck(path_t *head, char **buffer, char *string);
int ruta(char **buffer, char *string);
void free_list(path_t *head);

/* Prototypes Built-in*/
void _printenv(char **env);
void _exitshell(char *string);

#endif
