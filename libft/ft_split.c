/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:01:12 by vzeikan           #+#    #+#             */
/*   Updated: 2026/08/23 20:40:15 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char ch)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == ch)
			s++;
		if (*s == '\0')
			break ;
		count++;
		while (*s && *s != ch)
			s++;
	}
	return (count);
}

static size_t	ft_next_str(const char *s, size_t i, char ch, char **result)
{
	size_t	start;

	while (s[i] && s[i] == ch)
		i++;
	start = i;
	while (s[i] && s[i] != ch)
		i++;
	*result = ft_substr(s, start, i - start);
	return (i);
}

static void	ft_free_array(char	**arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;
	char	**result;

	count = ft_count_words(s, c);
	result = ft_calloc(count + 1, sizeof (char *));
	i = 0;
	j = 0;
	while (j < count)
	{
		i = ft_next_str(s, i, c, result + j);
		if (result[j] == NULL)
		{
			ft_free_array(result, j);
			return (NULL);
		}
		j++;
	}
	return (result);
}
