#include "shell.h"


/**

 * _strlen - returns the length of a string

 * @s: the string whose length to check

 *

 * Return: integer length of string

 */

int len(char *str)

{

        int i = 0;


        if (!str)

                return (0);


        while (*str++)

                i++;

        return (i);

}


/**

 * _strcmp - performs lexicogarphic comparison of two strangs.

 * @s1: the first strang

 * @s2: the second strang

 *

 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2

 */

int compare(char *str1, char *str2)

{

        while (*str1 && *str2)

        {

                if (*str1 != *str2)
		{
                        return (*str1 - *str2);
		}
                str1++;
                str2++;
        }

        if (*str1 == *str2)
	{
                return (0);
	}
        else
                return (*str1 < *str2 ? -1 : 1);

}


/**

 * starts_with - checks if needle starts with haystack

 * @hay: string to search

 * @needle: the substring to find

 *

 * Return: address of next char of haystack or NULL

 */

char *haystackstart(const char *hay, const char *needle)

{

        while (*needle)

                if (*needle++ != *hay++)

                        return (NULL);

        return ((char *)hay);

}


/**

 * _strcat - concatenates two strings

 * @destiatio: the destination buffer

 * @source: the source buffer

 *

 * Return: pointer to destination buffer

 */

char *_strcat(char *destiatio, char *source)

{

        char *ret = destiatio;


        while (*destiatio)

                destiatio++;

        while (*source)

                *destiatio++ = *source++;

        *destiatio = *source;

        return (ret);

}
