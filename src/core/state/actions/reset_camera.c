/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:30:25 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/14 13:59:54 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

static void	reset_offset(t_state *state);
static void	reset_scale(t_state *state);

void	reset_camera(t_state *state)
{
	state->camera.auto_rotate = coord_3d(0, 0, 0);
	state->camera.z_factor = 1.0;
	projection_isometric(state);
	reset_scale(state);
	reset_offset(state);
}

static void	reset_offset(t_state *state)
{
	int		window_width;
	int		window_height;
	double	mtx_width;
	double	mtx_height;

	window_width = state->viewer_context.window.width;
	window_height = state->viewer_context.window.height;
	mtx_width = (double)state->parsed_data->width;
	mtx_height = (double)state->parsed_data->height;
	window_width = state->viewer_context.window.width;
	window_height = state->viewer_context.window.height;
	(void)mtx_width;
	(void)mtx_height;
	state->camera.offset.x = window_width * 0.5;
	state->camera.offset.y = window_height * 0.5;
}

static void	reset_scale(t_state *state)
{
	int		window_width;
	int		window_height;
	double	mtx_width;
	double	mtx_height;

	window_width = state->viewer_context.window.width;
	window_height = state->viewer_context.window.height;
	mtx_width = (double)state->parsed_data->width;
	mtx_height = (double)state->parsed_data->height;
	state->camera.scale = 0.7;
	state->camera.scale_width = window_width / hypot(mtx_width, mtx_height);
	state->camera.scale_height = window_height / hypot(mtx_width, mtx_height);
}
