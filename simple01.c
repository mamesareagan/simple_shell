#include "simple_shell.h"

/**
 * main - prompts user for command and executes it
 *
 * Return:Always (0)
 */
int main(void)
{
	pid_t fk __attribute__((unused));
	char *arg[3];/* = {"argv[0]", NULL};*/
	char *buffer = NULL;
	ssize_t a;
	size_t b;
	int c;
	char *token, *command;
	int t = 0;

	while (1)
	{
		prompt();
		a = getline(&buffer, &b, stdin);
		if (*buffer == '\n')
		{
			continue;
		}
		if (a == -1)
		{
			perror("type a command");
		}
		else if (a > 0 && buffer[a - 1] == '\n')
			buffer[a - 1] = '\0';

		token = strtok(buffer, " ");
		command = token;
		while(token != NULL)
		{
			token = strtok(NULL, " ");
			if(token != NULL)
			{
				while(t < 3)
				{
					arg[t] = token;
					t++;
				}
			}
		}
		arg[t] = NULL;
		c = fork();
		if (c < 0)
			perror("unsucessful");
		else if (c == 0)
		{
			if (execve(command, arg, NULL) == -1)
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
