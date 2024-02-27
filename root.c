#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct s_node
{
    char    *data;
    struct s_node   *left;
    struct s_node   *right;
}   t_node;

t_node  *ft_new_node(char *data)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if(!node)
        return (NULL);
    node->data = strdup(data);
    if(!node->data)
        return (free(node), NULL);
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void ft_append_node(t_node **head, t_node *node)
{
    t_node  *tmp;

    if(!*head)
    {
        *head = node;
        return;
    }
    tmp = *head;
    while(tmp->right)
        tmp = tmp->right;
    tmp->right = node;
    node->left = tmp;
}

void    ft_print_tree(t_node *head)
{
    t_node  *tmp;

    tmp = head;
    while(tmp)
    {
        printf("%s\n", tmp->data);
        tmp = tmp->right;
    }
}

int main(void)
{
    t_node  *head;
    t_node  *node;

    head = NULL;
    node = ft_new_node("hello");
    ft_append_node(&head, node);
    node = ft_new_node("world");
    ft_append_node(&head, node);
    node = ft_new_node("this");
    ft_append_node(&head, node);
    node = ft_new_node("is");
    ft_append_node(&head, node);
    node = ft_new_node("a");
    ft_append_node(&head, node);
    node = ft_new_node("test");
    ft_append_node(&head, node);
    ft_print_tree(head);
    return (0);
}