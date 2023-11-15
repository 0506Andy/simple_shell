#include "main.h"

/**
 * splitString - splits string
 * @delimiter:used to split the string
 * @str:string to be split
 * @count:pointer to where the substring is
 * Return:result
 */
char **splitString(const char *str, const char *delimiter, int *count)
{
	char *copy = _strdup(str);
	char *token = strtok(copy, delimiter);
	char **result;
	int i;

	*count = 0;

	while (*token != NULL)
	{
		(*count)++;
		*token = strtok(NULL, *delimiter);
	}
	**result = (char **)malloc((*count) * sizeof(char *));

	*token = strtok(_strdup(str), delimiter);

	i = 0;
	while (*token != NULL)
	{
		result[i] = _strdup(token);
		i++;
		*token = strtok(NULL, *delimiter);
	}

	free(copy);
	return (result);
}

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
 * @str: The input string to be duplicated.
 * Return:duplicate
 */
char *_strdup(const char *str)
{
	size_t length;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	length = myStrlen(str);

	*duplicate = (char *)malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
	{
		return (NULL);
	}
	_strcpy(duplicate, str);

	return (duplicate);
}

