/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 22:11:19 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 15:22:04 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(uint64_t n, const char *base, char *buf)
{
	size_t	i;
	size_t	b;

	if (n == 0)
	{
		buf[MAX_DIGIT_COUNT - 1] = '\0';
		buf[MAX_DIGIT_COUNT - 2] = base[0];
		return (buf + MAX_DIGIT_COUNT - 2);
	}
	i = MAX_DIGIT_COUNT;
	buf[--i] = '\0';
	b = ft_strlen(base);
	while (n)
	{
		buf[--i] = base[n % b];
		n /= b;
	}
	return (buf + i);
}

char	*ft_itoa_base(int64_t n, const char *base, char *buf)
{
	size_t	i;
	size_t	b;
	int64_t	num;

	if (n == 0)
	{
		buf[MAX_DIGIT_COUNT - 1] = '\0';
		buf[MAX_DIGIT_COUNT - 2] = base[0];
		return (buf + MAX_DIGIT_COUNT - 2);
	}
	num = n;
	if (n < 0)
		num = -num;
	i = MAX_DIGIT_COUNT;
	buf[--i] = '\0';
	b = ft_strlen(base);
	while (num)
	{
		buf[--i] = base[num % b];
		num /= b;
	}
	if (n < 0)
		buf[--i] = '-';
	return (buf + i);
}

int64_t	ft_atoi_base(const char *src, const char *base)
{
	int		sign;
	int64_t	num;
	size_t	b;
	size_t	index;

	while ((*src == ' ' || (*src >= 9 && *src <= 13)))
		src++;
	sign = 1;
	if (*src == '+' || *src == '-')
	{
		if (*src == '-')
			sign = -1;
		src++;
	}
	num = 0;
	b = ft_strlen(base);
	while (TRUE)
	{
		index = ft_index_of(base, *src);
		if (index == SIZE_MAX)
			break ;
		num = num * b + index;
		src++;
	}
	return (num * sign);
}

static void	fraction_to_str(float frac_part, int precision, char *buf)
{
	int	i;
	int	digit;
	int	idx;

	idx = MAX_DIGIT_COUNT;
	i = 0;
	while (i < precision)
	{
		frac_part *= 10.0f;
		digit = (int) frac_part;
		buf[idx++] = digit + '0';
		frac_part -= digit;
		i++;
	}
	buf[idx] = '\0';
}

char	*ft_ftoa(float value, int precision, char *buf)
{
	int		int_part;
	char	*str;

	int_part = (int) value;
	str = ft_itoa_base(int_part, DECIMAL, buf);
	if (precision == 0 || precision > FTOA_MAX_PRECISION)
		return (str);
	if (value < 0)
	{
		value = -value;
		int_part = -int_part;
	}
	value -= (float) int_part;
	buf[MAX_DIGIT_COUNT - 1] = '.';
	fraction_to_str(value, precision, buf);
	return (str);
}
