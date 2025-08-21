/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:48 by marvin            #+#    #+#             */
/*   Updated: 2025/08/21 14:59:10 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdbool.h>

typedef struct s_stack_node
{
	int					num;
	int					index;
	int					position;
	int					cost;
	bool				above_median;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int				check_valid_int(char *s);
int				check_valid_set(char **set);
int				is_sorted(t_stack_node *stack);
int				find_min(t_stack_node *stack);
int				find_max(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *stack);
void			sort_three(t_stack_node **stack);
void			sort_small(t_stack_node **a, t_stack_node **b);
void			sort_stack(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_cheapest_in_chunk(t_stack_node *a, int start_index, 
					int end_index);
int				stack_size(t_stack_node *stack);
void			set_index(t_stack_node *stack);
long			ft_atol(const char *s);
void			init_stack(t_stack_node **stack, char **av);
void			print_stack(t_stack_node *stack);
int				check_dup(int num, char **set, int index);
void			ft_addtostack(t_stack_node **stack, int n);
t_stack_node	*ft_getlastnode(t_stack_node *stack);
void			ft_freestack(t_stack_node **stack);
int				swap(t_stack_node **head);
int				push(t_stack_node **dest, t_stack_node **src);
int				rotate(t_stack_node **stack);
int				rev_rotate(t_stack_node **stack);
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

void			do_turk_sort(t_stack_node **a, t_stack_node **b);
void			set_positions(t_stack_node *stack);

#endif