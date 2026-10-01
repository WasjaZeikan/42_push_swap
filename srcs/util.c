/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:32:26 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 16:26:49 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_ops.h"
#include "libft.h"

float	ft_calc_disorder(int *values, int size)
{
	int		i;
	int		j;
	int		pairs;
	float	mistakes;

	if (size < 2)
		return (0);
	i = 0;
	pairs = 0;
	mistakes = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			pairs++;
			if (values[i] > values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / pairs);
}

size_t	ft_total_ops_count(t_app *app)
{
	t_counter	*counter;
	size_t		count;

	counter = &app->counter;
	count = (size_t) counter->pa_count;
	count += counter->pb_count + counter->ra_count;
	count += counter->rrb_count + counter->rrr_count + counter->rra_count;
	count += counter->rb_count + counter->rr_count + counter->sa_count;
	count += counter->sb_count + counter->ss_count;
	return (count);
}

void	ft_handle_operation(t_operation op, t_stack *a, t_stack *b)
{
	static const t_string	opnames[OP_SIZE] = {
	{"sa\n", 3},
	{"sb\n", 3},
	{"ss\n", 3},
	{"pa\n", 3},
	{"pb\n", 3},
	{"ra\n", 3},
	{"rb\n", 3},
	{"rr\n", 3},
	{"rra\n", 4},
	{"rrb\n", 4},
	{"rrr\n", 4}
	};
	int						*ops;
	t_app					*app;

	if (a)
		app = a->app;
	else
		app = b->app;
	ops = (int *) &app->counter;
	ops[op]++;
	write(STDOUT_FILENO, opnames[op].str, opnames[op].len);
}
