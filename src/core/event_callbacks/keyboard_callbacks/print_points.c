/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:43:11 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 13:04:49 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_callbacks.h"

#include "build_lines.h"
# include <stdio.h>

static void	test_build_line_right(t_state *state, t_coord_2d curr_coord,
				int *line_idx);
static void	test_build_line_down(t_state *state, t_coord_2d curr_coord,
				int *line_idx);

void	test_build_lines(t_state *state)
{
	t_coord_2d		mtx_coord;
	int				line_idx;

	printf("\n\nprintiing logs...\n");
	line_idx = 0;
	mtx_coord.y = -1;
	while (state->parsed_data->data[++mtx_coord.y])
	{
		mtx_coord.x = -1;
		while (++mtx_coord.x < state->parsed_data->width)
		{
			test_build_line_right(state, mtx_coord, &line_idx);
			test_build_line_down(state, mtx_coord, &line_idx);
		}
	}
}

static void	test_build_line_right(
				t_state *state,
				t_coord_2d curr_coord,
				int *line_idx)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;
	t_input_point	start_point;
	t_input_point	end_point;

	(void)line_idx;
	curr_x = curr_coord.x;
	curr_y = curr_coord.y;
	if (curr_coord.x + 1 < state->parsed_data->width)
	{
		start_point = state->parsed_data->data[curr_y][curr_x];
		end_point = state->parsed_data->data[curr_y][curr_x + 1];
		curr_line = new_line(
				colorize_point(state, start_point),
				colorize_point(state, end_point)
				);
		update_line(state, &curr_line);
		printf("%d point - right: init_point(%d, %d), fin_point(%d, %d)\n", curr_y + curr_x + 1, curr_line.initial_point.x, curr_line.initial_point.y, curr_line.final_point.x, curr_line.final_point.y);
	}
}

static void	test_build_line_down(
				t_state *state,
				t_coord_2d curr_coord,
				int *line_idx)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;
	t_input_point	initial_point;
	t_input_point	final_point;

	(void)line_idx;
	curr_x = curr_coord.x;
	curr_y = curr_coord.y;
	if (state->parsed_data->data[curr_coord.y + 1])
	{
		initial_point = state->parsed_data->data[curr_y][curr_x];
		final_point = state->parsed_data->data[curr_y + 1][curr_x];
		curr_line = new_line(
				colorize_point(state, initial_point),
				colorize_point(state, final_point)
				);
		update_line(state, &curr_line);
		printf("%d point - down: init_point(%d, %d), fin_point(%d, %d)\n",curr_y + curr_x + 1, curr_line.initial_point.x, curr_line.initial_point.y, curr_line.final_point.x, curr_line.final_point.y);
	}
}

void	print_points(t_state *state)
{
	test_build_lines(state);
}
