#include "simple_shell.h"

/**
 * prompt - function that prompts the user
 *
 * Return: void
 */

void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
