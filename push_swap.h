#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
    int		        num;
    int            index;
    struct s_stack_node *target;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}	t_stack_node;

int check_valid_int(char *s);
int check_valid_set(char **set);
long    ft_atol(const char *s);
void    init_stack(t_stack_node **stack, char **av);
void    print_stack(t_stack_node *stack);
int         check_dup(int num, char **set, int index);
void    ft_addtostack(t_stack_node **stack, int n);
t_stack_node *ft_getlastnode(t_stack_node *stack);
void    ft_freestack(t_stack_node **stack);

#endif