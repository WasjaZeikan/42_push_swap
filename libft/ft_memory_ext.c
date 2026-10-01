/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:48:12 by vzeikan           #+#    #+#             */
/*   Updated: 2026/08/26 21:52:23 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_bzero(void *dest, size_t count)
{
	ft_memset(dest, 0, count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	size -= dst_len;
	while (i + 1 < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(src);
	copy = malloc((len + 1) * sizeof (char));
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, src, len);
	copy[len] = '\0';
	return (copy);
}

void	*ft_calloc(size_t count, size_t size)
{
	t_byte	*b;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	size = size * count * sizeof (t_byte);
	if (size == 0)
		size = 1;
	b = malloc(size);
	if (b == NULL)
		return (NULL);
	ft_memset(b, 0, size);
	return (b);
}
