/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:46:23 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:19:16 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_printf.h"
#include "libft.h"

#define FT_BUFFER_CHAR_SIZE 64

bool	ft_buffer_addi(t_buffer *buf, int64_t number, const char *base)
{
	char	buffer[MAX_DIGIT_COUNT];
	char	*str;

	if (!buf)
		return (false);
	str = ft_itoa_base(number, base, buffer);
	return (ft_buffer_add(buf, str, ft_strlen(str)));
}

bool	ft_buffer_addu(t_buffer *buf, uint64_t number, const char *base)
{
	char	buffer[MAX_DIGIT_COUNT];
	char	*str;

	if (!buf)
		return (false);
	str = ft_utoa_base(number, base, buffer);
	return (ft_buffer_add(buf, str, ft_strlen(str)));
}

bool	ft_buffer_addc(t_buffer *buffer, char ch, size_t count)
{
	char	str[FT_BUFFER_CHAR_SIZE];
	bool	result;

	if (!buffer || count == 0)
		return (false);
	ft_memset(str, ch, sizeof (str));
	result = false;
	while (count >= FT_BUFFER_CHAR_SIZE)
	{
		result |= ft_buffer_add(buffer, str, FT_BUFFER_CHAR_SIZE);
		count -= FT_BUFFER_CHAR_SIZE;
	}
	if (count > 0)
		result |= ft_buffer_add(buffer, str, count);
	return (result);
}

bool	ft_buffer_add(t_buffer *buffer, const void *buf, size_t len)
{
	if (!buffer || !buf || len == 0)
		return (false);
	if (len > buffer->capacity)
	{
		ft_flush_buffer(buffer);
		write(buffer->fd, buf, len);
		return (true);
	}
	if (buffer->pos + len > buffer->capacity)
	{
		ft_flush_buffer(buffer);
		ft_memcpy(buffer->buf, buf, len);
		buffer->pos = len;
		return (true);
	}
	ft_memcpy(buffer->buf + buffer->pos, buf, len);
	buffer->pos += len;
	return (false);
}
