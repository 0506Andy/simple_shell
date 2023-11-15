#include "main.h"

/**
 * printParentPID- prints parent pid
 * Returns:void
 */
void printParentPID(void)
{
	int z, i, j, k;
	char rps;
	char pid_str[20];

	pid_t parent_pid = getppid();

	i = 0;
	while (parent_pid > 0)
	{
		pid_str[i] = '0' + (parent_pid % 10);
		parent_pid /= 10;
		i++;
	}

	z = i;
	rps[20];

	for (j = 0; j < z; j++)
	{
		rps[j] = pid_str[z - j - 1];
	}

	rps[z] = '\n';

	write(STDOUT_FILENO, rps, z + 1);
}
