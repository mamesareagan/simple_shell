#include "shell.h"


/**

 * hsh - main shell loop

 * @info: the parameter & return info struct

 * @av: the argument vector from main()

 *

 * Return: 0 on success, 1 on error, or error code

 */

int shelloop(info_t *info, char **av)

{
	 int built= 0;
	 ssize_t read = 0;

        while (read != -1 && built != -2)
        {
                clear_info(info);
                if (mode(info))
                        _puts("$ ");
                _eputchar(BUF_FLUSH);
                read = usrinput(info);

                if (read != -1)

                {

                        set_info(info, av);

                        built = find_(info);

                        if (built == -1)

                                _cmd(info);

                }

                else if (mode(info))

                        _putchar('\n');

                info_free(info, 0);

        }

        apped_hist(info);

        info_free(info, 1);

        if (!mode(info) && info->status)

                exit(info->status);

        if (built == -2)

        {

                if (info->err_num == -1)

                        exit(info->status);

                exit(info->err_num);

        }

        return (built);

}


/**
 *

 * find_builtin - finds a builtin command

 * @info: the parameter & return info struct

 *

 * Return: -1 if builtin not found,

 *         0 if builtin executed successfully,

 *         1 if builtin found but not successful,

 *         2 if builtin signals exit()

 */

int find_(info_t *info)

{

        int cout, in= -1;

        builtin_table builtintbl[] = {

                {"exit", outsh},

                {"env", currenv},

                {"help", _dirchange},

                {"history", _history},

                {"setenv", _newsetenv},

                {"unsetenv", _newunsetenv},

                {"cd", _cd},

                {"alias", _alias},

                {NULL, NULL}

        };


        for (cout = 0; builtintbl[cout].type; cout++)

                if (compare(info->argv[0], builtintbl[cout].type) == 0)

                {

                        info->line_count++;

                        in= builtintbl[cout].func(info);

                        break;

                }

        return (in);

}


/**

 * find_cmd - finds a command in PATH

 * @info: the parameter & return info struct

 *

 * Return: void

 */

void _cmd(info_t *info)

{

        char *path = NULL;

        int j, l;


        info->path = info->argv[0];

        if (info->linecount_flag == 1)

        {

                info->line_count++;

                info->linecount_flag = 0;

        }

        for (j = 0, l = 0; info->arg[j]; j++)

                if (!is_delim(info->arg[j], " \t\n"))

                        l++;

        if (!l)

                return;


        path = path_find(info, _getenv(info, "PATH="), info->argv[0]);

        if (path)

        {

                info->path = path;

                newcmd(info);

        }

        else

        {

                if ((mode(info) || _getenv(info, "PATH=")

                                        || info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))

                        newcmd(info);

                else if (*(info->arg) != '\n')

                {

                        info->status = 127;

                        print_error(info, "not found\n");

                }

        }

}


/**

 * fork_cmd - forks a an exec thread to run cmd

 * @info: the parameter & return info struct

 *

 * Return: void

 */

void newcmd(info_t *info)

{

        pid_t child_pid;


        child_pid = fork();

        if (child_pid == -1)

        {

                /* TODO: PUT ERROR FUNCTION */

                perror("Error:");

                return;

        }

        if (child_pid == 0)

        {

                if (execve(info->path, info->argv, myget_environ(info)) == -1)

                {

                        info_free(info, 1);

                        if (errno == EACCES)

                                exit(126);

                        exit(1);

                }

        }

        else

        {

                wait(&(info->status));

                if (WIFEXITED(info->status))

                {

                        info->status = WEXITSTATUS(info->status);

                        if (info->status == 126)

                                print_error(info, "Permission denied\n");

                }

        }

}
