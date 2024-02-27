#include "minishell.h"
#include "tokens/token.h"

t_minishell g_minishell;

int main(int argc, char **argv, char **envp)
{
    char    *line;

    if (argc > 1)
        return((void)argv, 1);
    ft_get_env_list(envp);
    g_minishell.exit_status = 0;
    g_minishell.error_code = SUCESS;
    while(1)
    {
        //ft_init_signals();
        g_minishell.line = readline("minishell$ ");
        if(!g_minishell.line)
            exit(g_minishell.exit_status);
        g_minishell.tokens = ft_gen_token();
        if(!g_minishell.tokens)
            continue;
        g_minishell.ast = ft_parse_all();
        if(g_minishell.parse_error.type)
        {
            ft_handle_parse_err();
            continue;
        }
        signal(SIGQUIT, ft_sigquit_handler);
        exec();
    }
    
    return (0);
}