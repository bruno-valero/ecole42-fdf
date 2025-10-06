/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:26:02 by valero            #+#    #+#             */
/*   Updated: 2025/10/06 19:45:20 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_lines.h"

static void				build_line_right(
							t_frame_context frame,
							void (*update_line)
							(t_frame_context frame, t_line *curr_line),
							int *line_idx);
static void				build_line_down(
							t_frame_context frame,
							void (*update_line)
							(t_frame_context frame, t_line *curr_line),
							int *line_idx);
static int				get_lines_amount(t_parser_matrix *mtx);
static t_lines			*lines_init(t_lines *lines,
							t_parser_matrix *mtx,
							t_viewer_context viwer_context);

t_lines	build_lines(t_parser_matrix	*mtx,
			t_viewer_context viwer_context, t_camera *camera,
			void (*update_line)(t_frame_context frame, t_line *curr_line)
			)
{
	t_coord_2d		mtx_coord;
	t_lines			lines;
	t_frame_context	frame;
	int				line_idx;

	lines_init(&lines, mtx, viwer_context);
	line_idx = 0;
	mtx_coord.y = -1;
	while (mtx->data[++mtx_coord.y])
	{
		mtx_coord.x = -1;
		while (++mtx_coord.x < mtx->width)
		{
			frame = frame_context(mtx, mtx_coord, &lines, camera);
			build_line_right(frame, update_line, &line_idx);
			build_line_down(frame, update_line, &line_idx);
		}
	}
	return (lines);
}

static void	build_line_right(
				t_frame_context frame,
				void (*update_line)(t_frame_context frame, t_line *curr_line),
				int *line_idx)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;
	t_input_point	initial_point;
	t_input_point	final_point;

	curr_x = frame.curr_coord.x;
	curr_y = frame.curr_coord.y;
	if (frame.curr_coord.x + 1 < frame.mtx->width)
	{
		initial_point = frame.mtx->data[curr_y][curr_x];
		final_point = frame.mtx->data[curr_y][curr_x + 1];
		curr_line = new_line(
				colorize_point(initial_point),
				colorize_point(final_point)
				);
		update_line(frame, &curr_line);
		frame.lines->data[(*line_idx)++] = new_line(
				curr_line.initial_point, curr_line.final_point);
	}
}

static void	build_line_down(
				t_frame_context frame,
				void (*update_line)(t_frame_context frame, t_line *curr_line),
				int *line_idx)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;
	t_input_point	initial_point;
	t_input_point	final_point;

	curr_x = frame.curr_coord.x;
	curr_y = frame.curr_coord.y;
	if (frame.mtx->data[frame.curr_coord.y + 1])
	{
		initial_point = frame.mtx->data[curr_y][curr_x];
		final_point = frame.mtx->data[curr_y + 1][curr_x];
		curr_line = new_line(
				colorize_point(initial_point),
				colorize_point(final_point)
				);
		update_line(frame, &curr_line);
		frame.lines->data[(*line_idx)++] = new_line(
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

static t_lines	*lines_init(t_lines *lines, t_parser_matrix *mtx,
					t_viewer_context viwer_context)
{
	int					i;

	lines->size = get_lines_amount(mtx);
	lines->data = (t_line *)malloc(lines->size * sizeof(t_line));
	i = -1;
	while (++i < lines->size)
		lines->data[i] = new_line(new_colorized_point(), new_colorized_point());
	lines->layer = viwer_context.layer;
	lines->window = viwer_context.window;
	return (lines);
}
