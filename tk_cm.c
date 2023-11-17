#include "main.h"

/*char **tk_cm(char *input, const char *delimiters)
{
	int token_count = 1, i = 0;
	char *token;
	char *copy = _strdup(input);
	char **tokens = NULL;
	
	for (char *ptr = strtok(copy, delimiters); ptr; ptr = strtok(NULL, delimiters))
	
	{
		token_count++;
	}
	
	tokens = (char **)malloc(token_count * sizeof(char *));
	
	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	
	for (token = strtok(input, delimiters); token; token = strtok(NULL, delimiters))
	{
		tokens[i] = _strdup(token);
		i++;
	}
	free(copy);
	tokens[i] = NULL;
	
	return (tokens);
}*/

void _puts(const char *str)
{
	size_t i = 0;
	
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

void error_input(char *comd)
{
	_puts("Error: Command not found: ");
	_puts(comd);
	_putchar('\n');
}
