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
