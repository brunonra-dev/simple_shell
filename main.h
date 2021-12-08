#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>


extern char **environ;

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
int check(char **va, char **buffer, char **env, char *string, path_t *head);
int subprocess(char *buffer[], char *string);
int commandex(path_t *head, char **buffer, char *string, char **va);
int route(char **va, char **buffer, char *string);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
char **tokenizer(char *string, char **buffer);
void free_list(path_t *head);
void freeisa(path_t *head, char *string);
void ctrlD(path_t *head, char *string);
void error(char **va, char **buffer, int errtype);
path_t *add_node_end(path_t **head, char *str);
path_t *llpath(char **env, char *path);
path_t *token_path(char *path);

/* Prototypes Built-in*/
void _printenv(char **env);
void _exitshell(char *string);

#endif
