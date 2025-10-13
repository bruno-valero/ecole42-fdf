/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:14:33 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 16:31:21 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_line.h"

static void	update_x_rotation(t_state *state, t_point *point);
static void	update_y_rotation(t_state *state, t_point *point);
static void	update_z_rotation(t_state *state, t_point *point);

void	update_rotation(t_state *state, t_point *point)
{
	update_z_rotation(state, point);
	update_x_rotation(state, point);
	update_y_rotation(state, point);
}

static void	update_x_rotation(t_state *state, t_point *point)
{
	t_angle	angle;
	t_point	point_copy;

	angle = state->camera.angle;
	point_copy = *point;
	point->y = (point_copy.y * angle.cos_x) - (point_copy.z * angle.sin_x);
	point->z = (point_copy.y * angle.sin_x) + (point_copy.z * angle.cos_x);
}

static void	update_y_rotation(t_state *state, t_point *point)
{
	t_angle	angle;
	t_point	point_copy;

	angle = state->camera.angle;
	point_copy = *point;
	point->x = (point_copy.x * angle.cos_y) + (point_copy.z * angle.sin_y);
	point->z = (-point_copy.x * angle.sin_y) + (point_copy.z * angle.cos_y);
}

static void	update_z_rotation(t_state *state, t_point *point)
{
	t_angle	angle;
	t_point	point_copy;

	angle = state->camera.angle;
	point_copy = *point;
	point->x = (point_copy.x * angle.cos_z) - (point_copy.y * angle.sin_z);
	point->y = (point_copy.x * angle.sin_z) + (point_copy.y * angle.cos_z);
}
