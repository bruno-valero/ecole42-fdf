/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:23:25 by valero            #+#    #+#             */
/*   Updated: 2025/10/01 23:19:00 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	reset_offset(t_frame_context frame);

t_camera	create_camera(void)
{
	t_camera	camera;

	camera.offset = coord_2d(0, 0);
	camera.angle = coord_3d_double(0, 0, 0);
	camera.z_factor = 0;
	camera.scale = 0;
	camera.scale_width = 0;
	camera.scale_height = 0;
	camera.line_tracer = 0;
	camera.projection = 0;
	camera.auto_rotate = coord_3d(0, 0, 0);
	return (camera);
}

void	reset_camera(t_frame_context frame)
{
	reset_offset(frame);
	frame.camera->angle = coord_3d_double(0, 0, 0);
	frame.camera->z_factor = 0;
	frame.camera->scale = 0;
	frame.camera->scale_width = 0;
	frame.camera->scale_height = 0;
	frame.camera->line_tracer = 0;
	frame.camera->projection = 0;
	frame.camera->auto_rotate = coord_3d(0, 0, 0);
}

static t_coord_2d	coord_3d_to_2d(t_coord_3d coord)
{
	t_coord_2d	new_coord;

	new_coord = coord_2d(coord.x, coord.y);
	return (new_coord);
}

static void	reset_offset(t_frame_context frame)
{
	t_coord_2d	center_matrix;
	t_coord_2d	center_window;
	t_coord_2d	offset;

	frame.lines->window;
	center_matrix.x = (frame.mtx->width - 1) * frame.camera->scale / 2;
	center_matrix.y = (frame.mtx->height - 1) * frame.camera->scale / 2;
	center_window.x = frame.lines->window.width / 2;
	center_window.y = frame.lines->window.height / 2;
	frame.camera->offset.x = center_window.x - center_matrix.x;
	frame.camera->offset.y = center_window.y - center_matrix.y;
}
