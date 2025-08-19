/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:00 by eddlim            #+#    #+#             */
/*   Updated: 2025/08/19 19:37:23 by eddlim           ###   ########.fr       */
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

static  int get_cost(t_stack_node *stack, t_stack_node *node)
{
    int     position;
    int     stack_len;

    position = 0;
    stack_len = stack_size(stack);
    while (stack && stack != node)
    {
        stack= stack->next;
        position++;
    }
    if (position > stack_len / 2)
        return (stack_len - position);
    return (position);
}

t_stack_node    *find_cheapest_in_chunk(t_stack_node *a, int start_index, int end_index)
{
    t_stack_node    *cheapest_node;
    t_stack_node    *current;
    int             lowest_cost;
    int             cost;

    lowest_cost = INT_MAX;
    cheapest_node = NULL;
    current = a;
    while (current)
    {
        if (current->index >= start_index && current->index <= end_index)
        {
            cost = get_cost(a, current);
            if (cost < lowest_cost)
            {
                lowest_cost = cost;
                cheapest_node = current;
            }
        }
        current = current->next;
    }
    return (cheapest_node);
}

void    sort_stack(t_stack_node **a, t_stack_node **b)
{
    int             stack_len;
    int             chunk_size;
    int             i;
    t_stack_node    *cheapest_node;

    stack_len = stack_size(*a);
    i = 0;
    chunk_size = 20;
    //while (stack_ )
}
