/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:58:34 by vzeikan           #+#    #+#             */
/*   Updated: 2026/08/27 10:52:43 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef FT_BUFFER_SIZE
#  define FT_BUFFER_SIZE 256
# endif

typedef unsigned char	t_byte;

# ifndef FT_BUFFER_DYNAMIC

struct s_buffer
{
	t_byte	buf[FT_BUFFER_SIZE];
	size_t	capacity;
	size_t	pos;
	int		fd;
};

# else

struct s_buffer
{
	t_byte	*buf;
	size_t	capacity;
	size_t	pos;
	int		fd;
};

# endif

typedef struct s_buffer	t_buffer;

t_buffer	*ft_init_buffer(t_buffer *buffer, int fd, size_t buffer_size);
void		ft_free_buffer(t_buffer *buffer, bool is_allocated);
void		ft_flush_buffer(t_buffer *buffer);
bool		ft_buffer_add(t_buffer *buffer, const void *buf, size_t len);
bool		ft_buffer_addi(t_buffer *buf, int64_t number, const char *base);
bool		ft_buffer_addu(t_buffer *buf, uint64_t number, const char *base);
bool		ft_buffer_addc(t_buffer *buffer, char ch, size_t count);
#endif