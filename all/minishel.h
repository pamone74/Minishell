#ifndef MINISHEL_H
#define MINISHEL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef enum e_type{
    INPUT, // <
    OUTPUT, // >
    DOUBLE_QUOTE, // ""
    SINGLE_QUOTE, // ''
    PIPE, // |
    HERE_DOC, // <<
    APPEND_MODE, // >>  
}t_type;
typedef struct s_char
{
    int double_quote; // ""
    int redirect; //<<
    int inp; // <
    int outp; // >
    int single_quote; // ' '
} t_char;

typedef struct s_cmd
{
    int data;
    t_char *flag;
    struct s_cmd * next;
} t_cmd;

typedef struct test{
    int arr;
    struct test *next;
    char *comm[];
} t_test;

t_test  *add_node(void);
int ft_check_external(char *str);
int ft_strcmp(const char *s1, const char *s2);
char **ft_split(char *str);
void    ft_ls(char **str);
void    ft_cp(char **str);
void    ft_mv(char **str);
void    ft_rm(char **str);
void    ft_mkdir(char **str);
void    ft_rmdir(char **str);
void    ft_cat(char **str);
void    ft_find(char **str);
void    ft_grep(char **str);
char *ft_strjoin(const char *str, char *new_str );
void    ft_built_in(char **str);
int ft_check_b(char *str);
void    ft_cd(char **str);
void    ft_pwd(void);


// new function 
int ft_check_quote(char **string, t_char *hold);
#endif
