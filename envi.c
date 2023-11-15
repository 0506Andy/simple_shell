#include "main.h"
void print_environment(void)
int _unsetenv(const char *name)	
char *_getenv(const char *name)
int _setenv(const char *name, const char *value, int overwrite)
/**
 * print_environment - prints environment
 * Return:void
 */
void print_environment(void)
{
	char **environ;
	char **env = environ;
	char *current_env;

	while (*env != NULL)
	{
		*current_env = *env;

		while (*current_env != '\0')
		{
			write(STDOUT_FILENO, current_env, 1);
			current_env++;
		}
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * _getenv - retrieves environment value
 * @name:environment nsme
 * Return:NULL
 */
char *_getenv(const char *name)
{
	char **env = environ;
	size_t name_length = myStrlen(name);

	while (*env != NULL)
	{
		if (_strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
		{
			return (&(*env)[name_length + 1]);
		}
		env++;
	}
	return (NULL);
}

/**
 * _setenv - sets environments
 * @name:name of environment
 * @value:newvalue to be set to environment
 * @overwrite: flag to overwrite
 * Return:0 success
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t new_env_len;
	char *new_env;
	int i, num_vars;
	char *new_env, **new_environ;
	char **env;
	size_t name_lenght;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		return (-1);
	}
	**env = environ;
	name_length = myStrlen(name);

	while (*env != NULL)
	{
		if (_strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
		{
			if (!overwrite)
			{
				return (0);
			}
			*new_env = malloc(name_length + strlen(value) + 2);
			if (new_env == NULL)
			{
				return (-1);
			}
			_strcpy(new_env, name);
			_strcat(new_env, "=");
			_strcat(new_env, value);
			*env = new_env;

			return (0);
		}
		env++;
	}
	new_env_len = name_length + strlen(value) + 2;
	*new_env = malloc(new_env_len);

	if (new_env == NULL)
	{
		return (-1);
	}
	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);

	num_vars = 0;

	while (environ[num_vars] != NULL)
	{
		num_vars++;
	}

	**new_environ = malloc((num_vars + 2) * sizeof(char *));

	if (new_environ == NULL)
	{
		free(new_env);
		return (-1);
	}

	for (i = 0; i < num_vars; i++)
	{
		new_environ[i] = environ[i];
	}

	new_environ[num_vars] = new_env;
	new_environ[num_vars + 1] = NULL;

	environ = new_environ;

	return (0);
}

/**
 * _unsetenv - removes environment
 * @name:name if environment
 * Return: 0 success
 */
int _unsetenv(const char *name)
{
	char **env = environ;
	size_t name_leght = myStrlen(name);

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		return (-1);
	}

	while (*env != NULL)
	{
		if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
		{
			free(*env);

			while (env[1] != NULL)
			{
				env[0] = env[1];

				env++;
			}
			*env = NULL;

			return (0);
		}
		env++;
	}
	return (0);
}

