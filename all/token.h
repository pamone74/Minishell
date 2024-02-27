#ifndef TOKENS
#define TOKENS

#include <stdio.h>
#include <stdlib.h>
typedef enum e_type{
    INPUT, // <
    OUTPUT, // >
    DOUBLE_QUOTE, // ""
    SINGLE_QUOTE, // ''
    PIPE, // |
    HERE_DOC, // <<
    APPEND_MODE, // >> 
    AND,
    OR, 
}t_type;

typedef char *value;
typedef struct s_token
{
    value data;
    t_type type;
    struct s_token *next;
    struct s_token *prev;
}t_token;

t_token *ft_create_token(char *str, int type);
void	ft_append_token(t_token **head, t_token *new_token);

#endif