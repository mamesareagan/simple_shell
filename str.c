#include <stddef.h>
/**
 * strle - length of string
 * @a:string
 *
 * Return:length of string
 */
int strle(const char *a)
{
	int c;

	if (a == NULL)
	{
		return (-1);
	}
	for (c = 0; a[c] != '\0'; c++)
	{
	}
	return (c);
}
