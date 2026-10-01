/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:36:42 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 18:01:14 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "libft.h"

static void	sort_ints(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	*copy_and_sort(const int *values, int size)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	ft_memcpy(sorted, values, sizeof(int) * size);
	sort_ints(sorted, size);
	return (sorted);
}

static bool	has_duplicates(const int *sorted, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (sorted[i] == sorted[i - 1])
			return (true);
		i++;
	}
	return (false);
}

static int	find_rank(int value, const int *sorted, int size)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (sorted[mid] == value)
			return (mid);
		if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

int	*ft_compress_ranks(const int *values, int size)
{
	int	*sorted;
	int	*ranks;
	int	i;

	sorted = copy_and_sort(values, size);
	if (!sorted || has_duplicates(sorted, size))
	{
		free(sorted);
		return (NULL);
	}
	ranks = malloc(sizeof (int) * size);
	if (!ranks)
	{
		free(sorted);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		ranks[i] = find_rank(values[i], sorted, size);
		i++;
	}
	free(sorted);
	return (ranks);
}
