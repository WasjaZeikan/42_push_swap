/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 23:34:16 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 15:47:21 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_ops.h"
#include "ft_buffer.h"
#include "libft.h"

#define QUADRATIC_STR "O(n\xC2\xB2)"
#define CHUNK_BASED_STR "O(n\xE2\x88\x9An)"
#define LOGARITHMIC_STR "O(nlogn)"

static void	add_counts(t_buffer *buf, t_counter *count)
{
	ft_buffer_add(buf, "\n[bench] sa: ", 13);
	ft_buffer_addi(buf, count->sa_count, DECIMAL);
	ft_buffer_add(buf, " sb: ", 5);
	ft_buffer_addi(buf, count->sb_count, DECIMAL);
	ft_buffer_add(buf, " ss: ", 5);
	ft_buffer_addi(buf, count->ss_count, DECIMAL);
	ft_buffer_add(buf, " pa: ", 5);
	ft_buffer_addi(buf, count->pa_count, DECIMAL);
	ft_buffer_add(buf, " pb: ", 5);
	ft_buffer_addi(buf, count->pb_count, DECIMAL);
	ft_buffer_add(buf, "\n[bench] ra: ", 13);
	ft_buffer_addi(buf, count->ra_count, DECIMAL);
	ft_buffer_add(buf, " rb: ", 5);
	ft_buffer_addi(buf, count->rb_count, DECIMAL);
	ft_buffer_add(buf, " rr: ", 5);
	ft_buffer_addi(buf, count->rr_count, DECIMAL);
	ft_buffer_add(buf, " rra: ", 6);
	ft_buffer_addi(buf, count->rra_count, DECIMAL);
	ft_buffer_add(buf, " rrb: ", 6);
	ft_buffer_addi(buf, count->rrb_count, DECIMAL);
	ft_buffer_add(buf, " rrr: ", 6);
	ft_buffer_addi(buf, count->rrr_count, DECIMAL);
}

static void	add_mode_name(t_buffer *buf, t_mode mode)
{
	static const t_string	mode_names[] = {
	{"Invalid", 7u},
	{"Adaptive", 8u},
	{"Simple", 6u},
	{"Medium", 6u},
	{"Complex", 7u}
	};

	ft_buffer_add(buf, mode_names[mode].str, mode_names[mode].len);
}

static void	add_complexity(t_buffer *buf, float disorder, t_mode mode)
{
	static const t_string	strings[] = {
	{QUADRATIC_STR, sizeof (QUADRATIC_STR) - 1},
	{CHUNK_BASED_STR, sizeof (CHUNK_BASED_STR) - 1},
	{LOGARITHMIC_STR, sizeof (LOGARITHMIC_STR) - 1}
	};
	t_complexity			comp;

	if (mode == SIMPLE)
		comp = QUADRATIC;
	else if (mode == MEDIUM)
		comp = CHUNK_BASED;
	else if (mode == COMPLEX)
		comp = LOGARITHMIC;
	else if (disorder < QUADRATIC_THRESHOLD)
		comp = QUADRATIC;
	else if (disorder <= CHUNK_BASED_THRESHOLD)
		comp = CHUNK_BASED;
	else
		comp = LOGARITHMIC;
	ft_buffer_add(buf, strings[comp].str, strings[comp].len);
}

static void	add_disorder(t_buffer *buf, float disorder)
{
	char	buffer[FTOA_BUFSIZE];
	char	*str;

	str = ft_ftoa(disorder * 100.0f, 2, buffer);
	ft_buffer_add(buf, str, ft_strlen(str));
}

void	ft_print_benchmark(t_app *app)
{
	t_buffer	buf;

	if (!ft_init_buffer(&buf, STDERR_FILENO, 256))
		return ;
	ft_buffer_add(&buf, "[bench] disorder: ", 18);
	add_disorder(&buf, app->disorder);
	ft_buffer_add(&buf, "%\n[bench] strategy: ", 20);
	add_mode_name(&buf, app->options.mode);
	ft_buffer_add(&buf, "/", 1);
	add_complexity(&buf, app->disorder, app->options.mode);
	ft_buffer_add(&buf, "\n[bench] total operations: ", 27);
	ft_buffer_addu(&buf, ft_total_ops_count(app), DECIMAL);
	add_counts(&buf, &app->counter);
	ft_buffer_add(&buf, "\n", 1);
	ft_flush_buffer(&buf);
}
