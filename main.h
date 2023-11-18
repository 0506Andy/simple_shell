#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_DEST_SIZE 1000
extern char **environ;

extern int STATUS;
/**
 * struct built_in - Struct built_in
 *
 * @key: Variable.
 * @e: Function.
 */
typedef struct built_in
{
	char *key;
	int (*e)();
} op_t;

void *safe_malloc(size_t size);
char *strdup_safe(const char *str);
void _puts(const char *str);
char *get_command(void);
int (*get_built_in(char *s))(void);
void check_built_in(int (*e)(), char **buffer, char *command);
void freess(char *path, char **list_token);
void freesess(char *path, char **list_token, char *command);
int _word(const char *strn);
void free_tokens(char **token);
void *_calloc(size_t num_elements, size_t element_size);
void _strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strcspn(const char *s, const char *reject);
int myStrcmp(const char *s1, const char *s2);
size_t myStrlen(const char *s);
char *_strdup(const char *str);
char **tk_cm(const char *comand, const char *delim);
void error_input(char *copy);
char *path_d(char *comd);
void *_calloc(size_t num_elements, size_t element_size);
void printParentPID(void);
int _putchar(char c);
void print_environment(void);
int _unsetenv(const char *name);
char *_getenv(const char *name);
int _setenv(const char *name,
		const char *value, int overwrite);
void env_builtin(void);
int execut(char **list_token, char *path);
void exit_builtin(void);
char *get_env(void);
char *path_d(char *comd);
void run_shell(void);
void readline(void);
char **splitString(const char *str, const char *delimiter, int *count);
void printErrorMessage(const char *message);

#endif /* MAIN_H */
