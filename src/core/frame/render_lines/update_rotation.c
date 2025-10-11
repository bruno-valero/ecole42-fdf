/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:14:33 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 05:25:25 by valero           ###   ########.fr       */
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
	float	angle;
	t_point	point;

	angle = state->camera.angle.x * (PI / 180);
	point = line->initial_point;
	line->initial_point.y = (point.y * cos(angle)) - (point.z * sin(angle));
	line->initial_point.z = (point.y * sin(angle)) + (point.z * cos(angle));
	point = line->final_point;
	line->final_point.y = (point.y * cos(angle)) - (point.z * sin(angle));
	line->final_point.z = (point.y * sin(angle)) + (point.z * cos(angle));
}

static void	update_y_rotation(t_state *state, t_line *line)
{
	float	angle;
	t_point	point;

	angle = state->camera.angle.y * (PI / 180);
	point = line->initial_point;
	line->initial_point.x = (point.x * cos(angle)) + (point.z * sin(angle));
	line->initial_point.z = (-point.x * sin(angle)) + (point.z * cos(angle));
	point = line->final_point;
	line->final_point.x = (point.x * cos(angle)) + (point.z * sin(angle));
	line->final_point.z = (-point.x * sin(angle)) + (point.z * cos(angle));
}

static void	update_z_rotation(t_state *state, t_line *line)
{
	float	angle;
	t_point	point;

	angle = state->camera.angle.z * (PI / 180);
	point = line->initial_point;
	line->initial_point.x = (point.x * cos(angle)) - (point.y * sin(angle));
	line->initial_point.y = (point.x * sin(angle)) + (point.y * cos(angle));
	point = line->final_point;
	line->final_point.x = (point.x * cos(angle)) - (point.y * sin(angle));
	line->final_point.y = (point.x * sin(angle)) + (point.y * cos(angle));
}
