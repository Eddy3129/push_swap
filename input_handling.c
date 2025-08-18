/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:52:09 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 13:52:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_int(char *s)
{
	int	i;

	if (!s || !s[0] || ((s[0] == '+' || s[0] == '-') && !s[1]))
		return (0);
	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(int num, char **set, int index)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (num == ft_atol(set[i]) && i != index)
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_set(char **set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (!check_valid_int(set[i]))
			return (0);
		i++;
	}
	return (1);
}
