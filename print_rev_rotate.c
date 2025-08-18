/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:47:59 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 14:47:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **a)
{
	if (rev_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	if (rev_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (rev_rotate(a) && rev_rotate(b))
		ft_printf("rrr\n");
}
