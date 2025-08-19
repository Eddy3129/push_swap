/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:00 by eddlim            #+#    #+#             */
/*   Updated: 2025/08/19 14:53:25 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack_node **stack)
{
    t_stack_node    *max_node;

    max_node = find_max_node(*stack);
    if (*stack == max_node)
        ra(stack);
    else if ((*stack)->next == max_node)
        rra(stack);
    if (!is_sorted(*stack))
        sa(stack);
}

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;

	while (stack_size(*a) > 3)
	{
		min_node = find_min_node(*a);
		while (*a != min_node)
		{
			if (min_node->above_median)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
