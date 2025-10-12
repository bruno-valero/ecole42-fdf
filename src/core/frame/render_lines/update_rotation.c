/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:14:33 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 00:22:51 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_line.h"

static void	update_x_rotation(t_state *state, t_line *line);
static void	update_y_rotation(t_state *state, t_line *line);
static void	update_z_rotation(t_state *state, t_line *line);

void	update_rotation(t_state *state, t_line *line)
{
	update_z_rotation(state, line);
	update_x_rotation(state, line);
	update_y_rotation(state, line);
}

static void	update_x_rotation(t_state *state, t_line *line)
{
	t_angle	angle;
	t_point	point;

	angle = state->camera.angle;
	point = line->initial_point;
	line->initial_point.y = (point.y * angle.cos_x) - (point.z * angle.sin_x);
	line->initial_point.z = (point.y * angle.sin_x) + (point.z * angle.cos_x);
	point = line->final_point;
	line->final_point.y = (point.y * angle.cos_x) - (point.z * angle.sin_x);
	line->final_point.z = (point.y * angle.sin_x) + (point.z * angle.cos_x);
}

static void	update_y_rotation(t_state *state, t_line *line)
{
	t_angle	angle;
	t_point	point;

	angle = state->camera.angle;
	point = line->initial_point;
	line->initial_point.x = (point.x * angle.cos_y) + (point.z * angle.sin_y);
	line->initial_point.z = (-point.x * angle.sin_y) + (point.z * angle.cos_y);
	point = line->final_point;
	line->final_point.x = (point.x * angle.cos_y) + (point.z * angle.sin_y);
	line->final_point.z = (-point.x * angle.sin_y) + (point.z * angle.cos_y);
}

static void	update_z_rotation(t_state *state, t_line *line)
{
	t_angle	angle;
	t_point	point;

	angle = state->camera.angle;
	point = line->initial_point;
	line->initial_point.x = (point.x * angle.cos_z) - (point.y * angle.sin_z);
	line->initial_point.y = (point.x * angle.sin_z) + (point.y * angle.cos_z);
	point = line->final_point;
	line->final_point.x = (point.x * angle.cos_z) - (point.y * angle.sin_z);
	line->final_point.y = (point.x * angle.sin_z) + (point.y * angle.cos_z);
}
