/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:30:51 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/28 15:40:19 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

bool	stack_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (false);
	stack->top = stack->top->next;
	return (true);
}

bool	stack_reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (false);
	stack->top = stack->top->prev;
	return (true);
}
