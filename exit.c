#include "main.h"

/**
 * exit_builtin - exits code
 * Return:void
 */
void exit_builtin(void)
{
	_putchar('\n');

	write(STDOUT_FILENO, "Exiting the shell...\n", 21);
	exit(EXIT_SUCCESS);
}
