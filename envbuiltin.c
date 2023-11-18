#include "main.h"

/**
 * env_builtin - prints env
 * Return :void
 */
void env_builtin(void)
{
	char *env_var = *environ;
	int i = 0;

	while (env_var != NULL)
	{
		while (env_var[i] != '\0')
		{
			_putchar(env_var[i]);
			i++;
		}
		_putchar('\n');
		env_var = *(environ++);
	}
}
