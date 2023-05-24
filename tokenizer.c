#include "shell.h"

/**
 * **strtow - String splited into words & repeat delimeters ignored
 * @str: Input str
 * @i: Delimeter str
 *
 * Return: Pointer to array of str, or NULL on fail
 */

char **strtow(char *str, char *i)
{
	int n, y, h, c, numwords = 0;
	char **j;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!i)
		i = " ";
	for (n = 0; str[n] != '\0'; n++)
		if (!is_delim(str[n], i) && (is_delim(str[n + 1], i) || !str[n + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	j = malloc((1 + numwords) * sizeof(char *));
	if (!j)
		return (NULL);
	for (n = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[n], i))
			n++;
		h = 0;
		while (!is_delim(str[n + h], i) && str[n + h])
			h++;
		j[y] = malloc((h + 1) * sizeof(char));
		if (!j[y])
		{
			for (h = 0; h < y; h++)
				free(j[h]);
			free(j);
			return (NULL);
		}
		for (c = 0; c < h; c++)
			j[y][c] = str[n++];
		j[y][c] = 0;
	}
	j[y] = NULL;
	return (j);
}

/**
 * **strtow2 - A function that splits str into words
 * @str: String input
 * @i: Delimeter
 * Return: Point to array of str, or NULL on fail
 */
char **strtow2(char *str, char i)
{
	int n, y, h, c, numwords = 0;
	char **j;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (n = 0; str[n] != '\0'; n++)
		if ((str[n] != i && str[n + 1] == i) ||
				(str[n] != i && !str[n + 1]) || str[n + 1] == i)
			numwords++;
	if (numwords == 0)
		return (NULL);
	j = malloc((1 + numwords) * sizeof(char *));
	if (!j)
		return (NULL);
	for (n = 0, y = 0; y < numwords; y++)
	{
		while (str[n] == i && str[n] != i)
			n++;
		h = 0;
		while (str[n + h] != i && str[n + h] && str[n + h] != i)
			h++;
		j[y] = malloc((h + 1) * sizeof(char));
		if (!j[y])
		{
			for (h = 0; h < y; h++)
				free(j[h]);
			free(j);
			return (NULL);
		}
		for (c = 0; c < h; c++)
			j[y][c] = str[n++];
		j[y][c] = 0;
	}
	j[y] = NULL;
	return (j);
}
