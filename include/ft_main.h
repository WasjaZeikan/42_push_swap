/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:44:45 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 15:51:50 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H
# include "ft_stack.h"
# include <stdbool.h>

# define QUADRATIC_THRESHOLD 0.2f
# define CHUNK_BASED_THRESHOLD 0.5f

typedef enum e_mode
{
	INVALID = 0,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_mode;

typedef enum e_complexity
{
	QUADRATIC = 0,
	CHUNK_BASED,
	LOGARITHMIC
}	t_complexity;

typedef struct s_options
{
	t_mode	mode;
	bool	benchmark;
}	t_options;

typedef struct s_counter
{
	int	sa_count;
	int	sb_count;
	int	ss_count;
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
	int	rr_count;
	int	rra_count;
	int	rrb_count;
	int	rrr_count;
}	t_counter;

typedef struct s_string
{
	const char		*str;
	unsigned int	len;
}	t_string;

typedef struct s_app
{
	t_counter		counter;
	t_stack			stack_a;
	t_stack			stack_b;
	t_options		options;
	int				*values;
	int				*ranks;
	int				size;
	float			disorder;
}	t_app;

float	ft_calc_disorder(int *values, int size);
bool	ft_init_app(t_app *app, int argc, char **argv);
void	ft_free_app(t_app *app);
bool	ft_parse_args(t_app *app, int argc, char **argv);
int		ft_count_numbers(int argc, char **argv);
bool	ft_parse_values(int *values, int argc, char **argv);
int		*ft_compress_ranks(const int *values, int size);
size_t	ft_total_ops_count(t_app *app);
void	ft_print_benchmark(t_app *app);
void	ft_sort_simple(t_stack *a, t_stack *b);
void	ft_sort_chunks(t_stack *a, t_stack *b);
void	ft_sort_radix(t_stack *a, t_stack *b);
void	ft_sort_adaptive(t_stack *a, t_stack *b);
#endif