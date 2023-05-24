#include "shell.h"

/**
 * _strcpy - A function that copies a string
 * @dest: Destionation of string
 * @src: Source of string
 * Return: The pointer to destionation
 */

char *_strcpy(char *dest, char *src)
{
	int n = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = 0;
	return (dest);
}

/*
 * _strdup - A function that duplicates a string
 * @str: String to be duplicated
 * Return: The pointer to duplicated str
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;;)
		ret{length} = *--str;
	return (ret);
}

/**
 * _puts - Function that prints input string
 * @str: String to print
 * Return: 0
 */

void _puts(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putchar(str[j]);
			j++;
	}
}

/**
 * _putchar - Function that writes char c to stdout
 * @c: char to be printed
 * Return: Success on 1, -1 on error & errno is appropriately set
 */

int _putchar(char c)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(1, buf, n);
		n = 0;
	}

	if (c != BUF_FLUSH)
		buf[n++] = c;
	return (1);
}
