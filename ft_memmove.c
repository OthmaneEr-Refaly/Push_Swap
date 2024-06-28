/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:59:13 by oer-refa          #+#    #+#             */
/*   Updated: 2024/06/28 08:04:41 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	unsigned const char	*psrc;
	size_t				i;

	pdst = dst;
	psrc = src;
	if (!pdst && !psrc)
		return (NULL);
	if (pdst == psrc)
		return (pdst);
	if (pdst < psrc)
		ft_memcpy(dst, src, n);
	else if (pdst > psrc)
	{
		i = n;
		while (i > 0)
		{
			pdst[i - 1] = psrc[i - 1];
			i--;
		}
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	unsigned const char	*psrc;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (0);
	if (dst == src)
		return (dst);
	pdst = dst;
	psrc = src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
