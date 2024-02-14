#include "minishel.h"
static int ft_count_word(char *str)
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
static int ft_strlen(char *str)
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
static char *ft_subsr(const char *str, int start, int end)
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

int ft_strcmp(const char *s1, const char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            return 1;
        s1++;
        s2++;
    }
    return 0;
}