#include "main.h"

/**
 * printErrorMessage- prints error message
 * @message:message to be printed
 * Return : void
 */
void printErrorMessage(const char *message)
{
	while (*message != '\0')
	{
		_putchar(*message++);
	}
	_putchar('\n');
}

/**
 * _strdup - Duplicates a string using dynamic memory allocation.
 * @src: The input string to be duplicated.
 * Return:duplicate
 */
char *_strdup(const char *src)
{
	char *duplicate;
	size_t length;

	if (src == NULL)
	{
		return (NULL);
	}

	length = myStrlen(src);

	duplicate = (char *)malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
	{
		return (NULL);
	}
	_strcpy(duplicate, src);

	return (duplicate);
}

