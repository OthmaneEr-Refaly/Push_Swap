/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:05:16 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/10 09:41:37 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static	long	ft_atol(const char *s)
// {
// 	long	(result) , (prev);
// 	int		sign;

// 	result = 0;
// 	sign = 1;
// 	while (*s == ' ' || (*s >= 9 && *s <= 13))
// 		s++;
// 	if (*s == '-' || *s == '+')
// 	{
// 		if (*s == '-')
// 			sign = -1;
// 		s++;
// 	}
// 	while (*s >= '0' && *s <= '9')
// 	{
// 		prev = result;
// 		result = result * 10 + (*s - '0');
// 		if (result < prev)
// 		{
// 			if (sign == 1)
// 				return (LONG_MAX);
// 			else
// 				return (LONG_MIN);
// 		}
// 		s++;
// 	}
// 	return (result * sign);
// }
// void free_all(char **argv, t_stack_node **a)
// {

// 	int	i;

// 	i = 0;
// 	while (argv[i])
// 		free(argv[i++]);
// 	free(argv);
// 	free_stack(a);
// 	exit(1);
// }

long long	result(char *argv, int i)
{
	int			r;
	long long	d;

	r = 0;
	d = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		r = (r * 10) + (argv[i] - '0');
		d = (d * 10) + (argv[i] - '0');
		i++;
	}
	return (d);
}

int	ft_atoi(char *argv, t_stack_node **a)
{
	int			i;
	int			s;
	long long	d;

	i = 0;
	s = 1;
	while ((argv[i] >= 9 && argv[i] <= 13) || (argv[i] == ' '))
		i++;
	if (argv[i] == '+' || argv[i] == '-')
	{
		if (argv[i] == '-')
			s = s * -1;
		i++;
	}
	d = result(argv, i) * s;
	if (d > INT_MAX || d < INT_MIN)
	{
		i = 0;
		printf("Max Error");
		// free_all(&argv,a);
		free_errors(a);
		exit(1);
	}
	return (result(argv, i) * s);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atoi(argv[i],a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
