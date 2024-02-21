#include "minishel.h"

void    ft_ls(char **str)
{
    char *path = ft_strjoin("/bin/", str[0]);
    if(ft_check_external(str[0]))
    {
        if(!execve(path, str, NULL))
            printf("Error\n");
    }
    else
        printf("Invalid command\n");
}
void    ft_cp(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/cp", str, NULL))
            printf("Error!");
    }
}

void    ft_mv(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/mv", str, NULL))
            printf("Error\n");
    }
}
void    ft_rm(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/rm", str, NULL))
            printf("Error\n");
    }
}
void    ft_mkdir(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/mkdir", str, NULL))
            printf("Error\n");
    }
}
void    ft_rmdir(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/rmdir", str, NULL))
            printf("Error\n");
    }
}
void    ft_cat(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/cat", str, NULL))
            printf("Error\n");
    }
}
void    ft_grep(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/grep", str, NULL))
            printf("Error\n");
    }
}
void    ft_find(char **str)
{
    if(ft_check_external(str[0]))
    {
        if(!execve("/bin/find", str, NULL))
            printf("Error\n");
    }
}

void    ft_exit()
{
    exit(EXIT_SUCCESS);
}
void    ft_built_in(char **str)
{
    if(ft_strcmp(str[0], "exit") == 0)
        ft_exit();
    else if(ft_strcmp(str[0], "cd") == 0)
        ft_cd(str);
    else if(ft_strcmp(str[0], "pwd") == 0)
        ft_pwd();
}

int ft_check_b(char *str)
{
    char *built_in[] = {"exit", "cd", "pwd", "export", "unset", "env", "echo", NULL};


    int i = 0;
    while(built_in[i] != NULL)
    {
        if(ft_strcmp(str, built_in[i]) == 0)
            return 1;
        i++;
    }
    return 0;

}

void    ft_cd(char **str)
{
    if(chdir(str[1]) != 0)
        printf("Error\n");

}

void    ft_pwd(void)
{
    char buff[1024];

    printf("%s\n", getcwd(buff, sizeof(buff)));
}