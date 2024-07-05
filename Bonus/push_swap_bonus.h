/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:02:48 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/05 08:29:26 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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

int				ft_strcmp(const char *s1, const char *s2);
void			ft_pb(t_stack_node **a, t_stack_node **b, bool print);
void			ft_pa(t_stack_node **b, t_stack_node **a, bool print);
void			ft_rra(t_stack_node **a, bool print);
void			ft_rrb(t_stack_node **b, bool print);
void			ft_rrr(t_stack_node **a, t_stack_node **b, bool print);
void			ft_rr(t_stack_node **a, t_stack_node **b, bool print);
void			ft_rb(t_stack_node **b, bool print);
void			ft_ra(t_stack_node **a, bool print);
void			ft_sa(t_stack_node	**a, bool print);
void			ft_sb(t_stack_node **b, bool print);
void			ft_ss(t_stack_node **a, t_stack_node **b, bool print);
void			free_stack(t_stack_node **stack);
char			*get_next_line(int fd);
char			**split(char *s, char c);
void			init_stack_a_bonus(t_stack_node **a, char **argv);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
size_t			ft_strlen(char *str);
char			*ft_strchr(const char *s, int c);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			ft_putstr_fd(char *s, int fd);
int				stack_len(t_stack_node *stack);
char			**process_arguments(int argc, char **argv);
void			process_split_result(char **split_result, char **numbers,
					int *j);
char			**allocate_numbers(int argc);
char			*ft_strchr(const char *s, int c);
void			init_stack_a_bonus(t_stack_node **a, char **argv);
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_errors(t_stack_node **a);
void			moves_checker(t_stack_node **stack_a, t_stack_node **stack_b);
long			ft_atol(const char *s);
int 			ft_isspace(int c);
int				ft_isdigit(int c);

#endif