/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:42:05 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:24:17 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define MAX_PREFIX_LEN 2

static inline t_bool	is_zero_precision(t_uint num, t_specifier *spec)
{
	return (num == 0 && spec->precision == 0);
}

size_t	spec_decimal_handler(t_specifier *spec, t_buffer *buf, va_list *args)
{
	char		str_buf[MAX_DIGIT_COUNT + MAX_PREFIX_LEN];
	t_ntoa_buf	num_buf;
	char		*str;
	int			num;

	num = va_arg(*args, int);
	if (is_zero_precision(num, spec))
		return (ft_buffer_add_justified("", 0, spec, buf));
	str = ft_itoa_base(num, DECIMAL, str_buf + MAX_PREFIX_LEN);
	num_buf.prefix_len = 0;
	if (num < 0)
		num_buf.prefix_len = 1;
	else if (spec->number_prefix != '\0')
	{
		*(--str) = spec->number_prefix;
		num_buf.prefix_len = 1;
	}
	num_buf.str = str;
	num_buf.len = ft_strlen(str);
	return (ft_buffer_addn_justified(&num_buf, spec, buf));
}

size_t	spec_unsigned_handler(t_specifier *spec, t_buffer *buf, va_list *args)
{
	char		str_buf[MAX_DIGIT_COUNT];
	t_ntoa_buf	num_buf;
	t_uint		num;

	num = va_arg(*args, t_uint);
	if (is_zero_precision(num, spec))
		return (ft_buffer_add_justified("", 0, spec, buf));
	num_buf.str = ft_utoa_base(num, DECIMAL, str_buf);
	num_buf.len = ft_strlen(num_buf.str);
	num_buf.prefix_len = 0;
	return (ft_buffer_addn_justified(&num_buf, spec, buf));
}

size_t	spec_hex_lowercase_handler(
	t_specifier *spec, t_buffer *buf, va_list *args)
{
	char		str_buf[MAX_DIGIT_COUNT + MAX_PREFIX_LEN];
	char		*str;
	t_ntoa_buf	num_buf;
	t_uint		num;

	num = va_arg(*args, t_uint);
	if (is_zero_precision(num, spec))
		return (ft_buffer_add_justified("", 0, spec, buf));
	str = ft_utoa_base(num, HEX_LOWER, str_buf + MAX_PREFIX_LEN);
	num_buf.prefix_len = 0;
	if (spec->is_alternative_form && num != 0)
	{
		*(--str) = 'x';
		*(--str) = '0';
		num_buf.prefix_len = 2;
	}
	num_buf.str = str;
	num_buf.len = ft_strlen(str);
	return (ft_buffer_addn_justified(&num_buf, spec, buf));
}

size_t	spec_hex_uppercase_handler(
	t_specifier *spec, t_buffer *buf, va_list *args)
{
	char		str_buf[MAX_DIGIT_COUNT + MAX_PREFIX_LEN];
	char		*str;
	t_ntoa_buf	num_buf;
	t_uint		num;

	num = va_arg(*args, t_uint);
	if (is_zero_precision(num, spec))
		return (ft_buffer_add_justified("", 0, spec, buf));
	str = ft_utoa_base(num, HEX_UPPER, str_buf + MAX_PREFIX_LEN);
	num_buf.prefix_len = 0;
	if (spec->is_alternative_form && num != 0)
	{
		*(--str) = 'X';
		*(--str) = '0';
		num_buf.prefix_len = 2;
	}
	num_buf.str = str;
	num_buf.len = ft_strlen(str);
	return (ft_buffer_addn_justified(&num_buf, spec, buf));
}
