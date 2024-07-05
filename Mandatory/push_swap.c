/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:00:08 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/05 09:37:30 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}

static int	check_errors(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (error_syntax(numbers[i]))
		{
			free_numbers(numbers);
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

void    free_numbers(char **numbers)
{
    int    i;

    i = 0;
    while (numbers[i])
    {
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int main(int argc, char **argv)
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

    if (check_errors(numbers))
    {
        free_numbers(numbers);
        return (1);
    }

    init_stack_a(&a, numbers);
    sort_stack(&a, &b);
    free_numbers(numbers);
    free_stack(&a);
    return (0);
}
