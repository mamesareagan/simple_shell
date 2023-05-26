#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

void prompt(void);
int strle(const char *a);
char *_getenv(const char *name, char **env);
char *find_command_path(char *command, char **env);
void ext(const char *str);
void envir(const char *str,  char **env);
char **process_command(char *buffer);
char *_strdup(char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *source);
ssize_t read_command(char *buffer, size_t size);

#endif
