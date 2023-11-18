#include "main.h"

/**
 * safe_malloc - allocate memory fot error handling
 * @size: memory allocation size
 * Return:void
 */
void *safe_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
 * strdup_safe - allocate memory for a string and copy the content
 * @str: string to copy
 * Return: str dup
 */
char *strdup_safe(const char *str)
{
	char *dup_str = strdup(str);

	if (dup_str == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	return (dup_str);
}
/**
 * error_input - Function that prints an error messages.
 *
 * @copy: Copy.
 */
void error_input(char *copy)
{
	int status;
	int STATUS;
	char *msj_error = NULL;
	int length = 0;

	STATUS = 32512;

	status = write(STDERR_FILENO, copy, strlen(copy));
	if (status == -1)
	{
		perror("Error writing to stderr");
	}
	msj_error = _calloc((strlen(copy) + 23), sizeof(char));

	if (msj_error == NULL)
	{
		free(msj_error);
		return;
	}
	strcat(msj_error, "./hsh: ");
	strcat(msj_error, "1");
	strcat(msj_error, ": ");
	strcat(msj_error, copy);
	strcat(msj_error, ": not found\n");
	length = strlen(msj_error);

	if (write(2, msj_error, length) == -1)
	{
		perror("write");
	}
	exit(STATUS);
	free(msj_error);
}
