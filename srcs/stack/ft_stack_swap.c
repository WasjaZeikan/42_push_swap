/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:30:56 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 18:44:06 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	swap_nodes(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

bool	stack_swap(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (false);
	swap_nodes(stack->top, stack->top->next);
	return (true);
}
