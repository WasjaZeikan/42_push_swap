/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:40:14 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 15:39:55 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_ops.h"

static int	find_min_position(t_stack *stack)
{
	t_node	*node;
	int		min;
	int		min_pos;
	int		i;

	i = 0;
	node = stack->top;
	min = node->index;
	min_pos = 0;
	while (i < stack->size)
	{
		if (node->index < min)
		{
			min = node->index;
			min_pos = i;
		}
		node = node->next;
		i++;
	}
	return (min_pos);
}

static void	rotate_to_position(t_stack *stack, int pos)
{
	int	mid;

	mid = stack->size >> 1;
	if (pos < mid)
	{
		while (pos > 0)
		{
			pos--;
			op_ra(stack);
		}
	}
	else
	{
		while (pos < stack->size)
		{
			pos++;
			op_rra(stack);
		}
	}
}

void	ft_sort_simple(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 0)
	{
		pos = find_min_position(a);
		rotate_to_position(a, pos);
		op_pb(a, b);
	}
	while (b->size > 0)
		op_pa(a, b);
}
