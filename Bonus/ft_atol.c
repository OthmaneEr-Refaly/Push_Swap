/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:35:36 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/02 10:44:17 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\v');
}

static int	ft_parse_sign(const char **s)
{
	int	sign;

	sign = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		++*s;
	}
	return (sign);
}

long	ft_atol(const char *s)
{
	long	result;
	int		sign;
	long	prev;

	result = 0;
	while (ft_is_whitespace(*s))
		s++;
	sign = ft_parse_sign(&s);
	while (*s >= '0' && *s <= '9')
	{
		prev = result;
		result = result * 10 + (*s - '0');
		if (result < prev)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		s++;
	}
	return (result * sign);
}
