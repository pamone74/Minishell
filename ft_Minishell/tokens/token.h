/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:41:42 by pamone            #+#    #+#             */
/*   Updated: 2024/02/22 05:12:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN
#define TOKEN

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "/workspaces/Minishell/libft/libft.h"
typedef enum  e_token_id{
    IDENTIFIER,
    INPUT,
    OUTPUT,
    HERE_DOC,
    APPEND_MODE,
    O_PARENT,
    C_PARENT, 
    AND,
    OR,
    NL,
    PIPE,
}   t_token_id;

typedef struct s_token t_token;
typedef char *Value;
struct s_token{
    t_token_id  type;
    Value       value;
    struct  s_token *next;
    struct  s_token *prev;    
};
t_token	*ft_new_token(char *str, t_token_id id_type);
void	ft_append_token(t_token **head, t_token *new_token);
void	ft_free_token(t_token **tokens);
int	ft_append_delimiter(t_token_id id, char **args_line, t_token **token_list);
// int	ft_strncmp(char *string, char *str2, size_t len);
int	ft_isspace(char c);
int ft_skip_spaces(char **line);

// strings.
char	*ft_strjoin_with(char const *s1, char const *s2, char c);
#endif
