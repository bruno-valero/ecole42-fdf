/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:26:02 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 15:10:16 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_lines.h"

static void	build_line_right(t_lines *lines, t_coord_2d curr_coord,
				int *line_idx, t_state *state);
static void	build_line_down(t_lines *lines, t_coord_2d curr_coord,
				int *line_idx, t_state *state);
static int	get_lines_amount(t_parser_matrix *mtx);

void	build_lines(t_state *state, t_lines *lines)
{
	t_coord_2d		mtx_coord;
	int				line_idx;

	line_idx = 0;
	mtx_coord.y = -1;
	while (state->parsed_data->data[++mtx_coord.y])
	{
		mtx_coord.x = -1;
		while (++mtx_coord.x < state->parsed_data->width)
		{
			build_line_right(lines, mtx_coord, &line_idx, state);
			build_line_down(lines, mtx_coord, &line_idx, state);
		}
	}
}

static void	build_line_right(
				t_lines *lines,
				t_coord_2d curr_coord,
				int *line_idx, t_state *state)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;
	t_input_point	start_point;
	t_input_point	end_point;

	curr_x = curr_coord.x;
	curr_y = curr_coord.y;
	if (curr_coord.x + 1 < state->parsed_data->width)
	{
		start_point = state->parsed_data->data[curr_y][curr_x];
		end_point = state->parsed_data->data[curr_y][curr_x + 1];
		curr_line = new_line(
				colorize_point(start_point),
				colorize_point(end_point)
				);
		update_line(&curr_line);
		lines->data[(*line_idx)++] = new_line(
				curr_line.initial_point, curr_line.final_point);
	}
}

static void	build_line_down(
				t_lines *lines,
				t_coord_2d curr_coord,
				int *line_idx, t_state *state)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;
	t_input_point	initial_point;
	t_input_point	final_point;

	curr_x = curr_coord.x;
	curr_y = curr_coord.y;
	if (state->parsed_data->data[curr_coord.y + 1])
	{
		initial_point = state->parsed_data->data[curr_y][curr_x];
		final_point = state->parsed_data->data[curr_y + 1][curr_x];
		curr_line = new_line(
				colorize_point(initial_point),
				colorize_point(final_point)
				);
		update_line(&curr_line);
		lines->data[(*line_idx)++] = new_line(
				curr_line.initial_point, curr_line.final_point);
	}
}

static int	get_lines_amount(t_parser_matrix *mtx)
{
	int	total_points;
	int	total_lines;

	total_points = mtx->width * mtx->height;
	total_lines = total_points * 2 - mtx->width - mtx->height;
	return (total_lines);
}

t_lines	*lines_init(t_lines *lines, t_state *state)
{
	int					i;
	t_viewer_context	viwer_context;
	t_parser_matrix		*mtx;

	viwer_context = state->viewer_context;
	mtx = state->parsed_data;
	lines->size = get_lines_amount(mtx);
	lines->data = (t_line *)malloc(lines->size * sizeof(t_line));
	if (!lines->data)
		return (NULL);
	i = -1;
	while (++i < lines->size)
		lines->data[i] = new_line(new_colorized_point(), new_colorized_point());
	lines->layer = viwer_context.wireframe;
	lines->window = viwer_context.window;
	return (lines);
}
