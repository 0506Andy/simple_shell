#include "main.h"

/**
 * error_input - Function that prints an error messages.
 *
 * @copy: Copy.
 */
void error_input(char *copy)
{
    char *msj_error = NULL;
    int length = 0;

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

    const int STATUS = 32512;

    free(msj_error);
}
