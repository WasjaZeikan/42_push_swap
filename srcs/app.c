/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:05:37 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/30 22:20:26 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_ops.h"

static void	init_counter(t_counter *counter)
{
	counter->pa_count = 0;
	counter->pb_count = 0;
	counter->sa_count = 0;
	counter->sb_count = 0;
	counter->ss_count = 0;
	counter->ra_count = 0;
	counter->rb_count = 0;
	counter->rr_count = 0;
	counter->rra_count = 0;
	counter->rrb_count = 0;
	counter->rrr_count = 0;
}

static bool	cleanup_return(int *values, int *ranks)
{
	free(values);
	free(ranks);
	return (false);
}

bool	ft_init_app(t_app	*app, int argc, char **argv)
{
	int	*ranks;
	int	*values;
	int	size;

	if (!ft_parse_args(app, argc, argv))
		return (false);
	values = app->values;
	size = app->size;
	ranks = ft_compress_ranks(values, size);
	if (!ranks)
		return (cleanup_return(values, NULL));
	if (!init_stack(&app->stack_a, values, ranks, size))
		return (cleanup_return(values, ranks));
	app->ranks = ranks;
	app->stack_b.size = 0;
	app->stack_a.app = app;
	app->stack_b.app = app;
	init_counter(&app->counter);
	app->disorder = ft_calc_disorder(values, size);
	return (true);
}

void	ft_free_app(t_app	*app)
{
	if (!app)
		return ;
	free(app->values);
	free(app->ranks);
	free_stack(&app->stack_a);
	free_stack(&app->stack_b);
}
