/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:33:08 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 16:41:44 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops.h"

void	op_pa(t_stack *a, t_stack *b)
{
	if (stack_push(b, a))
		ft_handle_operation(OP_PA, a, b);
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (stack_push(a, b))
		ft_handle_operation(OP_PB, a, b);
}
