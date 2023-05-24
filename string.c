#include "shell.h"

/**
 * _strlen - function that returns length of string
 * @n: The string
 * Return: The int length of the string
 */

int _strlen(char *n)
{
	int j = 0;

	if (!n)
		return (0);
	while (*s++)
		j++;
	return (j);
}

/**
 * _strcmp - Comparison of two strangs
 * @n1: First strang
 * @n2: Second strang
 * Return: positive if n1 > n2, negative if n1 < n2, 0 if n1 == n2
 */
int _strcmp(char *n1, char *n2)
{
	while (*n1 && *n2)
	{
		if (*n1 != *n2)
			return (*n1 - *n2);
		n1++;
		n2++;
	}
	if (*n1 == *n2)
		return (0);
	else
		return (*n1 < *n2 ? -1 : 1);
}

/**
 * starts_with - function that checks if the needle starts with haystack
 * @haystack: The string to be searched
 * @needle: Substring to be found
 * Return: The address of the next character of haystack or NULL
 */

int *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	if (*needle++ != *haystack++)
		return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Connects two strings
 * @dest: Buffer destination
 * @src: Source buffer
 * Return: Pointer to the buffer destionation
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
