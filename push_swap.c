/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:43 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 15:11:33 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
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

// static void	test_operations(t_stack_node **a)
// {
// 	ft_printf("Before rotate:\n");
// 	print_stack(*a);
// 	rev_rotate(a);
// 	ft_printf("After rev_rotate:\n");
// 	print_stack(*a);
// }

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				should_free;
	int				size;

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
	size = stack_size(a);
	if (!is_sorted(a))
	{
		if (size == 2)
			sa(&a);
		else if (size == 3)
			sort_three(&a);
		else if (size <= 100)
			sort_small(&a, &b);
	}
	print_stack(a);
	ft_freestack(&a);
	ft_freestack(&b);
	if (should_free)
		free(args);
	return (0);
}
