/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:15:09 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 22:18:58 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "libft.h"

#ifndef FT_BUFFER_DYNAMIC

t_buffer	*ft_init_buffer(t_buffer *buffer, int fd, size_t buffer_size)
{
	if (!buffer)
	{
		buffer = malloc(sizeof (t_buffer));
		if (buffer == NULL)
			return (NULL);
	}
	buffer->pos = 0;
	buffer->fd = fd;
	buffer->capacity = FT_BUFFER_SIZE;
	(void) buffer_size;
	return (buffer);
}

void	ft_free_buffer(t_buffer *buffer, bool is_allocated)
{
	if (is_allocated)
		free(buffer);
}
#else

t_buffer	*ft_init_buffer(t_buffer *buffer, int fd, size_t buffer_size)
{
	t_bool	is_allocated;

	is_allocated = FALSE;
	if (!buffer)
	{
		buffer = malloc(sizeof (t_buffer));
		if (buffer == NULL)
			return (NULL);
		is_allocated = TRUE;
	}
	buffer->pos = 0;
	buffer->fd = fd;
	buffer->capacity = buffer_size;
	buffer->buf = malloc(buffer_size);
	if (buffer->buf == NULL)
	{
		if (is_allocated)
			free(buffer);
		return (NULL);
	}
	return (buffer);
}

void	ft_free_buffer(t_buffer *buffer, bool is_allocated)
{
	if (!buffer)
		return ;
	free(buffer->buf);
	if (is_allocated)
		free(buffer);
}

#endif

void	ft_flush_buffer(t_buffer *buffer)
{
	if (!buffer)
		return ;
	write(buffer->fd, buffer->buf, buffer->pos);
	buffer->pos = 0;
}
