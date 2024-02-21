#ifndef PARSING
#define PARSING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "/workspaces/Minishell/ft_Minishell/tokens/token.h"

typedef enum e_type
{
    NODE_PIPE,
    NODE_AND,
    NODE_CMD,
    NODE_OR,
}   t_type;

typedef enum e_io_type
{
    IO_IN,
    IO_OUT,
    IO_APPEND,
    IO_HERE_DOC,
}   t_io_type;

typedef enum e_err_type
{
    SYNTAX,
    MEM = 1,
}   t_err_type;

typedef struct s_io
{
    t_io_type   type;
    char        *value;
    struct s_io *next;
    struct s_io *prev;
}   t_io;

typedef struct s_node
{
    t_type      type;
    t_io        *io_list;
    char        *args;
    t_io        *io;
    struct s_node *left;
    struct s_node *right;
}   t_node;

typedef struct s_parse_error
{
    t_err_type  type;
    char        *msg;
}   t_parse_error;
//extern t_minishell g_minishell;
// the files needs to be included in the main file
#endif
