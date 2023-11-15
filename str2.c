#include "main.h"

/**
 * myStrcmp - Compares two strings
 * @s1:String to be compared
 * @s2:String to be compared
 * Return:(s1[i] - s2[i])
 */
int myStrcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * myStrlen - Return length os a string
 * @s: Length of string
 * Return: length
 */
int myStrlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _calloc - allocate block of memory for array
 * @num_elements: number of elements in array
 * @element_size:size of each element
 * Return: void
 */
void *_calloc(size_t num_elements, size_t element_size)
{
	if (num_elements == 0 || element_size == 0)
	{
		return (NULL);
	}

	size_t total_size = num_elements * element_size;

	if (total_size / num_elements != element_size)
	{
		return (NULL);
	}
	void *ptr = malloc(total_size);

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (size_t i = 0; i < total_size; i++)
	{
		((char *)ptr)[i] = 0;
	}
	return (ptr);
}
