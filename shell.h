#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include <sys/wait.h>

#include <sys/stat.h>

#include <limits.h>

#include <fcntl.h>

#include <errno.h>


/* for read/write buffers */

#define READ_BUF_SIZE 1024

#define WRITE_BUF_SIZE 1024

#define BUF_FLUSH -1


/* for command chaining */

#define CMD_NORM        0

#define CMD_OR                1

#define CMD_AND                2

#define CMD_CHAIN        3


/* for convert_number() */

#define CONVERT_LOWERCASE        1

#define CONVERT_UNSIGNED        2


/* 1 if using system getline() */

#define USE_GETLINE 0

#define USE_STRTOK 0


#define HIST_FILE        ".simple_shell_history"

#define HIST_MAX        4096


extern char **environ;



/**

 * struct liststr - singly linked list

 * @num: the number field

 * @str: a string

 * @next: points to the next node

 */

typedef struct liststr

{

        int num;

        char *str;

        struct liststr *next;

} list_t;


/**

 * struct passinfo - contains pseudo-arguements to pass into a function,

 * allowing uniform prototype for function pointer struct

 * @arg: a string generated from getline containing arguements

 * @argv:an array of strings generated from arg

 * @path: a string path for the current command

 * @argc: the argument count

 * @line_count: the error count

 * @err_num: the error code for exit()s

 * @linecount_flag: if on count this line of input

 * @fname: the program filename

 * @env: linked list local copy of environ

 * @environ: custom modified copy of environ from LL env

 * @history: the history node

 * @alias: the alias node

 * @env_changed: on if environ was changed

 * @status: the return status of the last exec'd command

 * @cmd_buf: address of pointer to cmd_buf, on if chaining

 * @cmd_buf_type: CMD_type ||, &&, ;

 * @readfd: the fd from which to read line input

 * @histcount: the history line number count

 */

typedef struct passinfo

{

        char *arg;

        char **argv;

        char *path;

        int argc;

        unsigned int line_count;

        int err_num;

        int linecount_flag;

        char *fname;

        list_t *env;

        list_t *history;

        list_t *alias;

        char **environ;

        int env_changed;

        int status;


        char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */

        int cmd_buf_type; /* CMD_type ||, &&, ; */

        int readfd;

        int histcount;

} info_t;


#define INFO_INIT \
{ \
    NULL, \
    NULL, \
    NULL, \
    0, \
    0, \
    0, \
    0, \
    NULL, \
    NULL, \
    NULL, \
    NULL, \
    NULL, \
    0, \
    0, \
    NULL, \
    0, \
    0, \
    0 \
}


/**

 * struct builtin - contains a builtin string and related function

 * @type: the builtin command flag

 * @func: the function

 */

typedef struct builtin

{

        char *type;

        int (*func)(info_t *);

} builtin_table;



/* toem_shloop.c */

int shelloop(info_t *, char **);

int find_(info_t *);

void _cmd(info_t *);

void newcmd(info_t *);


/* toem_parser.c */

int is_cmd(info_t *, char *);

char *dup_chars(char *, int, int);

char *path_find(info_t *, char *, char *);


/* loophsh.c */

int loophsh(char **);


/* toem_errors.c */

void _eputs(char *);

int _eputchar(char);

int _putfdsc(char c, int fd);

int _putsfdsc(char *str, int fd);


/* toem_string.c */

int len(char *str);

int compare(char *str1, char *str2);

char *haystackstart(const char *hay, const char *needle);

char *_strcat(char *destiatio, char *source);


/* toem_string1.c */

char *_strcpy(char *, char *);

char *_strdup(const char *);

void _puts(char *);

int _putchar(char);


/* toem_exits.c */

char *copy(char *destiatio, char *source, int z);

char *cat(char *, char *, int);

char *locate(const char *str, char c);


/* toem_tokenizer.c */

char **splitwo(char *, char *);

char **splitwords(char *, char);


/* toem_realloc.c */

char *_setmem(char *, char, unsigned int);

void _free(char **str);

void *_alloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* toem_memory.c */

int _bfree(void **);


/* toem_atoi.c */

int mode(info_t *info);

int is_delim(char check, char *delim);

int _isalpha(int character);

int _atoi(char *str);


/* toem_errors1.c */

int re_atoi(char *);

void print_error(info_t *, char *);

int print_d(int, int);

char *convert_number(long int, int, int);

void remove_comments(char *);


/* toem_builtin.c */

int outsh(info_t *docs);
int _cd(info_t *docs);
int _dirchange(info_t *);
/* toem_builtin1.c */

int _history(info_t *);

int _alias(info_t *);


/*toem_getline.c */

ssize_t usrinput(info_t *docs);

int _getline(info_t *, char **, size_t *);

void handler(int);


/* toem_getinfo.c */

void clear_info(info_t *);

void set_info(info_t *, char **);

void info_free(info_t *, int);


/* toem_environ.c */

char *_getenv(info_t *info, const char *);

int currenv(info_t *);

int _newsetenv(info_t *);

int _newunsetenv(info_t *);

int fill_env_list(info_t *);


/* toem_getenv.c */

char **myget_environ(info_t *);

int _myunsetenv(info_t *, char *);

int _mysetenv(info_t *, char *, char *);


/* toem_history.c */

char *tellhistory(info_t *);

int apped_hist(info_t *info);

int histread(info_t *info);

int historybuild(info_t *info, char *buf, int linecount);

int renum_hist(info_t *info);


/* toem_lists.c */

list_t *headadd_node(list_t **, const char *, int);

list_t *endadd_node_end(list_t **, const char *, int);

size_t print_list_str(const list_t *);

int indexdelete_node(list_t **, unsigned int);

void free_list(list_t **);


/* toem_lists1.c */

size_t len_list(const list_t *);

char **list_to_strings(list_t *);

size_t print_list(const list_t *);

list_t *node_starts_with(list_t *, char *, char);

ssize_t get_node_index(list_t *, list_t *);


/* toem_vars.c */

int delimchain(info_t *, char *, size_t *);

void _chain(info_t *, char *, size_t *, size_t, size_t);

int aliasrep(info_t *);

int varsrep(info_t *);

int stringrep(char **, char *);


#endif
