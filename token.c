#include "simple_shell.h"

/**
 * process_command - function that tokenizes a string
 * @buffer: buffer command
 *
 * Return: argument of the function
 */

char **process_command(char *buffer)
{
	int t = 1;
	char *token;
	char **arg = malloc(5 * sizeof(char *));

	if (arg == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " ");
	arg[0] = token;

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			arg[t] = token;
			t++;
		}
	}
	arg[t] = NULL;
	return (arg);
}
