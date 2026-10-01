/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 21:18:13 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 15:19:49 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

void	ft_sort_adaptive(t_stack *a, t_stack *b)
{
	float	disorder;

	disorder = a->app->disorder;
	if (disorder < QUADRATIC_THRESHOLD)
		ft_sort_simple(a, b);
	else if (disorder < CHUNK_BASED_THRESHOLD)
		ft_sort_chunks(a, b);
	else
		ft_sort_radix(a, b);
}
