#include "minishel.h"

int ft_check_external(char *str)
{
    if(*str == '\n')
    {
        return 0;
    }
    char *comment[] = {"cd","find","pwd","/bin/ls","export","unset",                "ssh","env","cc","vi","vim","history","clear","ls","cat","touch","rm","tar",
"vim","nano","vi","ed","grep","awk","sed","cut","head","tail","less","more","diff","patch","sort","uniq","tr","wc","tee","xargs","bc","dc","expr","seq","join","paste","split","csplit","comm","diff3","patch","cmp","diffstat","col","colrm","column","pr","fold","fmt","nl","od","expand","unexpand","tac","rev","shuf","yes","echo","printf","date","sleep","true","false","test","[","expr","factor","seq","shred","stat","sync","truncate","unlink","mktemp","readlink","realpath","which","type","file","touch","rm","mv","cp","mkdir","rmdir","chmod","chown","whoami","su","wc","sudo","passwd","top","kill","ps","bg","fg","jobs","killall","pkill","pgrep","nice","renice","time","watch","sort","crontab","shutdown","reboot","halt","poweroff","init","telinit","runlevel","uname","hostname","uptime","date","cal","mv","cp","la","l","mkdir","rmdir","chmod","chown","whoami","su","wc","sudo","passwd","top","kill","ps","bg","help","fg","jobs","killall","pkill","pgrep","nice","renice","time","watch","sort","crontab","shutdown","reboot",
"halt","poweroff","init","telinit","runlevel","uname","hostname","uptime","date","wget","/bin/vim", "/bin/vi","cal" , "make",NULL };

    int i = 0;
    while(comment[i] != NULL)
    {
        if(ft_strcmp(str,comment[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

// void ft_exec_built_in(char **str)
// {
    // if(!ft_check_buit(str[0]))
    // {
        // printf("Command not found\n");
        // return;
    // }
    // if(!strcmp(str[0], "cd"))
        // ft_cd(str);
    // else if(!strcmp(str[0], "help"))
        // ft_help();
    // else if(!strcmp(str[0], "exit"))
        // ft_exit();
    // else if(!strcmp(str[0], "echo"))
        // ft_echo(str);
    // else if(!strcmp(str[0], "pwd"))
        // ft_pwd();
    // else if(!strcmp(str[0], "export"))
        // ft_export(str);
    // else if(!strcmp(str[0], "unset"))
        // ft_unset(str);
    // else if(!strcmp(str[0], "env"))
        // ft_env();
    // else if(!strcmp(str[0], "history"))
        // ft_history();
    // else if(!strcmp(str[0], "clear"))
        // ft_clear();
    // else if(!strcmp(str[0], "ls"))
        // ft_ls(str);
    // else if(!strcmp(str[0], "cat"))
        // ft_cat(str);
    // else if(!strcmp(str[0], "touch"))
        // ft_touch(str);
    // else if(!strcmp(str[0], "rm"))
        // ft_rm(str);
    // else if(!strcmp(str[0], "mv"))
        // ft_mv(str);
    // else if(!strcmp(str[0], "cp"))
        // ft_cp(str);
    // else if(!strcmp(str[0], "mkdir"))
        // ft_mkdir(str);
    // else if(!strcmp(str[0], "rmdir"))
        // ft_rmdir(str);
    // else if(!strcmp(str[0], "chmod"))
        // ft_chmod(str);
    // else if(!strcmp(str[0], "chown"))
        // ft_chown(str);
    // else if(!strcmp(str[0], "whoami"))
        // ft_whoami();
    // else if(!strcmp(str[0], "su"))
        // ft_su(str);
    // else if(!strcmp(str[0], "sudo"))
        // ft_sudo(str);
    // else if(!strcmp(str[0], "passwd"))
        // ft_passwd(str);
    // else if(!strcmp(str[0], "top"))
        // ft_top();
    // else if(!strcmp(str[0], "kill"))
        // ft_kill(str);
    // else if(!strcmp(str[0], "ps"))
        // ft_ps(str);
    // else if(!strcmp(str[0], "bg"))
// }

void ft_stack_add(t_cmd **head, char c)
{//printf("%d", c);

    t_cmd *Node = (t_cmd *)malloc(sizeof(t_cmd) + 1);
    if(!Node)
        return ;

    Node->data = c;
    Node->next = NULL;
    *(*head) = *Node;
   
}
void ft_append(t_cmd *head, char c)
{
    t_cmd *Node = (t_cmd *)malloc(sizeof(t_cmd) + 1);
    if(!Node)
        return;
    if(head == NULL)
    {
        ft_stack_add(&head, c);
        return ;
    }
    else
    {
        Node->data = c;
        Node->next = NULL;
        head->next = Node;
    }
    
    
    
    
    

}

