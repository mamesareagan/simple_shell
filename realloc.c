#include "shell.h"


/**

 * _setmem - fills memory with a constant byte

 * @str: the pointer to the memory area

 * @b: the byte to fill *s with

 * @n: the amount of bytes to be filled

 * Return: (str) a pointer to the memory area str

 */

char *_setmem(char *str, char b, unsigned int n)

{

        unsigned int i;


        for (i = 0; i < n; i++)
	{
                str[i] = b;
	}
        return (str);

}


/**

 * _free - frees a string of strings

 * @str: string of strings

 */

void _free(char **str)

{

        char **a = str;


        if (!str)

                return;

        while (*str)

                free(*str++);

        free(a);

}


/**

 * _alloc - reallocates a block of memory

 * @ptr: pointer to previous malloc'ated block

 * @old_size: byte size of previous block

 * @new_size: byte size of new block

 *

 * Return: pointer to da ol'block nameen.

 */

void *_alloc(void *ptr, unsigned int old_size, unsigned int new_size)

{

        char *p;


        if (!ptr)

                return (malloc(new_size));

        if (!new_size)

                return (free(ptr), NULL);

        if (new_size == old_size)

                return (ptr);


        p = malloc(new_size);

        if (!p)

                return (NULL);


        old_size = old_size < new_size ? old_size : new_size;

        while (old_size--)

                p[old_size] = ((char *)ptr)[old_size];

        free(ptr);

        return (p);

}
