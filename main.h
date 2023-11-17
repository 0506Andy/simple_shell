#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
extern char **environ;
extern int status = 0;
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
#define STATUS status
int _word(char *strn)
void free_tokens(char **token)
char *tk_cm(const char *comand, const char *delim)
char *path_d(char *comd);
void *_calloc(size_t num_elements, size_t element_size);
void printParentPID(void);
int _putchar(char c);
void print_environment(void);
int _unsetenv(const char *name);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
void env_builtin(void);
int execut(char **list_token, char *path);
void exit_builtin(void);
void freess(char *path, char **list_token);
void freesess(char *path, char **list_token, char *command);
char *get_env(void);
char *path_d(char *comd);
void run_shell(void);
void readline(void);
void _strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strcspn(const char *s, const char *reject);
int myStrcmp(const char *s1, const char *s2);
int myStrlen(const char *s);
char **splitString(const char *str, const char *delimiter, int *count);
void printErrorMessage(const char *message);
char *_strdup(const char *str);
int custom_execve(const char *pathname, char *const argv[], char *const envp[]);
int custom_open(const char *pathname, int flags, mode_t mode);
ssize_t custom_read(int fd, void *buf, size_t count);
ssize_t custom_write(int fd, const void *buf, size_t count);
int custom_close(int fd);
int execut(char **list_token, char *path);
pid_t custom_fork(void);

#endif
