#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void prompt(void);
int strle(const char *a);
char *_getenv(const char *name, char **env);
char *find_command_path(const char *command, char **env);
void ext(const char *str);
void envir(const char *str,  char **env);
char** process_command(char *buffer);
#endif
