/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 09:52:20 by oer-refa          #+#    #+#             */
/*   Updated: 2024/06/22 09:58:57 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> 
# include <limits.h> 
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void	init_stack_a(t_stack_node **a, char **argv);
bool	stack_sorted(t_stack_node *stack);
int	stack_len(t_stack_node *stack);
void	sa(t_stack_node	**a, bool print);
void	sort_three(t_stack_node **a);
int	ft_isdigit(int c);
t_stack_node	*find_last(t_stack_node *stack);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	current_index(t_stack_node *stack);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	prep_for_push(t_stack_node **stack,
			t_stack_node *top_node, char stack_name);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
int	error_syntax(char *str_n);
void	free_errors(t_stack_node **a);
int	error_duplicate(t_stack_node *a, int n);

#endif