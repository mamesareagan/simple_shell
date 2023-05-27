#include "shell.h"


/**

 * input_buf - buffers chained commands

 * @info: parameter struct

 * @buf: address of buffer

 * @len: address of len var

 *

 * Return: bytes read

 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)

{

        ssize_t r = 0;

        size_t len_p = 0;


        if (!*len) /* if nothing left in the buffer, fill it */

        {

                /*bfree((void **)info->cmd_buf);*/

                free(*buf);

                *buf = NULL;

                signal(SIGINT, handler);

#if USE_GETLINE

                r = getline(buf, &len_p, stdin);

#else

                r = _getline(info, buf, &len_p);

#endif

                if (r > 0)

                {

                        if ((*buf)[r - 1] == '\n')

                        {

                                (*buf)[r - 1] = '\0'; /* remove trailing newline */

                                r--;

                        }

                        info->linecount_flag = 1;

                        remove_comments(*buf);

                        historybuild(info, *buf, info->histcount++);

                        /* if (_strchr(*buf, ';')) is this a command chain? */

                        {

                                *len = r;

                                info->cmd_buf = buf;

                        }

                }

        }

        return (r);

}


/**

 * usrinput - gets a line minus the newline

 * @info: parameter struct

 *

 * Return: bytes read

 */

ssize_t usrinput(info_t *docs)

{

        static char *buf; /* the ';' command chain buffer */

        static size_t i, j, l;

        ssize_t r = 0;

        char **buf_p = &(docs->arg), *p;


        _putchar(BUF_FLUSH);

        r = input_buf(docs, &buf, &l);

        if (r == -1) /* EOF */

                return (-1);

        if (l) /* we have commands left in the chain buffer */

        {

                j = i; /* init new iterator to current buf position */

                p = buf + i; /* get pointer for return */


                _chain(docs, buf, &j, i, l);

                while (j < l) /* iterate to semicolon or end */

                {

                        if (delimchain(docs, buf, &j))

                                break;

                        j++;

                }


                i = j + 1; /* increment past nulled ';'' */

                if (i >= l) /* reached end of buffer? */

                {

                        i = l = 0; /* reset position and length */

                        docs->cmd_buf_type = CMD_NORM;

                }


                *buf_p = p; /* pass back pointer to current command position */

                return (len(p)); /* return length of current command */

        }


        *buf_p = buf; /* else not a chain, pass back buffer from _getline() */

        return (r); /* return length of buffer from _getline() */

}


/**

 * read_buf - reads a buffer

 * @info: parameter struct

 * @buf: buffer

 * @i: size

 *

 * Return: r

 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)

{

        ssize_t r = 0;


        if (*i)

                return (0);

        r = read(info->readfd, buf, READ_BUF_SIZE);

        if (r >= 0)

                *i = r;

        return (r);

}


/**

 * _getline - gets the next line of input from STDIN

 * @info: parameter struct

 * @ptr: address of pointer to buffer, preallocated or NULL

 * @length: size of preallocated ptr buffer if not NULL

 *

 * Return: s

 */

int _getline(info_t *info, char **ptr, size_t *th)

{

        static char buf[READ_BUF_SIZE];

        static size_t j, len;

        size_t k;

        ssize_t r = 0, s = 0;

        char *p = NULL, *new_p = NULL, *c;


        p = *ptr;

        if (p && th)

                s = *th;

        if (j == len)

                j = len = 0;


        r = read_buf(info, buf, &len);

        if (r == -1 || (r == 0 && len == 0))

                return (-1);


        c = locate(buf + j, '\n');

        k = c ? 1 + (unsigned int)(c - buf) : len;

        new_p = _alloc(p, s, s ? s + k : k + 1);

        if (!new_p) /* MALLOC FAILURE! */

                return (p ? free(p), -1 : -1);


        if (s)

                cat(new_p, buf + j, k - j);

        else

                copy(new_p, buf + j, k - j + 1);


        s += k - j;

        j = k;

        p = new_p;


        if (th)

                *th = s;

        *ptr = p;

        return (s);

}


/**

 * handler - blocks ctrl-C

 * 
 * Return: void

 */

void handler(__attribute__((unused))int a)

{

        _puts("\n");

        _puts("$ ");

        _putchar(BUF_FLUSH);

}
