/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 20:34:19 by vzeikan           #+#    #+#             */
/*   Updated: 2026/08/19 21:56:07 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	t_byte	*b;
	size_t	i;

	b = (t_byte *) dest;
	i = 0;
	while (i < count)
		b[i++] = (t_byte) ch;
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;
	t_byte	*b;
	t_cbyte	*src_b;

	i = 0;
	b = (t_byte *) dest;
	src_b = (t_cbyte *) src;
	while (i < count)
	{
		b[i] = src_b[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;
	t_cbyte	*src_b;
	t_byte	*b;

	i = 0;
	src_b = (t_cbyte *) src;
	b = (t_byte *) dest;
	if (b < src_b)
		ft_memcpy(b, src_b, count);
	else if (b > src_b)
	{
		i = count;
		while (i > 0)
		{
			i--;
			b[i] = src_b[i];
		}
	}
	return (dest);
}

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	t_cbyte	*b;
	size_t	i;

	i = 0;
	b = (t_cbyte *) ptr;
	while (i < count)
	{
		if (b[i] == (t_cbyte)ch)
			return ((void *)(b + i));
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	t_cbyte	*b1;
	t_cbyte	*b2;
	size_t	i;

	i = 0;
	b1 = (t_cbyte *) lhs;
	b2 = (t_cbyte *) rhs;
	while (i < count)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
