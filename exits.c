#include "shell.h"


/**

 **copy - copies a string

 *@destiatio: the destination string to be copied to

 *@source: the source string

 *@z: the amount of characters to be copied

 *Return: the concatenated string

 */

char *copy(char *destiatio, char *source, int z)


{

        int i, p;

        char *str = destiatio;


        i = 0;

        while (source[i] != '\0' && i < z - 1)

        {

                destiatio[i] = source[i];

                i++;

        }

        if (i < z)

        {

                p = i;

                while (p < z)

                {

                        destiatio[p] = '\0';

                        p++;

                }

        }

        return (str);

}


/**

 *cat - concatenates two strings

 *@dest: the first string

 *@src: the second string

 *@n: the amount of bytes to be maximally used

 *Return: the concatenated string

 */

char *cat(char *dest, char *src, int n)

{

        int i, j;

        char *s = dest;


        i = 0;

        j = 0;

        while (dest[i] != '\0')

                i++;

        while (src[j] != '\0' && j < n)

        {

                dest[i] = src[j];

                i++;

                j++;

        }

        if (j < n)

                dest[i] = '\0';

        return (s);

}


/**

 *locate - locates a character in a string

 *@str: the string to be parsed

 *@c: the character to look for

 *Return: (str) a pointer to the memory area str

 */

char *locate(const char *str, char c)

{
	while (*str++ != '\0')
	{
		if (*str == c)
		{
			return (char *)str;
		}
		str++;
	}
        return (NULL);

}
