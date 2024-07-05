/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:03:37 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/05 08:43:17 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	stack_sorted(t_stack_node *stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return (false);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void free_numbers(char **numbers)
{
    int i = 0;
    while (numbers[i])
        free(numbers[i++]);
    free(numbers);
}

int main(int argc, char *argv[])
{
    t_stack_node *a;
    t_stack_node *b;
    char **numbers;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (0);

    numbers = process_arguments(argc, argv);
    if (!numbers)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    init_stack_a_bonus(&a, numbers);
    moves_checker(&a, &b);

    if (stack_sorted(a) && !b)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);

    free_stack(&a);
    free_stack(&b);
    free_numbers(numbers);

    return (0);
}
