#include "simple_shell.h"

/**
 * ext - function that exits a program
 * @str: strings to be checked
 *
 * Return: void
 */

void ext(const char *str)
{
	char *srt = strdup(str);

	if (srt == NULL)
		exit(1);
	if (strcmp(srt, "exit") == 0)
	{
		free(srt);
		_exit(0);
	}
}
