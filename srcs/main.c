/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:35:53 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/07 19:31:04 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_ops.h"
#define SIMPLE_THRESHOLD 10

static void	sort_stacks(t_stack *a, t_stack *b, t_mode mode)
{
	if (a->size < 2)
		return ;
	if (mode == SIMPLE)
		ft_sort_simple(a, b);
	else if (mode == MEDIUM)
		ft_sort_chunks(a, b);
	else if (mode == COMPLEX)
		ft_sort_radix(a, b);
	else if (a->size <= SIMPLE_THRESHOLD)
		ft_sort_simple(a, b);
	else
		ft_sort_adaptive(a, b);
}

int	main(int argc, char *argv[])
{
	t_app	app;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!ft_init_app(&app, argc, argv))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	a = &app.stack_a;
	b = &app.stack_b;
	if (app.disorder > 0.0f)
		sort_stacks(a, b, app.options.mode);
	if (app.options.benchmark)
		ft_print_benchmark(&app);
	ft_free_app(&app);
	return (0);
}
