/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:48 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 13:51:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					num;
	int					index;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int				check_valid_int(char *s);
int				check_valid_set(char **set);
long			ft_atol(const char *s);
void			init_stack(t_stack_node **stack, char **av);
void			print_stack(t_stack_node *stack);
int				check_dup(int num, char **set, int index);
void			ft_addtostack(t_stack_node **stack, int n);
t_stack_node	*ft_getlastnode(t_stack_node *stack);
void			ft_freestack(t_stack_node **stack);
void			swap(t_stack_node **head);
void			push(t_stack_node **dest, t_stack_node **src);
void			rotate(t_stack_node **stack);
void			rev_rotate(t_stack_node **stack);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif