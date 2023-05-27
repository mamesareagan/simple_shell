#include "shell.h"


/**

 * myget_environ - returns the string array copy of our environ

 * @docs: Structure containing potential arguments. Used to maintain

 *          constant function prototype.

 * Return: Always 0

 */

char **myget_environ(info_t *docs)

{

        if (!docs->environ || docs->env_changed)

        {

                docs->environ = list_to_strings(docs->env);

                docs->env_changed = 0;

        }


        return (docs->environ);

}


/**

 * _myunsetenv - Remove an environment variable

 * @info: Structure containing potential arguments. Used to maintain

 *        constant function prototype.

 *  Return: 1 on delete, 0 otherwise

 * @var: the string env var property

 */

int _myunsetenv(info_t *info, char *var)

{

        list_t *node = info->env;

        size_t i = 0;

        char *p;


        if (!node || !var)

                return (0);


        while (node)

        {

                p = haystackstart(node->str, var);

                if (p && *p == '=')

                {

                        info->env_changed = indexdelete_node(&(info->env), i);

                        i = 0;

                        node = info->env;

                        continue;

                }

                node = node->next;

                i++;

        }

        return (info->env_changed);

}


/**

 * _mysetenv - Initialize a new environment variable,

 *             or modify an existing one

 * @info: Structure containing potential arguments. Used to maintain

 *        constant function prototype.

 * @var: the string env var property

 * @value: the string env var value

 *  Return: Always 0

 */

int _mysetenv(info_t *info, char *var, char *value)

{

        char *buf = NULL;

        list_t *node;

        char *p;


        if (!var || !value)

                return (0);


        buf = malloc(len(var) + len(value) + 2);

        if (!buf)

                return (1);

        _strcpy(buf, var);

        _strcat(buf, "=");

        _strcat(buf, value);

        node = info->env;

        while (node)

        {

                p = haystackstart(node->str, var);

                if (p && *p == '=')

                {

                        free(node->str);

                        node->str = buf;

                        info->env_changed = 1;

                        return (0);

                }

                node = node->next;

        }

        endadd_node_end(&(info->env), buf, 0);

        free(buf);

        info->env_changed = 1;

        return (0);

}
