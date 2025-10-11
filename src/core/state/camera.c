/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:23:25 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 04:42:04 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	reset_offset(t_camera *camera, t_viewer_context context, t_parser_matrix *mtx);
static void	reset_angle(t_camera *camera);
static void	reset_scale(t_camera *camera, t_viewer_context context,
				t_parser_matrix *mtx);

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

void	reset_camera(t_camera *camera, t_viewer_context context,
			t_parser_matrix *mtx)
{
	reset_offset(camera, context, mtx);
	reset_angle(camera);
	camera->z_factor = 1.0;
	reset_scale(camera, context, mtx);
	camera->line_tracer = 0;
	camera->projection = 0;
	camera->auto_rotate = coord_3d(0, 0, 0);
}

static void	reset_offset(t_camera *camera, t_viewer_context context, t_parser_matrix *mtx)
{
	int		window_width;
	int		window_height;
	double	mtx_width;
	double	mtx_height;

	window_width = context.window.width;
	window_height = context.window.height;
	mtx_width = (double)mtx->width;
	mtx_height = (double)mtx->height;
	window_width = context.window.width;
	window_height = context.window.height;
	(void)mtx_width;
	(void)mtx_height;
	camera->offset.x = window_width * 0.5;
	camera->offset.y = window_height * 0.5;
}

static void	reset_angle(t_camera *camera)
{
	camera->angle = coord_3d_double(35, -45, 0);
}

static void	reset_scale(t_camera *camera, t_viewer_context context,
				t_parser_matrix *mtx)
{
	int		window_width;
	int		window_height;
	double	mtx_width;
	double	mtx_height;

	window_width = context.window.width;
	window_height = context.window.height;
	mtx_width = (double)mtx->width;
	mtx_height = (double)mtx->height;
	camera->scale = 0.7;
	camera->scale_width = window_width / hypot(mtx_width, mtx_height);
	camera->scale_height = window_height / hypot(mtx_width, mtx_height);
}
