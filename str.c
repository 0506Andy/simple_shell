#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @src:Points to the string appended to dest
 * @dest: Points to the string to be appended
 * Return:dest
 */
char *_strcat(char *dest, char *src)
{
	char* ptr = dest;

	if (dest == NULL || src == NULL)
		return (dest);

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0')
	{
		if (ptr < dest + MAX_DEST_SIZE - 1)
		{
			*ptr = *src;
			ptr++;
			src++;
		}
		else
		{
			return (dest);
		}
		src++;
	}
	*ptr = ('\0');

	return (dest);
}

/**
 * _strcpy - Copies string to a buffer
 * @dest: Buffer pointer
 * @src: String pointer
 * Return: Value of dest
 */
void _strcpy(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
	{
		return;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = ('\0');
}

/**
 * _strchr - Returns the pointer to first occurance of character
 * @s: String to be scanned
 * @c: Character where the pointer is to be returned
 * Return: NULL or Pointer
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}

/**
 * _strncmp - Compares two strings up to n characters
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 * Return: 0 if equal, negative if s1 < s2, positive if s1 > s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		if (*s1 == '\0' || n == 1)
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * _strcspn-Calculates the length of the initial segment of a string
 * @s: string to be searched.
 * @reject: null-terminated string containing characters to reject.
 * Return:len
 */
size_t _strcspn(const char *s, const char *reject)
{
	size_t len = 0;

	while (*s != '\0')
	{
		const char *r = reject;

		while (*r != '\0')
		{
			if (*s == *r)
			{
				return (len);
			}
			r++;
		}
		s++;
		len++;
	}
	return (len);
}
