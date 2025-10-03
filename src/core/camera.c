/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:23:25 by valero            #+#    #+#             */
/*   Updated: 2025/10/03 14:00:00 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	reset_offset(t_frame_context frame);
static void	reset_angle(t_frame_context frame);
static void	reset_scale(t_frame_context frame);

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
	reset_angle(frame);
	frame.camera->z_factor = 0;
	reset_scale(frame);
	frame.camera->line_tracer = 0;
	frame.camera->projection = 0;
	frame.camera->auto_rotate = coord_3d(0, 0, 0);
}

// static t_coord_2d	coord_3d_to_2d(t_coord_3d coord)
// {
// 	t_coord_2d	new_coord;

// 	new_coord = coord_2d(coord.x, coord.y);
// 	return (new_coord);
// }

static void	reset_offset(t_frame_context frame)
{
	int		window_width;
	int		window_height;

	window_width = frame.lines->window.width;
	window_height = frame.lines->window.height;
	frame.camera->offset.x = window_width / 2;
	frame.camera->offset.y = window_height / 2;
}

static void	reset_angle(t_frame_context frame)
{
	frame.camera->angle = coord_3d_double(60, 0, 45);
}

static void	reset_scale(t_frame_context frame)
{
	int		window_width;
	int		window_height;
	double	mtx_width;
	double	mtx_height;

	window_width = frame.lines->window.width;
	window_height = frame.lines->window.height;
	mtx_width = (double)frame.mtx->width;
	mtx_height = (double)frame.mtx->height;
	frame.camera->scale = 0.7;
	frame.camera->scale_width = window_width / hypot(mtx_width, mtx_height);
	frame.camera->scale_height = window_height / hypot(mtx_width, mtx_height);
}
