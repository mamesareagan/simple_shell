#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
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
 * dup_chars - duplicates characters
 * @pathsrt: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathsrt, int start, int stop)
{
	static char buf[1024];
	int j = 0, l = 0;

	for (l = 0, j = start; j < stop; j++)
		if (pathsrt[j] != ':')
			buf[l++] = pathsrt[j];
	buf[l] = 0;
	return (buf);
}

/**
 * path_find - finds cmd in the PATH string
 * @info: info struct
 * @pathsrt: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *path_find(info_t *info, char *pathsrt, char *cmd)
{
	int j = 0, curr_pos = 0;
	char *path;

	if (!pathsrt)
		return (NULL);
	if ((len(cmd) > 2) && haystackstart(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathsrt[j] || pathsrt[j] == ':')
		{
			path = dup_chars(pathsrt, curr_pos, j);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathsrt[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}

