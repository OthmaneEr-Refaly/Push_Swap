/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 09:52:20 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/09 11:37:18 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
}						t_stack_node;

void					init_stack_a(t_stack_node **a, char **argv);
int						ft_isdigit(char c);
bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
void					sa(t_stack_node **a);
void					sort_three(t_stack_node **a);
t_stack_node			*find_last(t_stack_node *stack);
void					ra(t_stack_node **a);
void					rra(t_stack_node **a);
void					rrr(t_stack_node **a, t_stack_node **b);
void					rrb(t_stack_node **b);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
t_stack_node			*find_max(t_stack_node *stack);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					current_index(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					pa(t_stack_node **a, t_stack_node **b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node			*find_min(t_stack_node *stack);
int						error_syntax(char *str_n);
void					free_errors(t_stack_node **a);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					min_on_top(t_stack_node **a);
char					**split(char *s, char c);
char					*ft_strncpy(char *dest, const char *src, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t n);
char					*ft_strchr(const char *s, int c);
char					**process_arguments(int argc, char **argv);
// long			ft_atol(const char *s);
char					*ft_strdup(const char *s1);
void					free_numbers(char **numbers);
int						ft_isspace(int c);
size_t					ft_strlen(const char *s);
void					ft_putstr_fd(char *s, int fd);
char					**allocate_and_fill_numbers(int argc, char **argv,
							int total_numbers);
int						has_non_whitespace_arg(int argc, char **argv);
void					free_numbers_array(char **numbers, int count);
int						count_total_numbers(int argc, char **argv);
int						counting(char *arg);
void					ft_some(char **numbers, char *argv, int total_numbers,
							int *k);

#endif