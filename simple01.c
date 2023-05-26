#include "simple_shell.h"
/**
 * main - prompts user for command and executes it
 * @ac:numer of arguments
 * @av:array of arguments
 * @env:array of environ variables
 * Return:Always (0)
 */
int main(__attribute__((unused))int ac, char **av, char **env)
{
	pid_t c;
	char **arg, *buffer = NULL, *path;
	ssize_t a;
	size_t b;

	__attribute__((unused))char **h = av;

	while (1)
	{
		prompt();
		a = getline(&buffer, &b, stdin);
		if (*buffer == '\n')
			continue;
		if (a == -1)
			break;
		else if (a > 0 && buffer[a - 1] == '\n')
			buffer[(int)a - 1] = '\0';
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
		{
			execve(path, arg, NULL);
			free(path);
		}
		else
			wait(&c);
	}
	free(buffer);
	return (0);
}
