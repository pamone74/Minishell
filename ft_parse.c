#include "minishel.h"
#include <stdio.h>

// int ft_strlen(char *str)
// {
//     int i = 0;
//     while (*str) {
//         i++;
//         str++;
//     }
//     return (i);
// }

int ft_check_quote(char **string, t_char *hold)
{
    t_char *characters;
    characters = malloc(sizeof(t_char));
    characters->double_quote = 0;
    int len = 0;
    while(string[len] != NULL)
    {
        int j = 0;
        while(string[len][j] != '\0')
        {
            if(string[len][j] == '"')
            {
                characters->double_quote++;
                if(string[len][j + 1] == '<' || string[len][j+1] == '|' || string[len][j+1] == '&' || string[len][j+1] == '>')
                return 1;
            }
            j++;
        }
        hold->double_quote = characters->double_quote;
        len++;
    }
    return 0;
}