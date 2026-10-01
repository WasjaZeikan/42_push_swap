/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:24:17 by vzeikan           #+#    #+#             */
/*   Updated: 2026/08/23 20:42:40 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	t_byte	ch;
	t_byte	curr;

	ch = (t_byte) c;
	while (*s)
	{
		curr = (t_byte) * s;
		if (curr == ch)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	t_byte		ch;
	t_byte		curr;
	size_t		len;
	ptrdiff_t	i;

	len = ft_strlen(s);
	ch = (t_byte) c;
	i = len;
	while (i >= 0)
	{
		curr = (t_byte) s[i];
		if (curr == ch)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_byte	ch1;
	t_byte	ch2;
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		ch1 = (t_byte) s1[i];
		ch2 = (t_byte) s2[i];
		if (ch1 != ch2)
			return (ch1 - ch2);
		i++;
	}
	if (i == n)
		return (0);
	return ((t_byte) s1[i] - (t_byte) s2[i]);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && little[j] && little[j] == big[i + j])
			j++;
		if (little[j] == '\0')
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
