#include "simple_shell.h"

/**
 * _strdup - returns copy of a string
 * @str:string to returned
 *
 * Return:copy of str
 */
char *_strdup(char *str)
{
	char *srt = malloc((strle(str) + 1) * sizeof(char));

	if (srt == NULL)
	{
		perror("Malloc failed");
		return (NULL);
	}
	_strcpy(srt, str);
	return (srt);
}
