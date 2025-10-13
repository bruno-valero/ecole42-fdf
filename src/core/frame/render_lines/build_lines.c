/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:26:02 by valero            #+#    #+#             */
/*   Updated: 2025/10/13 02:08:15 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_lines.h"

static void	build_line(
				t_state *state,
				t_input_point start_point,
				t_input_point end_point);
static int	get_lines_amount(t_parser_matrix *mtx);

void	build_lines(t_state *state)
{
	t_coord_2d		mtx_coord;
	t_input_point	**matrix;

	matrix = state->parsed_data->data;
	mtx_coord.y = 0;
	while (matrix[mtx_coord.y])
	{
		mtx_coord.x = 0;
		while (mtx_coord.x < state->parsed_data->width)
		{
			if (mtx_coord.x + 1 < state->parsed_data->width)
				build_line(
					state,
					matrix[mtx_coord.y][mtx_coord.x],
					matrix[mtx_coord.y][mtx_coord.x + 1]);
			if (state->parsed_data->data[mtx_coord.y + 1])
				build_line(
					state,
					matrix[mtx_coord.y][mtx_coord.x],
					matrix[mtx_coord.y + 1][mtx_coord.x]);
			mtx_coord.x += state->modes.resolution;
		}
		mtx_coord.y += state->modes.resolution;
	}
}

static void	build_line(
		t_state *state,
		t_input_point start_point,
		t_input_point end_point)
{
	t_line			line;

	line = new_line(
			update_point(state, start_point),
			update_point(state, end_point));
	draw_line(line, state->viewer_context, bresenham);
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
	t_viewer_context	viwer_context;
	t_parser_matrix		*mtx;

	viwer_context = state->viewer_context;
	mtx = state->parsed_data;
	lines->size = get_lines_amount(mtx);
	lines->data = (t_line *)ft_calloc(lines->size, sizeof(t_line));
	if (!lines->data)
		return (NULL);
	lines->layer = viwer_context.wireframe;
	lines->window = viwer_context.window;
	return (lines);
}
