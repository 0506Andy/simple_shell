#include "main.h"

/**
 * _word - Function that counts the amount of words
 * that the command has according to the spaces.
 *
 * @strn: is a pointer of the incoming string
 * Return: the number of words
 */
int _word(const char *strn)
{
	int count = 0;
	int word = 0;

	while (*strn)
	{
		if (*strn == ' ' || *strn == '\n' || *strn == '\t' || *strn == '='
				|| *strn == ':')
			count = 0;

		else if (count == 0)
		{
			count = 1;
			word++;
		}
		strn++;
	}
	return (word);
}

/**
 * free_tokens - Function that releases the tioken,
 * iteration by iteration until reaching null.
 *
 * @token: token
 */
void free_tokens(char **token)
{
	int i = 0;

	while (token[i] != NULL)
	{
		free(token[i]);
		i++;
	}
	free(token);
}

/**
 * tk_cm - The function that splits a string based on the delimiter.
 * @comand: a pointer the command received
 * @delim: a pointer to the delimiter of the tokenize
 * Return: 0 for free, and return the result of the tokenize
 */
char **tk_cm(const char *comand, const char *delim)
{
	char **token = NULL;
	int i, word = 0;
	char *non_const_comand = strdup(comand);

	if (non_const_comand == NULL)
		return (NULL);

	word = _word(non_const_comand);

	token = _calloc((word + 1), sizeof(char *));
	if (token == NULL)
	{
		free(non_const_comand);
		return (NULL);
	}
	token[0] = strtok(non_const_comand, delim);
	if (token[0] == NULL)
	{
		free(token);
		free(non_const_comand);
		return (NULL);
	}
	for (i = 1; i < word + 1; i++)
	{
		token[i] = strtok(NULL, delim);
	}
	free(non_const_comand);

	return (token);
}
