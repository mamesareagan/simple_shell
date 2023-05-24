#include "simple_shell.h"

int strle(const char *a);
/**
 * _getenv - finds a specified environmental variable
 * @name:specified variable
 *
 * Return:key of the variable else NULL
 */
extern char **environ;
char *_getenv(const char *name)
{
	char **a = environ;
	size_t b = strle(name);

	while (*a != NULL)
	{
		if (strncmp(*a, name, b) == 0)
		{
			return &((*a)[b + 1]);
		}
		a++;
	}
	return (NULL);
}
