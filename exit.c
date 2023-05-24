#include "simple_shell.h"

/**
 * ext - function that exits a program
 * @str: strings to be checked
 *
 * Return: void
 */

void ext(const char *str)
{
	char *str = strdup(str);

	if (str == NULL)
		exit(1);
	if (strcmp(srt, "exit") == 0)
	{
		free(srt);
		_exit(0);
	}
}
