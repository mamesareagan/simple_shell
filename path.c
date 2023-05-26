#include "simple_shell.h"

/**
 * find_command_path - finds the full path of a command
 * @command: the command to find
 * @env: character for environmental variables
 *
 * Return: the full path of command if found, NULL otherwise
 */

char *find_command_path(char *command, char **env)
{
	char *path = _getenv("PATH", env);
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	size_t dir_len;
	char *dir;
	char *command_path = NULL;

	while (path_token != NULL)
	{
		dir_len = strlen(path_token);
		dir = malloc(dir_len + strlen(command) + 2);
		strcpy(dir, path_token);
		_strcat(dir, "/");
		_strcat(dir, command);

		if (access(dir, X_OK) == 0)
		{
			command_path = strdup(dir);
			free(dir);
			break;
		}
		free(dir);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (command_path);
}
