/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:42 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/04 08:40:21 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**allocate_numbers(int argc)
{
	char	**numbers;

	numbers = malloc(sizeof(char *) * (argc * 100));
	if (!numbers)
		return (NULL);
	return (numbers);
}

void	process_split_result(char **split_result, char **numbers, int *j)
{
	int	k;

	k = 0;
	while (split_result[k])
	{
		if (split_result[k][0] != '\0' && !ft_strchr(split_result[k], '='))
			numbers[(*j)++] = split_result[k];
		else
			free(split_result[k]);
		k++;
	}
}

static char	**process_single_argument(char *arg)
{
	char	**numbers;

	numbers = split(arg, ' ');
	if (!numbers || !*numbers)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (numbers);
}

static char	**process_multiple_arguments(int argc, char **argv)
{
	char	**numbers;
	int		i;

	numbers = malloc(sizeof(char *) * argc);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		numbers[i - 1] = ft_strdup(argv[i]);
		if (!numbers[i - 1])
		{
			while (--i >= 0)
				free(numbers[i]);
			free(numbers);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	numbers[argc - 1] = NULL;
	return (numbers);
}

char	**process_arguments(int argc, char **argv)
{
	if (argc == 2)
		return (process_single_argument(argv[1]));
	else
		return (process_multiple_arguments(argc, argv));
}
