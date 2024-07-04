/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:07:16 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/03 15:21:06 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	apply_move_to_stack_a(t_stack_node **stack_a,
	t_stack_node **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(stack_a, false);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(stack_a, false);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(stack_a, false);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(stack_b, stack_a, false);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(stack_a, stack_b, false);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
}

void	apply_move_to_stack_b(t_stack_node **stack_a,
	t_stack_node **stack_b, char *line)
{
	if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(stack_b, false);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(stack_b, false);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(stack_b, false);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(stack_a, stack_b, false);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(stack_a, stack_b, false);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
}

void	which_move(t_stack_node **stack_a, t_stack_node **stack_b, char *line)
{
	if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(stack_a, stack_b, false);
	else if (ft_strcmp(line, "rrr\n") == 0)
        ft_rrr(stack_a, stack_b, false);
	else if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "ra\n") == 0
		|| ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "sa\n") == 0
		|| ft_strcmp(line, "rr\n") == 0)
		apply_move_to_stack_a(stack_a, stack_b, line);
	else if (ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "rb\n") == 0
		|| ft_strcmp(line, "rrb\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "rr\n") == 0)
		apply_move_to_stack_b(stack_a, stack_b, line);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
}

void	moves_checker(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		which_move(stack_a, stack_b, line);
		free(line);
	}
}
