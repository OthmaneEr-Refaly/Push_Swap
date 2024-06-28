/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:03:37 by oer-refa          #+#    #+#             */
/*   Updated: 2024/06/27 12:50:39 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	stack_sorted(t_stack_node *stack)
{
    t_stack_node *tmp;
	// if (!stack)
    // {
    //     ft_putstr_fd("KO\n",1);
    //     (free_stack(&stack), exit(0));
    // }
    tmp = stack;
    while (tmp->next)
	{ 
		if (tmp->nbr > tmp->next->nbr)
		{
			ft_putstr_fd("KO\n", 1);
			(free_stack(&stack),exit(0));
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("OK\n", 1);
	(free_stack(&stack),exit(0));
}

void	which_move(t_stack_node **stack_a, t_stack_node **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, false);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, false);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_b, stack_a, false);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, false);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, false);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, false);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, false);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
    else
    {
        get_next_line(1000);
    }
}

void moves_checker(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (1)
	{
        if (!line)
            break;
		which_move(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		exit(0);
    else if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a_bonus(&a, argv + 1);
	moves_checker(&a, &b);
    if (stack_sorted(a))
        printf("OK\n");
    // if (stack_sorted(b))
    //     printf("OK\n");
    free_stack(&a);

}
