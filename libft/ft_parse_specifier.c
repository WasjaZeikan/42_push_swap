/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 22:18:22 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:24:23 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_bool	parse_flag(const char *str, t_specifier *spec)
{
	if (*str == '#')
		spec->is_alternative_form = TRUE;
	else if (*str == '+')
		spec->number_prefix = '+';
	else if (*str == ' ' && spec->number_prefix != '+')
		spec->number_prefix = ' ';
	else if (*str == '-')
		spec->is_left_adjusted = TRUE;
	else if (*str == '0')
		spec->is_zero_padded = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

static const char	*parse_field_modifiers(const char *str, t_specifier *spec)
{
	if (ft_isdigit(*str))
	{
		spec->width = (t_uint) ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	if (*str == '.')
	{
		str++;
		spec->precision = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	return (str);
}

static void	init_specifier(t_specifier *spec)
{
	spec->is_alternative_form = FALSE;
	spec->is_left_adjusted = FALSE;
	spec->is_zero_padded = FALSE;
	spec->number_prefix = '\0';
	spec->pad_character = ' ';
	spec->pad_digit = '0';
	spec->precision = -1;
	spec->specifier = SPEC_NONE;
	spec->width = 0;
}

static t_spec	get_specifier(char ch)
{
	t_spec	spec;

	spec = SPEC_NONE;
	if (ch == '%')
		spec = SPEC_PERCENT;
	else if (ch == 'c')
		spec = SPEC_CHAR;
	else if (ch == 'p')
		spec = SPEC_POINTER;
	else if (ch == 's')
		spec = SPEC_STRING;
	else if (ch == 'u')
		spec = SPEC_UNSIGNED;
	else if (ch == 'x')
		spec = SPEC_HEX_LOWERCASE;
	else if (ch == 'X')
		spec = SPEC_HEX_UPPERCASE;
	else if (ch == 'd' || ch == 'i')
		spec = SPEC_DECIMAL;
	return (spec);
}

size_t	parse_specifier(const char *str, t_specifier *spec)
{
	const char	*start;

	init_specifier(spec);
	start = str;
	while (parse_flag(str, spec))
		str++;
	str = parse_field_modifiers(str, spec);
	spec->specifier = get_specifier(*str);
	if (spec->is_zero_padded && !spec->is_left_adjusted && spec->precision < 0)
		spec->pad_character = '0';
	return (str - start + (*str != '\0'));
}
