/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_justified.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:18:30 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:24:38 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_buffer_add_justified(const char *str,
	size_t len, t_specifier *spec, t_buffer *buf)
{
	size_t	padding;

	if (spec->width <= 0 || len >= spec->width)
	{
		ft_buffer_add(buf, str, len);
		return (len);
	}
	padding = spec->width - len;
	if (spec->is_left_adjusted)
	{
		ft_buffer_add(buf, str, len);
		ft_buffer_addc(buf, spec->pad_character, padding);
	}
	else
	{
		ft_buffer_addc(buf, spec->pad_character, padding);
		ft_buffer_add(buf, str, len);
	}
	return (len + padding);
}

static size_t	add_no_prefix(const char *str,
	size_t len, t_specifier *spec, t_buffer *buf)
{
	size_t	padding;
	size_t	digit_padding;
	size_t	count;

	digit_padding = spec->precision - len;
	count = len + digit_padding;
	padding = spec->width - count;
	if (spec->is_left_adjusted)
	{
		ft_buffer_addc(buf, spec->pad_digit, digit_padding);
		ft_buffer_add(buf, str, len);
		ft_buffer_addc(buf, spec->pad_character, padding);
	}
	else
	{
		ft_buffer_addc(buf, spec->pad_character, padding);
		ft_buffer_addc(buf, spec->pad_digit, digit_padding);
		ft_buffer_add(buf, str, len);
	}
	return (count + padding);
}

static size_t	add_zeroed(const t_ntoa_buf *num_buf,
	t_specifier *spec, t_buffer *buf)
{
	size_t		padding;
	size_t		len;
	const char	*str;

	len = num_buf->len;
	str = num_buf->str;
	if (spec->width <= len)
	{
		ft_buffer_add(buf, str, len);
		return (len);
	}
	padding = spec->width - len;
	if (num_buf->prefix_len != 0)
	{
		ft_buffer_add(buf, str, num_buf->prefix_len);
		str += num_buf->prefix_len;
		len -= num_buf->prefix_len;
	}
	ft_buffer_addc(buf, spec->pad_digit, padding);
	ft_buffer_add(buf, str, len);
	return (len + padding + num_buf->prefix_len);
}

static size_t	add_prefix(const t_ntoa_buf *num_buf,
			t_specifier *spec, t_buffer *buf)
{
	size_t		padding;
	size_t		digit_padding;
	size_t		count;
	size_t		digit_count;
	const char	*str;

	digit_count = num_buf->len - num_buf->prefix_len;
	digit_padding = (size_t) spec->precision - digit_count;
	count = num_buf->len + digit_padding;
	padding = spec->width - count;
	str = num_buf->str;
	if (spec->is_left_adjusted)
		ft_buffer_addc(buf, spec->pad_character, padding);
	ft_buffer_add(buf, str, num_buf->prefix_len);
	str += num_buf->prefix_len;
	ft_buffer_addc(buf, spec->pad_digit, digit_padding);
	ft_buffer_add(buf, str, digit_count);
	if (!spec->is_left_adjusted)
		ft_buffer_addc(buf, spec->pad_character, padding);
	return (count + padding);
}

size_t	ft_buffer_addn_justified(const t_ntoa_buf *num_buf,
			t_specifier *spec, t_buffer *buf)
{
	size_t	digit_padding;
	size_t	count;
	size_t	digit_count;

	if (spec->pad_character == '0')
		return (add_zeroed(num_buf, spec, buf));
	digit_count = num_buf->len - num_buf->prefix_len;
	if (spec->precision < 0 || digit_count >= (size_t) spec->precision)
		return (ft_buffer_add_justified(num_buf->str, num_buf->len, spec, buf));
	digit_padding = spec->precision - digit_count;
	count = digit_padding + num_buf->len;
	if (spec->width <= count)
	{
		ft_buffer_add(buf, num_buf->str, num_buf->prefix_len);
		ft_buffer_addc(buf, spec->pad_digit, digit_padding);
		ft_buffer_add(buf, num_buf->str + num_buf->prefix_len, digit_count);
		return (count);
	}
	if (num_buf->prefix_len == 0)
		return (add_no_prefix(num_buf->str, num_buf->len, spec, buf));
	return (add_prefix(num_buf, spec, buf));
}
