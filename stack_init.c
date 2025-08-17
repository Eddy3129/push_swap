#include "push_swap.h"

long    ft_atol(const char *s)
{
    long    result;
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    } 
    while (ft_isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    return (result * sign);
}

void init_stack(t_stack_node **stack, char **av)
{
    int i;
    long value;
    
    *stack = NULL;
    i = 0;
    while (av[i])
    {
        value = ft_atol(av[i]);
        if (value > INT_MAX || value < INT_MIN)
        {
            ft_freestack(stack);
            ft_printf("Error values exceeded\n");
            return;
        }
        if (!check_dup(value, av, i))
        {
            ft_freestack(stack);
            ft_printf("Error values duplicated\n");
            return;
        }
        ft_addtostack(stack, value);
        i++;
    }
}