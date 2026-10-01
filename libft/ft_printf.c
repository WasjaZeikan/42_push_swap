/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:49:05 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:45:11 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	handle_raw_string(const char *str, t_buffer *buf, size_t *count)
{
	const char	*start;
	size_t		len;

	start = str;
	while (*str && *str != '%')
		str++;
	len = str - start;
	ft_buffer_add(buf, start, len);
	*count += len;
	return (len);
}

static size_t	handle_specifier(t_specifier *spec,
	t_buffer *buf, va_list *list)
{
	static const t_handler	handlers[SPEC_SIZE] = {
		spec_none_handler,
		spec_percent_handler,
		spec_char_handler,
		spec_pointer_handler,
		spec_string_handler,
		spec_decimal_handler,
		spec_unsigned_handler,
		spec_hex_lowercase_handler,
		spec_hex_uppercase_handler
	};

	return (handlers[spec->specifier](spec, buf, list));
}

int	ft_printf(const char *format, ...)
{
	t_buffer	buffer;
	t_specifier	spec;
	va_list		args;
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	ft_init_buffer(&buffer, STDOUT_FILENO, 0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			i += handle_raw_string(format + i, &buffer, &count);
		else
		{
			i++;
			i += parse_specifier(format + i, &spec);
			count += handle_specifier(&spec, &buffer, &args);
		}
	}
	va_end(args);
	ft_flush_buffer(&buffer);
	return (count);
}
