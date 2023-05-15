#include "simple_shell.h"

/**
 * main - prompts user for command and executes it
 *
 * Return:Always (0)
 */
int main(void)
{
	pid_t fk;
	char *arg[] = {"argv[0]", NULL};
	char *buffer = NULL;
	ssize_t a;
	ssize_t b;
	int c;

	while (1)
	{
		prompt();
		a = getline(&buffer, &b, stdin);
		if (a == -1)
		{
			perror("type a command");
		}
		else if (a > 0 && buffer[a - 1] == '\n')
			buffer[a - 1] = '\0';

		c = fork();
		if (c < 0)
			perror("unsucessful");
		else if (c == 0)
		{
			if (execve(buffer, arg, NULL) == -1)
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
