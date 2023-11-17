#include "main.h"

/**
 * get_env - get environment
 *
 * Return: NULL.
 *
 */
char *get_env(void)
{
	int i = 0;
	char *path = NULL;

	while (environ && environ[i])
	{
		if (_strncmp(environ[i], "PATH", 4) == 0)
		{
			path = _strdup(environ[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * path_d - the function
 *
 * @comd: dsaf
 * Return: dfsa
 */
char *path_d(char *comd)
{
	char *path = NULL, **rout = NULL;
	char *comand = NULL;
	int i = 1;
	struct stat st;

	if (stat(comd, &st) == 0)
	{
		comand = _strdup(comd);
		return (comand);
	}
	path = get_env();

	if (!path)
		return (NULL);

	rout = tk_cm(path, "=:");
	
	while (rout[i] != NULL)
	{
		comand = _calloc((myStrlen(rout[i]) + myStrlen(comd) + 2), sizeof(char));
		if (comand == NULL)
		{
			free(comand);
			return (NULL);
		}
		myStrcmp(comand, rout[i]);
		_strcat(comand, "/");
		_strcat(comand, comd);
		if (stat(comand, &st) == 0)
		{
			free(path);
			free(rout);
			return (comand);
		}
		free(comand);
		i++;
	}
	free(path);
	free(rout);
	error_input(comd);
	return (NULL);
}
