/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:26:02 by valero            #+#    #+#             */
/*   Updated: 2025/10/01 22:08:36 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_lines.h"

static void				build_line_right(
							t_frame_context frame,
							void (*update_line)
							(t_frame_context frame, t_line curr_line),
							int *line_idx);
static void				build_line_down(
							t_frame_context frame,
							void (*update_line)
							(t_frame_context frame, t_line curr_line),
							int *line_idx);
static t_coord_2d		coord_3d_to_2d(t_coord_3d coord);
static void				scale_point(t_coord_2d *coord, int scale);
static void				set_position(t_coord_2d *coord,
							t_parser_matrix *mtx,
							int scale, t_minilib_window window);
static int				get_lines_amount(t_parser_matrix *mtx);
static t_lines			*lines_init(t_lines *lines,
							t_parser_matrix *mtx,
							t_viewer_context viwer_context);
static t_frame_context	frame_context(
							t_parser_matrix *mtx, t_coord_2d curr_coord,
							t_lines *lines, t_camera *camera);

t_lines	build_lines(
			char *file_path, t_viewer_context viwer_context, t_camera *camera,
			void (*update_line)(t_frame_context frame)
			)
{
	t_parser_matrix	*mtx;
	t_coord_2d		mtx_coord;
	t_lines			lines;
	t_frame_context	frame;
	int				line_idx;

	if (!parse_file(file_path, &mtx))
		return ;
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
	mtx->destroy(mtx);
	return (lines);
}

static void	build_line_right(
				t_frame_context frame,
				void (*update_line)(t_frame_context frame, t_line curr_line),
				int *line_idx)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;

	curr_x = frame.curr_coord.x;
	curr_y = frame.curr_coord.y;
	if (frame.curr_coord.x + 1 < frame.mtx->width)
	{
		curr_line = new_line(
				coord_3d_to_2d(frame.mtx->data[curr_y][curr_x].coord),
				coord_3d_to_2d(frame.mtx->data[curr_y + 1][curr_x].coord)
				);
		update_line(frame, curr_line);
		// scale_point(&start, frame.camera->scale);
		// scale_point(&end, frame.camera->scale);
		// set_position(&start, frame.mtx, frame.camera->scale, frame.lines->window);
		// set_position(&end, frame.mtx, frame.camera->scale, frame.lines->window);
		frame.lines->data[(*line_idx)++] = new_line(
				curr_line.initial_point, curr_line.final_point);
	}
}

static void	build_line_down(
				t_frame_context frame,
				void (*update_line)(t_frame_context frame, t_line curr_line),
				int *line_idx)
{
	t_line			curr_line;
	int				curr_x;
	int				curr_y;

	curr_x = frame.curr_coord.x;
	curr_y = frame.curr_coord.y;
	if (frame.mtx->data[frame.curr_coord.y + 1])
	{
		curr_line = new_line(
				coord_3d_to_2d(frame.mtx->data[curr_y][curr_x].coord),
				coord_3d_to_2d(frame.mtx->data[curr_y + 1][curr_x].coord)
				);
		update_line(frame, curr_line);
		// scale_point(&start, frame.camera->scale);
		// scale_point(&end, frame.camera->scale);
		// set_position(&start, frame.mtx, frame.camera->scale, frame.lines->window);
		// set_position(&end, frame.mtx, frame.camera->scale, frame.lines->window);
		frame.lines->data[(*line_idx)++] = new_line(
				curr_line.initial_point, curr_line.final_point);
	}
}

static t_coord_2d	coord_3d_to_2d(t_coord_3d coord)
{
	t_coord_2d	new_coord;

	new_coord = coord_2d(coord.x, coord.y);
	return (new_coord);
}

static void	scale_point(t_coord_2d *coord, int scale)
{
	coord->x *= scale;
	coord->y *= scale;
}

static void	set_position(t_coord_2d *coord, t_parser_matrix *mtx, int scale, t_minilib_window window)
{
	t_coord_2d	center_matrix;
	t_coord_2d	center_window;
	t_coord_2d	offset;

	center_matrix.x = (mtx->width - 1) * scale / 2;
	center_matrix.y = (mtx->height - 1) * scale / 2;
	center_window.x = window.width / 2;
	center_window.y = window.height / 2;
	offset.x = center_window.x - center_matrix.x;
	offset.y = center_window.y - center_matrix.y;
	coord->x += offset.x;
	coord->y += offset.y;
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
	lines->data = (t_line *)malloc(lines->size);
	i = -1;
	while (++i < lines->size)
		lines->data[i] = new_line(coord_2d(0, 0), coord_2d(0, 0));
	lines->layer = viwer_context.layer;
	lines->window = viwer_context.window;
	return (lines);
}

static t_frame_context	frame_context(
		t_parser_matrix *mtx, t_coord_2d curr_coord,
		t_lines *lines, t_camera *camera)
{
	t_frame_context	frame;

	frame.camera = camera;
	frame.curr_coord = curr_coord;
	frame.lines = lines;
	frame.mtx = mtx;
	return (frame);
}
