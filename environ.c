#include "shell.h"

/**
 * currenv - prints the current environment
 * @docs: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int currenv(info_t *docs)
{
        print_list_str(docs->env);
        return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
        list_t *node = info->env;
        char *p;

        while (node)
        {
                p = haystackstart(node->str, name);
                if (p && *p)
                        return (p);
                node = node->next;
        }
        return (NULL);
}

/**
 * _newsetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _newsetenv(info_t *info)
{
        if (info->argc != 3)
        {
                _eputs("Incorrect number of arguements\n");
                return (1);
        }
        if (_mysetenv(info, info->argv[1], info->argv[2]))
                return (0);
        return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _newunsetenv(info_t *info)
{
        int i;

        if (info->argc == 1)
        {
                _eputs("Too few arguements.\n");
                return (1);
        }
        for (i = 1; i <= info->argc; i++)
                _myunsetenv(info, info->argv[i]);

        return (0);
}

/**
 * fill_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int fill_env_list(info_t *info)
{
        list_t *node = NULL;
        size_t i;

        for (i = 0; environ[i]; i++)
                endadd_node_end(&node, environ[i], 0);
        info->env = node;
        return (0);
}
