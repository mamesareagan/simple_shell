#ifndef SHELLME_H
#define SHELLME_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>

/**
* struct choice_built - getting the commands in validation
* @naming_built: naming
* @fun_built: Pointer
*/

typedef struct choice_built
{
char *naming_built;
int (*fun_built)(char **, char *, int *);
} choice_t;

void signal_handler(int sigint);
char *get_en(char *envronment_variable);
char *input_validation(char **agu, char **arg);
char **_tonken(char *iinput);
void *_realloc(void *p, unsigned int p_s, unsigned int n_s);
int h_unsetenv(char **av, char *input, int *exiti);
int h_setenv(char **av, char *input, int *exiti);
int _en(char **av, char *input, int *exiti);
int _cd(char **av, char *input, int *exiti);
int _exe(char **a, char *input_s, char **args, int *exit_s);
int p_exit(char **av, char *input, int *exiti);
int _exe_p(char **agu, char **arg, int *exiti);
int space_validation(char *iinput);
char *append_str(char *str_one, char *str_two);

extern char **environ;

#endif
