#include "main.h"

/**
 * readline - reads and prints a line
 * Return : void
 */
void readline(void)
{
	int i;
	char command[100];

	_putchar('$');
	_putchar(' ');

	fgets(command, sizeof(command), stdin);

	for (i = 0; command[i] != '\0'; i++)
	{
		_putchar(command[i]);
	}
}
