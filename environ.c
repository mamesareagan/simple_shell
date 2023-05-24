#include "simple_shell.h"

/**
 * envir - prints environ variables
 * @str:command to determine if function prints out
 * @env:env argument of main
 *
 * Return:nothing
 **/
void envir(const char *str, char **env)
{
	char *srt = strdup(str);
	char **ev = env;
	unsigned int i = 0;

	/*compares str to env*/
	if (strcmp(srt, "env") == 0)
	{
		free(srt);
		/*iterate through environ variables*/
		while (ev[i] != NULL)
		{
			printf("%s\n", ev[i]);
			i++;
		}
	}
}
