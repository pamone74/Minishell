#include "../minishell.h"

void    ft_add_node(t_env *new_node)
{
    t_env *tmp;

    if (!g_minishell.env_list)
    {
        g_minishell.env_list = new;
        return ;
    }
    tmp = g_minishell.env_list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}
t_env	*ft_new_node_env(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (0);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}
char	*ft_get_key(char *str)
{
	int		len;
	char	*new;

	if (ft_strchr(str, '=') == NULL)
		len = ft_strlen(str) + 1;
	else
	{
		new = ft_strchr(str, '=');
		len = new - str + 1;
	}
	new = malloc(len * sizeof(char));
	ft_strlcpy(new, str, len);
	return (new);
}
char	*ft_get_value(char *str)
{
    char	*new;
    char	*tmp;

    if (ft_strchr(str, '=') == NULL)
        return (NULL);
    tmp = ft_strchr(str, '=') + 1;
    new = ft_strdup(tmp);
    return (new);
}

void    ft_get_env_list(char **envp)
{
    int i;

    i = 0;
    g_minishell.env_list = NULL;
    while (envp[i])
    {
        ft_add_node(ft_new_node_env(ft_get_key(envp[i]), ft_get_value(envp[i])));
        i++;
    }
}