#include "main.h"
/**
 * write_prompt - writes prompt
 * @prompt: prompt written
 * Return:ret
 */
void write_prompt(const char *prompt)
{
	write(1, prompt, strlen(prompt));
}

/**
 * main - check the code and,
 *
 * Return: Always 0.
 */
int main(void)
{
	int STATUS = 0;
	int (*func)() = NULL;
	char *pront = "myShell$: ", *command = NULL, **list_token = NULL;
	char *path = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write_prompt(pront);

		command = get_command();
		if (command == NULL)
			continue;
		list_token = tk_cm(command, " \n\t");
		if (!list_token)
		{
			free(command);
			continue;
		}
		func = get_built_in(list_token[0]);
		if (func)
		{
			if (strcmp(list_token[0], "exit") == 0)
			{
				freesess(path, list_token, command);
				free(command);
				return (STATUS);
			}
			check_built_in(func, list_token, command);
			continue;
		}
		if (strcmp(list_token[0], "env") == 0)
		{
			char **env = environ;
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			freesess(path, list_token, command);
			continue;
		}
		path = path_d(list_token[0]);

		if (path)
		{
			if (execut(list_token, path) == -1)
			{
				error_input(command);
				freess(path, list_token);
				continue;
			}
			freesess(path, list_token, command);
			continue;
		}
		freess(path, list_token);

		if (!isatty(STDIN_FILENO))
			break;
	}
	return STATUS;
}
