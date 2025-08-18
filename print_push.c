/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:29:35 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 14:29:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	if (push(b, a))
		ft_printf("pb\n");
}
