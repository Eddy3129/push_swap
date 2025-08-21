/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:00 by eddlim            #+#    #+#             */
/*   Updated: 2025/08/21 19:05:00 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*max_node;

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

	if (is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
	{
		set_positions(*a);
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

static void	push_back_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max_node;

	while (*b)
	{
		set_positions(*b);
		max_node = find_max_node(*b);
		while (*b != max_node)
		{
			if (max_node->above_median)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

static void	finalize_stack_a(t_stack_node **a)
{
	t_stack_node	*min_node;

	set_positions(*a);
	min_node = find_min_node(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	do_turk_sort(a, b);
	sort_three(a);
	push_back_to_a(a, b);
	finalize_stack_a(a);
}
