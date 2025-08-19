/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:54 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 13:25:58 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;
	int		i;

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

void	set_index(t_stack_node *stack)
{
	int				i;
	int				stack_len;

	i = 0;
	if (!stack)
		return ;
	stack_len = stack_size(stack);
	while (stack)
	{
		stack->index = i;
		if (i > stack_len / 2)
			stack->above_median = 0;
		else
			stack->above_median = 1;
		stack = stack->next;
		i++;
	}
}

void	init_stack(t_stack_node **stack, char **av)
{
	int		i;
	long	value;

	*stack = NULL;
	i = 0;
	while (av[i])
	{
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_freestack(stack);
			ft_putendl_fd("Error", 2);
			return ;
		}
		if (!check_dup(value, av, i))
		{
			ft_freestack(stack);
			return ;
		}
		ft_addtostack(stack, value);
		i++;
	}
	set_index(*stack);
}
