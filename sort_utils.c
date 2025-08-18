/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:28:31 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 20:28:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	int	num;

	if (!stack)
		return (1);
	num = stack->num;
	while (stack->next)
	{
		if (stack->next->num < num)
			return (0);
		num = stack->next->num;
		stack = stack->next;
	}
	return (1);
}

int	find_min(t_stack_node *stack)
{
	int	min;

	if (!stack)
		return (INT_MAX);
	min = stack->num;
	while (stack->next)
	{
		if (stack->next->num < min)
			min = stack->next->num;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack_node *stack)
{
	int	max;

	if (!stack)
		return (INT_MIN);
	max = stack->num;
	while (stack->next)
	{
		if (stack->next->num > max)
			max = stack->next->num;
		stack = stack->next;
	}
	return (max);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;
	int				min;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;
	int				max;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
