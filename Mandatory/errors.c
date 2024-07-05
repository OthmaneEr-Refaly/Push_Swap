/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 08:43:39 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/04 09:38:47 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n)
{
	if (!str_n)
		return (1);
	while (*str_n == ' ' || *str_n == '\t')
		str_n++;
	if (*str_n == '\0')
		return (1);
	if (*str_n == '+' || *str_n == '-')
		str_n++;
	if (*str_n < '0' || *str_n > '9')
		return (1);
	while (*str_n >= '0' && *str_n <= '9')
		str_n++;
	while (*str_n == ' ' || *str_n == '\t')
		str_n++;
	return (*str_n != '\0');
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
