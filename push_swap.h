#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> 
# include <limits.h> 
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; //The number to sort
	int					index; //The number's position in the stack
	int					push_cost; //How many commands in total
	bool				above_median; //Used to calculate `push_cost`
	bool				cheapest; //The node that is the cheapest to do commands
	struct s_stack_node	*target_node; //The target node of a node in the opposite stack
	struct s_stack_node	*next; //A pointer to the next node
	struct s_stack_node	*prev; //A pointer to the previous node
}	t_stack_node; //The "shortened name", "t_stack_node". `t_` for type

void	init_stack_a(t_stack_node **a, char **argv);
bool	stack_sorted(t_stack_node *stack);
int stack_len(t_stack_node *stack);
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
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	pa(t_stack_node **a, t_stack_node **b, bool print);








#endif