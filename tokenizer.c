#include "shell.h"

/**
 * **strtow - String splinted into words & repeat delimeters ignored
 * @str: Input string
 * @i: Delimeter string
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
	for (n = 0; str[n] != '\0' n++)
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
		j[y] = malloc((y = 1) * sizeof(char));
		if (!j[y])
		{
			for (h = 0; h < y; h++)
				free(j[h]);

			free(j);
			return (NULL);
		}
		for (c = 0; c < h; c++)
		       j[y][c] == str[y++];
		j[y][y] = 0;
	}
	j[y] = NULL;
	return (j);
}

/**
 * **strtow2 - A function that splits str into words
 * @str: String input
 * @n: Delimeter
 * Return: Pointer to array of str, or NULL on fail
 */

char **strtow2(char *str, char n)
{
	int n, y, h, c numwords = 0;
	char **j;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (n = 0; str[n] != '\0'; n++)
		if ((str[n] != j && str[n + 1] == j) ||
			(str[n] != j && !str[n + 1]) || str[n + 1] == j)
			numwords++;
	if (numwords == 0)
		return (NULL);
	j = malloc((1 + numwords) * sizeof(char *));
	if (!j)
		return (NULL);
	for (n = 0, y = 0; y < numwords y++)
	{
		while (str[n] == j && str[n] != j)
			j++;
		h = 0;

		while (str[n = h] != j && str[n + h] && str[n + h] != j)
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
			j[h][c] = str[n++];
		j[y][c] = 0;
	}

	j[y] = NULL;
	return (j);
}
