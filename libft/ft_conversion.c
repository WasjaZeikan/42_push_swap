/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:30:55 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:14:27 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_toupper(int ch)
{
	if (ch < 'a' || ch > 'z')
		return (ch);
	return (ch - ('a' - 'A'));
}

int	ft_tolower(int ch)
{
	if (ch < 'A' || ch > 'Z')
		return (ch);
	return (ch + ('a' - 'A'));
}

int	ft_atoi(const char *src)
{
	int64_t	num;

	num = ft_atoi_base(src, DECIMAL);
	if (num >= INT_MAX)
		return (INT_MAX);
	if (num <= INT_MIN)
		return (INT_MIN);
	return ((int) num);
}

char	*ft_itoa(int n)
{
	char	buf[MAX_DIGIT_COUNT];

	return (ft_strdup(ft_itoa_base(n, DECIMAL, buf)));
}
