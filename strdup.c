#include "simple_shell.h"

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
