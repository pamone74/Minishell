#include "minishel.h"
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
int ft_parse_absolute(char *str)
{
    if(strncmp("/bin/", str, 5) == 0)
        return 1;
    return 0;
}
char *ft_strjoin(const char *str, char *new )
{
    int i = 0;
    int j  =0;
    char *result = malloc(sizeof(char)  * (ft_strlen((char *)str)  + ft_strlen(new)) + 1);
    if(!result)
        return (free(result), NULL);
    if(ft_parse_absolute(new))
        j = 5;
    while(str[i] != '\0')
    {
        result[i] =  str[i];
        i++;
    }
    while(new[j] != '\0')
    {
        result[i] = new[j];
        j++;
        i++;
    }
    result[i]  =  '\0';
    return (result);
}
void ft_execute_path(char **str)
{
    if(ft_strcmp(str[0], "a.out")== 0)
        execve("./a.out", str, NULL);
    else
    {
        execve(ft_strjoin("/bin/", str[0]), str, NULL);
        exit(EXIT_SUCCESS);
    }
}

int ft_white_spaces(char *str)
{
    while(*str)
    {
        if((*str >= 9 && *str <= 13) || *str == 32)
            str++;
        else
            return 0;
    }
    return 1;
}
int main(void)
{
    char *line;
    int pid;
    line = readline("minishell $ ");
    char **str;
    str = malloc(sizeof(char *) * strlen(line) + 1);
    while(1)
    {
            // if(!ft_white_spaces(line) && ft_strlen(str[0]) != 0)
            str = ft_split(line);
            pid = fork();
            if(pid == 0)
            {
                if(ft_check_external(str[0]))
                    ft_execute_path(str);
                else
                    exit(EXIT_FAILURE);
            }
            else
            {
                int status;
                wait(&status);
                if(ft_check_b(str[0]))
                    ft_built_in(str);
                line = readline("Minishell $ ");
            }
    }
    free(str);
    
}
