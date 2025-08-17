#include "push_swap.h"

void    print_stack(t_stack_node *stack)
{
    while (stack)
    {
        if (stack->num)
            ft_printf("%d\n", stack->num);
        stack = stack->next;
    }
}

int main(int ac, char **av)
{
    t_stack_node *a;
    char **args;
    int should_free;

    should_free = 0;
    if (ac < 2)
        return (1);
    if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        should_free = 1;
    }
    else
    {
        args = av + 1;
        should_free = 0;
    }
    if (!check_valid_set(args))
    {
        ft_printf("Error, invalid values\n");
        if (should_free)
            free(args);
        return (1);
    }
    init_stack(&a, args);
    print_stack(a);
    ft_freestack(&a);
    if (should_free)
        free(args);
    return (0);
}