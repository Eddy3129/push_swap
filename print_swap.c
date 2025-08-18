/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:25:41 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 14:25:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (swap(a) && swap(b))
		ft_printf("ss\n");
}
