/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:40:47 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/30 23:06:28 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_ops.h"

static void	radix_pass(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			op_pb(a, b);
		else
			op_ra(a);
		i++;
	}
	while (b->size > 0)
		op_pa(a, b);
}

void	ft_sort_radix(t_stack *a, t_stack *b)
{
	int	max_index;
	int	max_bits;
	int	bit;

	max_index = a->size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit);
		bit++;
	}
}
