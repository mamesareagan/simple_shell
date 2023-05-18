#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void prompt(void);
int strle(const char *a);
char *_getenv(const char *name);
#endif
