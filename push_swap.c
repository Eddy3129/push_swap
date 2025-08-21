/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:43 by marvin            #+#    #+#             */
/*   Updated: 2025/08/21 19:10:00 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_logic(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 10)
		sort_small(a, b);
	else
		sort_stack(a, b);
}

static char	**parse_args(int ac, char **av, int *should_free)
{
	char	**args;

	*should_free = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		*should_free = 1;
	}
	else
	{
		args = av + 1;
		*should_free = 0;
	}
	return (args);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				should_free;

	if (ac < 2)
		return (1);
	args = parse_args(ac, av, &should_free);
	b = NULL;
	if (!check_valid_set(args))
	{
		if (should_free)
			free(args);
		return (1);
	}
	init_stack(&a, args);
	sort_logic(&a, &b);
	ft_freestack(&a);
	ft_freestack(&b);
	if (should_free)
		free(args);
	return (0);
}