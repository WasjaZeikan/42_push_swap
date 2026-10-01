/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 22:06:04 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:40:00 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_buffer.h"
# include "libft.h"
# include <stdarg.h>

typedef enum e_spec
{
	SPEC_NONE,
	SPEC_PERCENT,
	SPEC_CHAR,
	SPEC_POINTER,
	SPEC_STRING,
	SPEC_DECIMAL,
	SPEC_UNSIGNED,
	SPEC_HEX_LOWERCASE,
	SPEC_HEX_UPPERCASE,
	SPEC_SIZE
}	t_spec;

struct s_specifier
{
	t_uint	width;
	int		precision;
	t_spec	specifier;
	char	number_prefix;
	char	pad_character;
	char	pad_digit;
	char	is_alternative_form : 1;
	char	is_left_adjusted : 1;
	char	is_zero_padded : 1;
};
typedef struct s_specifier	t_specifier;
typedef size_t				(*t_handler)(t_specifier *, t_buffer *, va_list *);

typedef struct s_ntoa_buf
{
	const char	*str;
	t_uint		len;
	t_uint		prefix_len;
}	t_ntoa_buf;

int		ft_printf(const char *format, ...);
size_t	parse_specifier(const char *str, t_specifier *spec);
size_t	spec_none_handler(t_specifier *spec, t_buffer *buf, va_list *args);
size_t	spec_percent_handler(t_specifier *spec, t_buffer *buf, va_list *args);
size_t	spec_char_handler(t_specifier *spec, t_buffer *buf, va_list *args);
size_t	spec_pointer_handler(t_specifier *spec, t_buffer *buf, va_list *args);
size_t	spec_string_handler(t_specifier *spec, t_buffer *buf, va_list *args);
size_t	spec_decimal_handler(t_specifier *spec, t_buffer *buf, va_list *args);
size_t	spec_unsigned_handler(t_specifier *spec, t_buffer *buf, va_list *args);
size_t	spec_hex_lowercase_handler(t_specifier *spec,
			t_buffer *buf, va_list *args);
size_t	spec_hex_uppercase_handler(t_specifier *spec,
			t_buffer *buf, va_list *args);

size_t	ft_buffer_add_justified(const char *str, size_t len,
			t_specifier *spec, t_buffer *buf);

size_t	ft_buffer_addn_justified(const t_ntoa_buf *num_buf,
			t_specifier *spec, t_buffer *buf);

#endif