#include <stdlib.h>
#include <stdio.h>
typedef enum t_id{
    TYPE,
    ID,
} s_id;

typedef struct s_doubly_linked{
    char *str;
    s_id type;
    struct s_doubly_linked *next;
    struct s_doubly_linked *prev;
} t_r;

t_r *ft_add(char *str, s_id type)
{
    t_r *node = (t_r *)malloc(sizeof(t_r));
    if(!node)
        return NULL;
    node->str = str;
    node->type = type;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
void    ft_appen_doubly(t_r **head, t_r *new_node)
{
    t_r *currrrnt_node;
    if(!*head)
    {
        *head = new_node;
        return ;
    }
    currrrnt_node = *head;
    while (currrrnt_node && currrrnt_node->next) {
        currrrnt_node =currrrnt_node->next;
    }
    currrrnt_node->next = new_node;
   // new_node->next =currrrnt_node;
}
int main(int ac, char *argv[])
{
    t_r *node = ft_add(argv[0], ID);
    ft_appen_doubly(&node, ft_add(argv[1], TYPE));

    printf("The string is and the type is %s, %d", node->next->str, node->type);
}