/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:33:02 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/28 19:31:08 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops.h"

void	op_rra(t_stack *a)
{
	if (stack_reverse_rotate(a))
		ft_handle_operation(OP_RRA, a, NULL);
}

void	op_rrb(t_stack *b)
{
	if (stack_reverse_rotate(b))
		ft_handle_operation(OP_RRB, NULL, b);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	bool	result;

	result = stack_reverse_rotate(a);
	result |= stack_reverse_rotate(b);
	if (result)
		ft_handle_operation(OP_RRR, a, b);
}
