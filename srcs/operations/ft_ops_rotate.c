/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:33:05 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/28 19:30:02 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops.h"

void	op_ra(t_stack *a)
{
	if (stack_rotate(a))
		ft_handle_operation(OP_RA, a, NULL);
}

void	op_rb(t_stack *b)
{
	if (stack_rotate(b))
		ft_handle_operation(OP_RB, NULL, b);
}

void	op_rr(t_stack *a, t_stack *b)
{
	bool	result;

	result = stack_rotate(a);
	result |= stack_rotate(b);
	if (result)
		ft_handle_operation(OP_RR, a, b);
}
