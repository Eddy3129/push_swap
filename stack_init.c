/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:54 by marvin            #+#    #+#             */
/*   Updated: 2025/08/21 19:15:00 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_temp_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	fill_indices(t_stack_node **stack, int *arr)
{
	t_stack_node	*current;
	int			i;
	int			size;

	current = *stack;
	size = stack_size(*stack);
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->num == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_indices(t_stack_node **stack)
{
	int				*temp_arr;
	int				size;
	int				i;
	t_stack_node	*current;

	size = stack_size(*stack);
	if (size == 0)
		return ;
	temp_arr = (int *)malloc(sizeof(int) * size);
	if (!temp_arr)
		return ;
	current = *stack;
	i = 0;
	while (current)
	{
		temp_arr[i++] = current->num;
		current = current->next;
	}
	sort_temp_array(temp_arr, size);
	fill_indices(stack, temp_arr);
	free(temp_arr);
}

void	init_stack(t_stack_node **stack, char **av)
{
	int		i;
	long	value;

	*stack = NULL;
	i = 0;
	while (av[i])
	{
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_freestack(stack);
			ft_putendl_fd("Error", 2);
			return ;
		}
		if (!check_dup(value, av, i))
		{
			ft_freestack(stack);
			return ;
		}
		ft_addtostack(stack, value);
		i++;
	}
	assign_indices(stack);
}