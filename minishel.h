#ifndef MINISHEL_H
#define MINISHEL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struc s_cmd{
    char *cmd;
    char **args;
    int argc;
} t_cmd;
#endif
