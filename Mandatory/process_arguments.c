/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:42 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/09 16:06:25 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**process_arguments(int argc, char **argv)
{
	int		total_numbers;
	char	**numbers;

	if (!has_non_whitespace_arg(argc, argv))
		exit (1);
	total_numbers = count_total_numbers(argc, argv);
	if (total_numbers == 0)
		return (NULL);
	numbers = allocate_and_fill_numbers(argc, argv, total_numbers);
	if (!numbers)
	{
		free_numbers(numbers);
		return(NULL);	
	}
	return (numbers);
}

char	**allocate_and_fill_numbers(int argc, char **argv, int total_numbers)
{
	char	**numbers;
	int		k;
	int		i;

	numbers = malloc(sizeof(char *) * (total_numbers + 1));
	if (!numbers)
		return (NULL);
	k = 0;
	i = 1;
	while (i < argc)
	{
		ft_some(numbers, argv[i], total_numbers, &k);
		i++;
	}
	numbers[total_numbers] = NULL;
	return (numbers);
}

int	has_non_whitespace_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	write(2,"Error\n",6);
	return (0);
}

void	free_numbers_array(char **numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
