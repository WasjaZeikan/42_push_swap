/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:10:56 by vzeikan           #+#    #+#             */
/*   Updated: 2026/08/20 23:55:15 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	s_len -= start;
	if (len > s_len)
		len = s_len;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}

static t_bool	ft_str_contains(const char *src, char ch)
{
	while (*src)
	{
		if (*src == ch)
			return (TRUE);
		src++;
	}
	return (FALSE);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	size_t	begin;
	size_t	end;
	char	*result;

	begin = 0;
	while (s1[begin] && ft_str_contains(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_str_contains(set, s1[end - 1]))
		end--;
	len = end - begin;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1 + begin, len);
	result[len] = '\0';
	return (result);
}
