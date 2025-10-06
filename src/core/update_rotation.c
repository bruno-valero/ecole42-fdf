/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:14:33 by valero            #+#    #+#             */
/*   Updated: 2025/10/05 21:36:15 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_line.h"

static void	update_x_rotation(t_frame_context frame, t_line *line);
static void	update_y_rotation(t_frame_context frame, t_line *line);
static void	update_z_rotation(t_frame_context frame, t_line *line);

void	update_rotation(t_frame_context frame, t_line *line)
{
	update_z_rotation(frame, line);
	update_x_rotation(frame, line);
	update_y_rotation(frame, line);
}

static void	update_x_rotation(t_frame_context frame, t_line *line)
{
	float		angle;
	t_coord_3d	coord;

	angle = frame.camera->angle.x * (PI / 180);
	coord = line->initial_point;
	line->initial_point.y = (coord.y * cos(angle)) - (coord.z * sin(angle));
	line->initial_point.z = (coord.y * sin(angle)) + (coord.z * cos(angle));
	coord = line->final_point;
	line->final_point.y = (coord.y * cos(angle)) - (coord.z * sin(angle));
	line->final_point.z = (coord.y * sin(angle)) + (coord.z * cos(angle));
}

static void	update_y_rotation(t_frame_context frame, t_line *line)
{
	float		angle;
	t_coord_3d	coord;

	angle = frame.camera->angle.y * (PI / 180);
	coord = line->initial_point;
	line->initial_point.x = (coord.x * cos(angle)) + (coord.z * sin(angle));
	line->initial_point.z = (-coord.x * sin(angle)) + (coord.z * cos(angle));
	coord = line->final_point;
	line->final_point.x = (coord.x * cos(angle)) + (coord.z * sin(angle));
	line->final_point.z = (-coord.x * sin(angle)) + (coord.z * cos(angle));
}

static void	update_z_rotation(t_frame_context frame, t_line *line)
{
	float		angle;
	t_coord_3d	coord;

	angle = frame.camera->angle.z * (PI / 180);
	coord = line->initial_point;
	line->initial_point.x = (coord.x * cos(angle)) - (coord.y * sin(angle));
	line->initial_point.y = (coord.x * sin(angle)) + (coord.y * cos(angle));
	coord = line->final_point;
	line->final_point.x = (coord.x * cos(angle)) - (coord.y * sin(angle));
	line->final_point.y = (coord.x * sin(angle)) + (coord.y * cos(angle));
}
