/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:43 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 13:51:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->num)
			ft_printf("%d\n", stack->num);
		stack = stack->next;
	}
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

static void	test_operations(t_stack_node **a)
{
	ft_printf("Before rotate:\n");
	print_stack(*a);
	rev_rotate(a);
	ft_printf("After rev_rotate:\n");
	print_stack(*a);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	char			**args;
	int				should_free;

	if (ac < 2)
		return (1);
	args = parse_args(ac, av, &should_free);
	if (!check_valid_set(args))
	{
		if (should_free)
			free(args);
		return (1);
	}
	init_stack(&a, args);
	test_operations(&a);
	ft_freestack(&a);
	if (should_free)
		free(args);
	return (0);
}
