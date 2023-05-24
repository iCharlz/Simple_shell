#include "shell.h"

/**
 * is_chain - Function that tests current char in buf
 * @info: Parameter structure
 * @buf: Character buf
 * @i: The address of the current position in buffer
 * Return: chain delimeter 1, otherwise 0
 */

int is_chain(info_t *info, char *buf, size_t *i)
{
	size_t n = *i;

	if (buf[n] == '|' && buf[n + 1] == '|')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[n] == '&' && buf[n + 1] == '&')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[n] == ';') /* found end of command */
	{
		buf[n] = 0; /* replace semicolon with NULL */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*i = n;
	return (1);
}

/**
 * check_chain - func that checks if we continue chaining based on last status
 * @info: Parameter structure
 * @buf: Character Buf
 * @i: current position in buf
 * @c: The starting position in buffer
 * @len: The length of the buffer
 * Return: Void
 */

void check_chain(info_t *info, char *buf, size_t *i, size_t c, size_t len)
{
	size_t n = *i;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[c] = 0;
			n = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[c] = 0;
			n = len;
		}
	}

	*i = n;
}

/**
 * replace_alias - Funtion that will replace aliases in tokenised str
 * @info: Parameter struct
 * Return: 1 if replaced, otherwise 0
 */

int replace_alias(info_t *info)
{
	int c;
	list_t *node;
	char *i;

	for (c = 0; c < 10; c++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		i = _strchr(node->str, '=');
		if (!i)
			return (0);
		i = _strdup(i + 1);
		if (!i)
			return (0);
		info->argv[0] = i;
	}
	return (1);
}

/**
 * replace_vars - Function that replaces vars in tokenised str
 * @info: Parameter structure
 * Return: 1 if replaced, otherwise 0
 */

int replace_vars(info_t *info)
{
	int c = 0;
	list_t *node;

	for (c = 0; info->argv[c]; c++)
	{
		if (info->argv[c][0] != '$' || !info->argv[c][1])
			continue;
		if (!_strcmp(info->argv[c], "$"))
		{
			replace_string(&(info->argv[c]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if  (!_strcmp(info->argv[c], "$$"))
		{
			replace_string(&(info->argv[c]),
					_strdup(convert_number(getpid(), 10, 0)));
					continue;
		}
		node = node_starts_with(info->env, &info->argv[c][1], '=');
		if (node)
		{
			replace_string(&(info->argv[n]),
					_strdup(_strchr(node->str, '=') + 1));
					continue;
		}
		replace_string(&info->argv[c], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - A function that replaces a string
 * @old: The address of the old str
 * @new: The new str
 * Return: 1 if replaced, otherwise 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
