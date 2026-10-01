/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 20:21:55 by vzeikan           #+#    #+#             */
/*   Updated: 2026/08/19 21:53:58 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	t_byte	ch;

	ch = (t_byte) c;
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int	ft_isdigit(int c)
{
	t_byte	ch;

	ch = (t_byte) c;
	return (ch >= '0' && ch <= '9');
}

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
