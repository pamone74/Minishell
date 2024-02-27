#ifndef MINISHELL
#define MINISHELL


# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"
#include "parser/parsing.h"
#include "tokens/token.h"

/* 
envrionment start
char *key; stores the key of the environment variable
char *value; stores the value of the environment variable
struct s_env *next; stores the next environment variable
*/
typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env	*next;
}	t_env;
/*
    int i; stores the index of the command
    int status; stores the status of the command
    int child; stores the child process id
*/

typedef struct s_wait
{
    int           i;
    int           status;
    int           child;
}   t_wait;

/*
    char *path; stores the path of the command
    char **args; stores the arguments of the command

*/
typedef struct s_exec
{
    char            *path;
    char            **args;
}   t_exec;
/*
    int content; stores the file descriptor
    struct s_fd *next; stores the next file descriptor  
*/
typedef struct s_fd
{
    int content;
    struct s_fd *next;
}  t_fd;

/*
    int fd[2]; stores the file descriptor for pipe (interprocess communication)
    where fd[0] is the read end and fd[1] is the write end. 
    struct s_fd *fd_close; stores the file descriptor to close
    struct s_fd *here_doc; stores the file descriptor for heredoc
*/
typedef struct s_context
{
    int fd[2];
    t_fd *fd_close;
    t_fd *here_doc;
}   t_context;

typedef enum s_error
{
    SUCESS,
    CMD_NOT_FOUND,
    NO_SUCH_FILE_FILE,
    NO_SUCH_FILE_PROGRAM,
    PERMISSION_DENIED_FILE,
    PERMISSION_DENIED_PROGRAM,
    AMBIGUOUS,
    CD_NO_SUCH_FILE,
    HOME_NOT_SET,
    TOO_MANY_ARGS,
    NUMERIC_REQUI,
}t_error;

/*
    t_list *lst; stores the list of the environment variables
    t_list *tmp; stores the list of the environment variables   
    char quotes; stores the quotes  
    int i; stores the index of the command
*/
typedef struct s_expand
{
    t_list *lst;
    t_list *tmp;
    char    quotes;
    int    i;
}t_expand;

/*
    t_token *tokens; stores the list of tokens
    t_env *env_list; stores the list of environment variables
    char *line; stores the command line
    int exit_status; stores the exit status of the command
    int index; stores the index of the command
    bool sigint; stores the signal interrupt
    t_token *curr_token; stores the current token
    t_node *ast; stores the abstract syntax tree
    t_exec exec; stores the execution of the command
    int in_pipe; stores the pipe
    int in_redirect; stores the redirect
    t_error error_code; stores the error code
    char *error_file; stores the error file
    int last_pid; stores the last process id
    t_parse_error parse_error; stores the parse error

*/
typedef struct s_minishell
{
    t_token         *tokens;
    t_env           *env_list;
    char            *line;
    int             exit_status;
    int             index;
    bool            sigint;
    t_token         *curr_token;
    t_node          *ast;
    t_exec          exec;
    int             in_pipe;
    int             in_redirect;
    t_error         error_code;
    char            *error_file;
    int             last_pid;
    t_parse_error   parse_error;
}   t_minishell;

/*
    extern t_minishell g_minishell; stores the global minishell
    the extern keyword means that the value is defined elsewhere

*/
extern t_minishell g_minishell;

// envrionment_list.c
void    ft_get_env_list(char **envp);
char	*ft_get_value(char *str);
char	*ft_get_key(char *str);
t_env	*ft_new_node_env(char *key, char *value);
void    ft_add_node(t_env *new_node);
#endif
