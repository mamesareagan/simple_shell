#include "simple_shell.h"
/**
 * main - prompts user for command and executes it
 * @ac:numer of arguments
 * @av:array of arguments
 * @env:array of environ variables
 * Return:Always (0)
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **env)
{
	pid_t c, __attribute__((unused))fk;
	char **arg, *buffer = NULL, *path;
	ssize_t a;
	size_t b;

	while (1)
	{
		prompt();
		a = getline(&buffer, &b, stdin);
		if (*buffer == '\n')
			continue;
		if (a == -1)
		{
			perror("type a command");
		}
		else if (a > 0 && buffer[a - 1] == '\n')
			buffer[a - 1] = '\0';

		ext(buffer);
		envir(buffer, env);
		arg = process_command(buffer);
		path =  find_command_path(arg[0], env);
		if (path == NULL)
		{
			perror("Command not found");
			continue;
		}
		c = fork();
		if (c < 0)
			perror("unsucessful");
		else if (c == 0)
			execve(path, arg, NULL);
		else
			fk = wait(&c);
	}
	free(path);
	free(buffer);
	return (0);
}
