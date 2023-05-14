#include "shell.h"

/**
 * is_cmd - a function that decides if a file is an executable command
 * @info: Info struct
 * @path: file path
 * Return: 1 if true, otherwise 0
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicates chars
 * @pathstr: The string of the path
 * @start: The start of the index
 * @stop: where the index stops
 * Return: pointer to a new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int j = 0, n = 0;

	for (n = 0, j = start; j < stop; j++)
		if (pathstr[j] != ':')
	buf[n] = 0;
	return (buf);
}

/**
 * find_path - Finds cmd in path string
 * @info: info struct
 * pathstr: The string of the path
 * cmd: cmd to find
 * Return: path of cmd if founf or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int j = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) >2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[j] || pathstr[j] == ':')
		{
			path = dup_chars(pathstr, curr_pos, j);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}
