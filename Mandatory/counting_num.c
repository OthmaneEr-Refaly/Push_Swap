/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:53:13 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/09 15:06:07 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_some2(char  *argv,char  **numbers, int *j, int *k)
{
	int start;
	int arg_len;
	
	start = 0;
	arg_len = ft_strlen(argv);
	
	if (ft_isdigit(argv[*j]) || ((argv[*j] == '-' || argv[*j] == '+') && *j
			+ 1 < arg_len && ft_isdigit(argv[*j + 1])))
	{
		start = *j;
		while (*j < arg_len && !ft_isspace(argv[*j]))
			(*j)++;
		numbers[*k] = malloc(*j - start + 1);
		if (!numbers[*k])
		{
			// free_numbers_array(numbers, *k);
			// free_numbers(numbers);
			return (0);
		}
		ft_strncpy(numbers[*k], argv + start, *j - start);
		numbers[*k][*j - start] = '\0';
		(*k)++;
		return 1;
	}
	return(0);
}

void	ft_some(char **numbers, char *argv, int total_numbers, int *k)
{
	int	arg_len;
	int	j;
	arg_len = ft_strlen(argv);
	j = 0;
	while (j < arg_len && *k < total_numbers)
	{
		while (j < arg_len && ft_isspace(argv[j]))
			j++;
		if (j == arg_len)
			break ;
		if (!ft_some2(argv, numbers, &j, k)) {
    		j++;
		
		}
	}
}
int	counting(char *argv)
{
	int	j;
	int	res;
	int	arg_len;

	j = 0;
	res = 0;
	arg_len = ft_strlen(argv);
	while (j < arg_len)
	{
		while (j < arg_len && ft_isspace(argv[j]))
		{
			j++;
		}
		if ((ft_isspace(argv[j])) && argv[j + 1] == '\0')
		{
			printf("Er1ror");
			exit(1);
		}
		if (j == arg_len)
		{
			// printf("argv[j] inside 1====> %c\n",argv[j]);
			break ;
		}
		// printf("argv[j] inside 2 ====> %c\n",argv[j]);
		if (ft_isdigit(argv[j]) || ((argv[j] == '-' || argv[j] == '+') && j
				+ 1 < arg_len && ft_isdigit(argv[j + 1])))
		{
			// printf("argv[j] inside 3 ====> %c\n",argv[j]);
			res++;
			while (j < arg_len && !ft_isspace(argv[j]))
				j++;
		}
		else
			j++;
	}
	// printf("count ====> %d\n",res);

	return (res);
}

int	count_total_numbers(int argc, char **argv)
{
	int	total_numbers;
	int	i;
	int j;

	i = 1;
	j = 0;
	total_numbers = 0;
	while (i < argc)
	{
		// printf("argv[i] 1 ====> %s\n",argv[i]);
		total_numbers += counting(argv[i]);
		// printf("argv[i] 2 ====> %s\n",argv[i]);
		i++;
	}
	return (total_numbers);
}
