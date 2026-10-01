/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:28:35 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/28 19:32:01 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops.h"

void	op_sa(t_stack *a)
{
	if (stack_swap(a))
		ft_handle_operation(OP_SA, a, NULL);
}

void	op_sb(t_stack *b)
{
	if (stack_swap(b))
		ft_handle_operation(OP_SB, NULL, b);
}

void	op_ss(t_stack *a, t_stack *b)
{
	bool	result;

	result = stack_swap(a);
	result |= stack_swap(b);
	if (result)
		ft_handle_operation(OP_SS, a, b);
}
