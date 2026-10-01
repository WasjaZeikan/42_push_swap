/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:30:54 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/29 19:14:25 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	free_stack(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*next;

	i = 0;
	node = stack->top;
	while (i < stack->size)
	{
		next = node->next;
		free(node);
		node = next;
		i++;
	}
	stack->size = 0;
}

static void	stack_insert(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	node->prev = stack->top->prev;
	stack->top->prev->next = node;
	stack->top->prev = node;
	stack->top = node;
	stack->size++;
}

static t_node	*new_node(int value, int rank)
{
	t_node	*node;

	node = malloc(sizeof (t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = rank;
	return (node);
}

bool	init_stack(t_stack *stack, int *values, int *ranks, int size)
{
	t_node	*node;

	size--;
	node = new_node(values[size], ranks[size]);
	if (!node)
		return (false);
	node->next = node;
	node->prev = node;
	stack->top = node;
	stack->size = 1;
	while (size > 0)
	{
		size--;
		node = new_node(values[size], ranks[size]);
		if (!node)
		{
			free_stack(stack);
			return (false);
		}
		stack_insert(stack, node);
	}
	return (true);
}
