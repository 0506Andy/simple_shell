#include "main.h"

/**
 * error_input - Function that prints an error messages.
 *
 * @copy: Copy.
 */
void error_input(char *copy)
{
	int status;
	const int STATUS = 32512;
	char *msj_error = NULL;
	int length = 0;

	status = write(STDERR_FILENO, copy, myStrlen(copy));
	if (status == -1)
	{
		perror("Error writing to stderr");
	}

    msj_error = _calloc((myStrlen(copy) + 23), sizeof(char));
    if (msj_error == NULL)
    {
        free(msj_error);
        return;
    }
    _strcat(msj_error, "./hsh: ");
    _strcat(msj_error, "1");
    _strcat(msj_error, ": ");
    _strcat(msj_error, copy);

    _strcat(msj_error, ": not found\n");
    length = myStrlen(msj_error);
   
    if (write(2, msj_error, length) == -1)
    {
        perror("write");
    }

    exit(STATUS);

    free(msj_error);
}
