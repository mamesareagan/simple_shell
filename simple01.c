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
	char **arg, buff[BUFFER_SIZE], *buffer = NULL, *path;
	ssize_t b;

	__attribute__((unused))char **h = av;

	while (1)
	{
		prompt();
		b = read_command(buff, BUFFER_SIZE);
		if (b == 0)
			continue;
		ext(buff);
		envir(buff, env);
		arg = process_command(buff);
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
