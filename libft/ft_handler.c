/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 22:18:22 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:40:38 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define NULL_STR "(null)"
#define NULL_STR_LEN 6

#define NIL_STR "(nil)"
#define NIL_STR_LEN 5

#define HEX_PREFIX_LEN 2

size_t	spec_none_handler(t_specifier *spec, t_buffer *buf, va_list *args)
{
	(void) spec;
	(void) buf;
	(void) args;
	return (0);
}

size_t	spec_percent_handler(t_specifier *spec, t_buffer *buf, va_list *args)
{
	const char	ch = '%';

	(void) args;
	return (ft_buffer_add_justified(&ch, 1, spec, buf));
}

size_t	spec_char_handler(t_specifier *spec, t_buffer *buf, va_list *args)
{
	char	ch;

	ch = (char) va_arg(*args, int);
	return (ft_buffer_add_justified(&ch, 1, spec, buf));
}

size_t	spec_pointer_handler(t_specifier *spec, t_buffer *buf, va_list *args)
{
	char		str_buf[MAX_DIGIT_COUNT + HEX_PREFIX_LEN];
	uintptr_t	num;
	char		*str;

	num = (uintptr_t) va_arg(*args, void *);
	if (num == 0)
		return (ft_buffer_add_justified(NIL_STR, NIL_STR_LEN, spec, buf));
	str = ft_utoa_base(num, HEX_LOWER, str_buf + HEX_PREFIX_LEN);
	*(--str) = 'x';
	*(--str) = '0';
	return (ft_buffer_add_justified(str, ft_strlen(str), spec, buf));
}

size_t	spec_string_handler(t_specifier *spec, t_buffer *buf, va_list *args)
{
	const char	*str;
	size_t		len;

	str = va_arg(*args, const char *);
	if (str == NULL)
		str = NULL_STR;
	len = ft_strlen(str);
	if (spec->precision >= 0 && len > (size_t) spec->precision)
		len = spec->precision;
	return (ft_buffer_add_justified(str, len, spec, buf));
}
