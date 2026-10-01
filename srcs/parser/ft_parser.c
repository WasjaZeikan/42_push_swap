/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:54:12 by vzeikan           #+#    #+#             */
/*   Updated: 2026/09/30 20:59:01 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "libft.h"

static bool	arg_equal(const char *arg, const char *target)
{
	size_t	i;

	i = 0;
	while (arg[i] && target[i] && arg[i] == target[i])
		i++;
	return (arg[i] == '\0' && target[i] == '\0');
}

static t_mode	parse_mode(const char *arg)
{
	if (arg_equal(arg, "--simple"))
		return (SIMPLE);
	if (arg_equal(arg, "--medium"))
		return (MEDIUM);
	if (arg_equal(arg, "--complex"))
		return (COMPLEX);
	if (arg_equal(arg, "--adaptive"))
		return (ADAPTIVE);
	return (INVALID);
}

static bool	handle_options(int *argc, char ***argv, t_options *opts)
{
	t_mode	mode;
	bool	has_mode;
	int		i;

	opts->mode = ADAPTIVE;
	opts->benchmark = false;
	has_mode = false;
	i = 1;
	while (i < *argc && (*argv)[i][0] == '-')
	{
		if (arg_equal((*argv)[i], "--bench"))
			opts->benchmark = true;
		else
		{
			mode = parse_mode((*argv)[i]);
			if (mode == INVALID || has_mode)
				return (false);
			opts->mode = mode;
			has_mode = true;
		}
		i++;
	}
	*argc -= i;
	*argv += i;
	return (true);
}

bool	ft_parse_args(t_app *app, int argc, char **argv)
{
	int		size;
	int		*values;

	if (!handle_options(&argc, &argv, &app->options))
		return (false);
	size = ft_count_numbers(argc, argv);
	if (size < 0)
		return (false);
	values = malloc(size * sizeof (int));
	if (!values || !ft_parse_values(values, argc, argv))
	{
		free(values);
		return (false);
	}
	app->values = values;
	app->size = size;
	return (true);
}
