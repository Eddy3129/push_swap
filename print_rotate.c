/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:46:11 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 14:46:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (rotate(a) && rotate(b))
		ft_printf("rr\n");
}
