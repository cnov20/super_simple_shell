#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define PROMPT "$ "
#define BUFF_SIZE 1024
#define pid_max 32768
#define DELIMITER "\n\t\r\a "
#define EXIT_FAILURE    1       /* Failing exit status.  */
#define EXIT_SUCCESS    0       /* Successful exit status.  */

extern char **environ;

typedef struct path_link
{
	char *token;
	struct path_link *next;

} link_t;

typedef struct shell_node
{
        char *token;
        struct shell_node *next;

} shell_node_t;

char *_getenv_PATH(const char *name);
shell_node_t *createlist_PATH(shell_node_t **head, char *token);
int execve(const char *filename, char *const argv[], char *const envp[]);
void _putstring(char *str);
unsigned int _strlen(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strdup(char *src);
void shell_exit(int status);
char **tokenizer(char *line);
char *_strncat(char *dest, char *src, int n);

#endif /*SHELL_H*/
