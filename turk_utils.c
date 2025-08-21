/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:30:00 by eddlim            #+#    #+#             */
/*   Updated: 2025/08/21 19:00:00 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack_node **s, t_stack_node *n, bool is_a)
{
	while (n->position-- > 0)
	{
		if (is_a)
		{
			if (n->above_median)
				ra(s);
			else
				rra(s);
		}
		else
		{
			if (n->above_median)
				rb(s);
			else
				rrb(s);
		}
	}
}

static void	execute_move(t_stack_node **a, t_stack_node **b, t_stack_node *chpst)
{
	while (chpst->position != 0 && chpst->target->position != 0 &&
		chpst->above_median && chpst->target->above_median)
	{
		rr(a, b);
		chpst->position--;
		chpst->target->position--;
	}
	while (chpst->position != 0 && chpst->target->position != 0 &&
		!chpst->above_median && !chpst->target->above_median)
	{
		rrr(a, b);
		chpst->position--;
		chpst->target->position--;
	}
	rotate_to_top(a, chpst, true);
	rotate_to_top(b, chpst->target, false);
	pb(a, b);
}

static void	set_costs(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->cost = a->position;
		if (!a->above_median)
			a->cost = len_a - a->position;
		if (a->target->above_median)
			a->cost += a->target->position;
		else
			a->cost += len_b - a->target->position;
		a = a->next;
	}
}

static void	set_targets(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_b;
	t_stack_node	*target;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		curr_b = b;
		target = find_max_node(b);
		while (curr_b)
		{
			if (curr_b->num < a->num && curr_b->num > best_match)
			{
				best_match = curr_b->num;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		a->target = target;
		a = a->next;
	}
}

void	do_turk_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		set_positions(*a);
		set_positions(*b);
		set_targets(*a, *b);
		set_costs(*a, *b);
		cheapest = *a;
		while (*a)
		{
			if ((*a)->cost < cheapest->cost)
				cheapest = *a;
			*a = (*a)->next;
		}
		execute_move(a, b, cheapest);
	}
}