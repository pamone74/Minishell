#include "minishell.h"

int ft_count_word(char *str)
{
    int i = 0;
    int flag = 0;
    while(*str != '\0')
    {
        if(*str == ' ')
            flag = 0;
        else if(flag == 0)
        {
            flag = 1;
            i++;
        }
        str++;
    }
    return (i);
}
int ft_strlen(char *str)
{
    int i = 0;
    int flag = 0;
    while(*str != '\0')
    {
        if(*str == ' ')
            flag = 1;
        else if(!flag)
            i++;
        str++;
    }
    return (i);
}
char *ft_subsr(const char *str, int start, int end)
{
    char *sub;
    int i = 0;
    sub = (char *)malloc(sizeof(char) * (end - start + 1));
    while(start < end)
    {
        sub[i] = str[start];
        i++;
        start++;
    }
    sub[i] = '\0';
    return (sub);
}
char **ft_split(char *str)
{
    int word = ft_count_word(str);
    char **strr = malloc(sizeof(char *) * (word + 1));
    int i = 0;
    while (i < word)
    {
        while(*str == ' ')
            str++;
        strr[i] = ft_subsr(str, 0, ft_strlen(str));
        if(!strr[i])
            return (free(strr[i]),NULL);
        i++;
        str += ft_strlen(str);
    }
    strr[i] = NULL;
    return (strr);
}
int main(void)
{
    char *str = "Hello World 8";
    printf("The number of words or substring is %s\n", *(ft_split(str) + 2));
    // char *line;
    // line = readline("minishell $ ");
    // while(1)
    // {
    //     if(strcmp(line, "exit") == 0)
    //         break;
    //     if(strcmp(line, "cd") == 0)
    //         chdir(line);
    //     if(strcmp(line, "") == 0)
    //         line = readline("minishell $ ");
    //     if(strcmp(line, "ls") == 0)
    //     {
    //         char *ls[] = {"/bin/ls", "-l", NULL};
    //         execve(ls[0], ls, NULL);
    //         continue;
    //     }
    //     if(strcmp(line, "pwd") == 0)
    //     {
    //         char buff[100];
    //           printf("%s\n", getcwd(buff, sizeof(buff)));
    //           free(line);
    //           continue;
    //     }
    //     else
    //         line = readline("minishell $ ");
    
    // }

}