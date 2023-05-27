#include "shell.h"


/**

 **splitwo - splits a string into words. Repeat delimiters are ignored

 * @str: the input string

 * @delim: the delimeter string

 * Return: a pointer to an array of strings, or NULL on failure

 */


char **splitwo(char *str, char *delim)

{

        int dev, j, k, m, numwords = 0;

        char **s;


        if (str == NULL || str[0] == 0)

                return (NULL);

        if (!delim)

                delim = " ";

        for (dev = 0; str[dev] != '\0'; dev++)

                if (!is_delim(str[dev], delim) && (is_delim(str[dev + 1], delim) || !str[dev + 1]))

                        numwords++;


        if (numwords == 0)

                return (NULL);

        s = malloc((1 + numwords) * sizeof(char *));

        if (!s)

                return (NULL);

        for (dev = 0, j = 0; j < numwords; j++)

        {

                while (is_delim(str[dev], delim))

                        dev++;

                k = 0;

                while (!is_delim(str[dev + k], delim) && str[dev + k])

                        k++;

                s[j] = malloc((k + 1) * sizeof(char));

                if (!s[j])

                {

                        for (k = 0; k < j; k++)

                                free(s[k]);

                        free(s);

                        return (NULL);

                }

                for (m = 0; m < k; m++)

                        s[j][m] = str[dev++];

                s[j][m] = 0;

        }

        s[j] = NULL;

        return (s);

}


/**

 * splitwords - splits a string into words

 * @str: the input string

 * @d: the delimeter

 * Return: a pointer to an array of strings, or NULL on failure

 */

char **splitwords(char *str, char d)

{

        int dev, j, k, m, numwords = 0;

        char **s;


        if (str == NULL || str[0] == 0)

                return (NULL);

        for (dev = 0; str[dev] != '\0'; dev++)

                if ((str[dev] != d && str[dev + 1] == d) ||

                                    (str[dev] != d && !str[dev + 1]) || str[dev + 1] == d)

                        numwords++;

        if (numwords == 0)

                return (NULL);

        s = malloc((1 + numwords) * sizeof(char *));

        if (!s)

                return (NULL);

        for (dev = 0, j = 0; j < numwords; j++)

        {

                while (str[dev] == d && str[dev] != d)

                        dev++;

                k = 0;

                while (str[dev + k] != d && str[dev + k] && str[dev + k] != d)

                        k++;

                s[j] = malloc((k + 1) * sizeof(char));

                if (!s[j])

                {

                        for (k = 0; k < j; k++)

                                free(s[k]);

                        free(s);

                        return (NULL);

                }

                for (m = 0; m < k; m++)

                        s[j][m] = str[dev++];

                s[j][m] = 0;

        }

        s[j] = NULL;

        return (s);

}
