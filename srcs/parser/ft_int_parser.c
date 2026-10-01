/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:44:11 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/28 17:00:03 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_main.h"
#include "libft.h"

static bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static bool	parse_int(const char **str, int *value)
{
	int64_t	number;
	int		sign;

	number = 0;
	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	if (!ft_isdigit(**str))
		return (false);
	while (**str >= '0' && **str <= '9')
	{
		number = number * 10 + (**str - '0');
		if (sign == 1 && number > INT_MAX)
			return (false);
		if (sign == -1 && (-number < INT_MIN))
			return (false);
		(*str)++;
	}
	if (**str && !is_space(**str))
		return (false);
	*value = (int)(number * sign);
	return (true);
}

static bool	is_number(const char **arg)
{
	const char	*str;

	str = *arg;
	str += (*str == '-');
	if (!ft_isdigit(*str))
		return (false);
	while (ft_isdigit(*str))
		str++;
	if (*str && !is_space(*str))
		return (false);
	*arg = str;
	return (true);
}

int	ft_count_numbers(int argc, char **argv)
{
	const char	*str;
	int			count;
	int			i;

	count = 0;
	i = 0;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			while (*str && is_space(*str))
				str++;
			if (*str == '\0')
				break ;
			if (!is_number(&str))
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

bool	ft_parse_values(int *values, int argc, char **argv)
{
	int			i;
	int			j;
	const char	*str;

	i = 0;
	j = 0;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			while (*str && is_space(*str))
				str++;
			if (*str == '\0')
				break ;
			if (!parse_int(&str, values + j))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
