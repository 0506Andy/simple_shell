#include "main.h"

/**
 * custom_execve - executes new program
 * @pathname: path to the program
 * @argv: array of pointers to program arguments
 * @envp: arry of pointers to environment var
 * Return:resultfinal
 */
int custom_execve(const char *pathname, char *const argv[], char *const envp[])
{
	int resultfinal;

	resultfinal = execve(pathname, argv, envp);

	if (resultfinal == -1)
	{
		perror("execve");
	}
	return (resultfinal);
}
