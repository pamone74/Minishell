#include "token.h"

/*
    This function creates a token and returns it
    it takes two pararmeters a string and a type

*/
t_token *ft_create_token(char *str, int type)
{
    t_token *token;
    token = malloc(sizeof(t_token));
    token->data = str;
    token->type = type;
    return (token);
}
void	ft_append_token(t_token **head, t_token *new_toekn)
{
	t_token	*last;

	if (*head == NULL)
	{
		*head = new_toekn;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new_toekn;
}

/*
This function takes a string and a type and creates a token, then appends it to the token list
Suppose you have the command line: "ls -l | grep 'important' > output.txt"
The command line would initially be tokenized into individual tokens: ["ls", "-l", "|", "grep", "'important'", ">", "output.txt"]
As you iterate over the tokens, you would encounter the pipe symbol "|", indicating a pipe between commands.
When encountering the pipe symbol "|", you would call ft_append_delimiter with the PIPE identifier. This would append a delimiter token representing the pipe to your token list.
The same would be done for the other delimiters: INPUT, OUTPUT, OR, AND

*/
int ft_append_delimiter(t_type id, char **args_line, t_token **token_list)
{
	t_token *token;
	token = ft_create_token(NULL, id);
	if (!token)
		return (0);
	ft_append_token(token_list, token);
	(*args_line)++;
	if (id == INPUT || id == OUTPUT || id == OR || id == AND)
		(*args_line)++;
	return (1);
}