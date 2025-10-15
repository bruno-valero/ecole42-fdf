/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:59:29 by valero            #+#    #+#             */
/*   Updated: 2025/10/15 13:27:06 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_line.h"

static void	update_scale(t_state	*state, t_point *point);
static void	update_offset(t_state	*state, t_point *point);
static void	centralize(t_state	*state, t_point *point);
static void	update_z_factor(t_state	*state, t_point *point);

t_point	update_point(t_state	*state, t_input_point point)
{
	t_point	newer_point;

	newer_point = new_point(point.coord, point.color);
	if (!point.has_color && !state->modes.shadow)
		colorize_point(state, &newer_point);
	update_z_factor(state, &newer_point);
	centralize(state, &newer_point);
	update_scale(state, &newer_point);
	update_rotation(state, &newer_point);
	update_offset(state, &newer_point);
	if (!point.has_color && state->modes.shadow)
		colorize_point(state, &newer_point);
	return (newer_point);
}

static void	update_scale(t_state	*state, t_point *point)
{
	double	scale_width;
	double	scale_height;

	scale_width = state->camera.scale_width;
	scale_height = state->camera.scale_height;
	point->x *= scale_width * state->camera.scale;
	point->y *= scale_height * state->camera.scale;
	point->z *= state->camera.z_factor * state->camera.scale;
}

static void	update_offset(t_state	*state, t_point *point)
{
	point->x += state->camera.offset.x;
	point->y += state->camera.offset.y;
}

static void	centralize(t_state	*state, t_point *point)
{
	point->x -= state->parsed_data->width / 2;
	point->y -= state->parsed_data->height / 2;
}

static void	update_z_factor(t_state	*state, t_point *point)
{
	double	delta_z;

	delta_z = state->parsed_data->bigger_z - state->parsed_data->lower_z;
	if (!delta_z)
		return ;
	if (delta_z > 100)
		delta_z = delta_z * 0.1;
	point->z *= (40 / delta_z);
}
