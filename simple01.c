#include "simple_shell.h"

/**
 * main - prompts user for command and executes it
 *
 * Return:Always (0)
 */
extern char **environ;
int main()
{
	pid_t fk __attribute__((unused));
	char *arg[5];
	char *buffer = NULL, *path, *dir, *path_copy, *path_token;
	ssize_t a;
	char **env = environ;
	size_t b;
	int c;
	char *token, *command ;
	int t = 1, command_exists;
	size_t dir_len;

	while (1)
	{
		prompt();
		a = getline(&buffer, &b, stdin);
		if (*buffer == '\n')
		{
			continue;
		}
		else if (strncmp(buffer, "exit", 4) == 0)
			_exit(0);
		else if ( strncmp(buffer, "env", 3) == 0)
		{
			unsigned int i = 0;

			while (env[i] != NULL)
			{
				printf("%s\n", env[i]);
				i++;
			}
		}
		if (a == -1)
		{
			perror("type a command");
		}
		else if (a > 0 && buffer[a - 1] == '\n')
			buffer[a - 1] = '\0';

		token = strtok(buffer, " ");
		command = token;
		arg[0] = token;
		while(token != NULL)
		{
			token = strtok(NULL, " ");
			if(token != NULL)
			{
				while(t < 5)
				{
					arg[t] = token;
					t++;
				}
			}
		}
		arg[t] = NULL;
		path = _getenv("PATH");
		path_copy = strdup(path);
		path_token = strtok(path_copy, ":");
		command_exists = 0;

		while (path_token != NULL) {
			dir_len = strle(path_token);
			dir = malloc(dir_len + strle(command) + 2);
			strcpy(dir, path_token);
			strcat(dir, "/");
			strcat(dir, command);

			if (access(dir, X_OK) == 0) {
				command_exists = 1;
				break;
			}

			free(dir);
			path_token = strtok(NULL, ":");
		}

		free(path_copy);

		if (!command_exists) {
			perror("Command not found");
			continue;
		}
		c = fork();
		if (c < 0)
			perror("unsucessful");
		else if (c == 0)
		{
			if (execve(dir, arg, NULL) == -1)
			{
				perror("No such file or directory");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fk = wait(&c);
		}
	}
	free(buffer);
	return (0);
}
