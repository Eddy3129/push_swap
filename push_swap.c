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

static void	test_operations(t_stack_node **a, t_stack_node **b)
{
	ft_printf("Before push:\n");
	ft_printf("a:\n");
	print_stack(*a);
	ft_printf("b:\n");
	print_stack(*b);
	push(b, a);
	push(b, a);
	ft_printf("After push:\n");
	ft_printf("a:\n");
	print_stack(*a);
	ft_printf("b:\n");
	print_stack(*b);
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
	if (!check_valid_set(args))
	{
		ft_printf("Error, invalid values\n");
		if (should_free)
			free(args);
		return (1);
	}
	init_stack(&a, args);
	b = NULL;
	test_operations(&a, &b);
	ft_freestack(&a);
	if (should_free)
		free(args);
	return (0);
}
