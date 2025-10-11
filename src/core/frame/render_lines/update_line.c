/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:59:29 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 05:55:32 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_line.h"

static void	update_scale(t_state	*state, t_line *curr_line);
static void	update_offset(t_state	*state, t_line *curr_line);
static void	centralize(t_state	*state, t_line *curr_line);
static void	update_z_factor(t_state	*state, t_line *curr_line);

void	update_line(t_state	*state, t_line *curr_line)
{
	t_line	newer_line;

	newer_line = *curr_line;
	update_z_factor(state, &newer_line);
	centralize(state, &newer_line);
	update_scale(state, &newer_line);
	update_rotation(state, &newer_line);
	update_offset(state, &newer_line);
	*curr_line = new_line(newer_line.initial_point, newer_line.final_point);
}

static void	update_scale(t_state	*state, t_line *curr_line)
{
	double	scale_width;
	double	scale_height;

	scale_width = state->camera.scale_width;
	scale_height = state->camera.scale_height;
	curr_line->initial_point.x *= scale_width * state->camera.scale;
	curr_line->initial_point.y *= scale_height * state->camera.scale;
	curr_line->final_point.x *= scale_width * state->camera.scale;
	curr_line->final_point.y *= scale_height * state->camera.scale;
}

static void	update_offset(t_state	*state, t_line *curr_line)
{
	curr_line->initial_point.x += state->camera.offset.x;
	curr_line->initial_point.y += state->camera.offset.y;
	curr_line->final_point.x += state->camera.offset.x;
	curr_line->final_point.y += state->camera.offset.y;
}

static void	centralize(t_state	*state, t_line *curr_line)
{
	curr_line->initial_point.x -= state->parsed_data->width / 2;
	curr_line->initial_point.y -= state->parsed_data->height / 2;
	curr_line->final_point.x -= state->parsed_data->width / 2;
	curr_line->final_point.y -= state->parsed_data->height / 2;
}

static void	update_z_factor(t_state	*state, t_line *curr_line)
{
	double	delta_z;

	delta_z = state->parsed_data->bigger_z - state->parsed_data->lower_z;
	curr_line->initial_point.z *= (40 / delta_z) * state->camera.z_factor;
	curr_line->final_point.z *= (40 / delta_z) * state->camera.z_factor;
}
