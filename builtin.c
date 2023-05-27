#include "shell.h"


/**

 * outsh - exits the shell

 * @docs: Structure containing potential arguments. Used to maintain

 * constant function prototype.

 * Return: exits with a given exit status

 * (0) if info.argv[0] != "exit"

 */

int outsh(info_t *docs)

{

        int ext;


        if (docs->argv[1]) /* If there is an exit arguement */

        {

                ext = re_atoi(docs->argv[1]);

                if (ext == -1)

                {

                        docs->status = 2;

                        print_error(docs, "Illegal number: ");

                        _eputs(docs->argv[1]);

                        _eputchar('\n');

                        return (1);

                }

                docs->err_num = re_atoi(docs->argv[1]);

                return (-2);

        }

        docs->err_num = -1;

        return (-2);

}


/**

 * _cd - changes the current directory of the process

 * @docs: Structure containing potential arguments. Used to maintain

 * constant function prototype.

 * Return: Always 0

 */

int _cd(info_t *docs)

{

        char *s, *dir, buffer[1024];

        int chdir_ret;


        s = getcwd(buffer, 1024);

        if (!s)

                _puts("TODO: >>getcwd failure emsg here<<\n");

        if (!docs->argv[1])

        {

                dir = _getenv(docs, "HOME=");

                if (!dir)

                        chdir_ret = chdir((dir = _getenv(docs, "PWD=")) ? dir : "/");

                else

                        chdir_ret = chdir(dir);

        }

        else if (compare(docs->argv[1], "-") == 0)

        {

                if (!_getenv(docs, "OLDPWD="))

                {

                        _puts(s);

                        _putchar('\n');

                        return (1);

                }

                _puts(_getenv(docs, "OLDPWD=")), _putchar('\n');

                chdir_ret = chdir((dir = _getenv(docs, "OLDPWD=")) ? dir : "/");

        }

        else

                chdir_ret = chdir(docs->argv[1]);

        if (chdir_ret == -1)

        {

                print_error(docs, "can't cd to ");

                _eputs(docs->argv[1]), _eputchar('\n');

        }

        else

        {

                _mysetenv(docs, "OLDPWD", _getenv(docs, "PWD="));

                _mysetenv(docs, "PWD", getcwd(buffer, 1024));

        }

        return (0);

}
/**

 * _dirchange - changes the current directory of the process

 * @info: Structure containing potential arguments. Used to maintain

 * constant function prototype.

 * Return: Always 0

 */

int _dirchange(info_t *info)

{

        char **arg_array;


        arg_array = info->argv;

        _puts("help call works. Function not yet implemented \n");

        if (0)

                _puts(*arg_array); /* temp att_unused workaround */

        return (0);

}
