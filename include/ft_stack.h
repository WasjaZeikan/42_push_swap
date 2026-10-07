/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:50:07 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/07 13:04:42 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
struct	s_app;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_app	*app;
	t_node			*top;
	int				size;
}	t_stack;

bool	init_stack(t_stack *stack, int *values, int *ranks, int size);
void	free_stack(t_stack *stack);
bool	stack_push(t_stack *from, t_stack *to);
bool	stack_swap(t_stack *stack);
bool	stack_rotate(t_stack *stack);
bool	stack_reverse_rotate(t_stack *stack);
#endif