/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:40:11 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 16:07:17 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_ops.h"

static int	find_max_position(t_stack *stack)
{
	t_node	*node;
	int		max;
	int		pos;
	int		max_pos;

	node = stack->top;
	max = node->index;
	pos = 0;
	max_pos = 0;
	while (pos < stack->size)
	{
		if (node->index > max)
		{
			max = node->index;
			max_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_max_to_top(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			op_rb(b);
	}
	else
	{
		while (pos++ < b->size)
			op_rrb(b);
	}
}

static void	push_chunk(t_stack *a, t_stack *b, int start, int end)
{
	int	target;
	int	pushed;
	int	mid;

	target = end - start + 1;
	pushed = 0;
	mid = start + (end - start) / 2;
	while (pushed < target)
	{
		if (a->top->index >= start && a->top->index <= end)
		{
			op_pb(a, b);
			if (b->top->index < mid)
				op_rb(b);
			pushed++;
		}
		else
			op_ra(a);
	}
}

static int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

void	ft_sort_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	start;
	int	end;
	int	pos;
	int	size;

	size = a->size;
	chunk_size = get_chunk_size(size);
	start = 0;
	while (start < size)
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		push_chunk(a, b, start, end);
		start = end + 1;
	}
	while (b->size > 0)
	{
		pos = find_max_position(b);
		rotate_max_to_top(b, pos);
		op_pa(a, b);
	}
}
