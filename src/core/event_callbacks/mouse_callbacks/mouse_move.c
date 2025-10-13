/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:26:19 by valero            #+#    #+#             */
/*   Updated: 2025/10/13 14:03:56 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_callbacks.h"

static void	drag_lb(int x, int y, t_state *state);
static void	drag_mb(int x, int y, t_state *state);
static void	drag_rb(int x, int y, t_state *state);
static void	update_drag(int x, int y, t_state *state, t_coord_2d *last);

int	mouse_move(int x, int y, t_state *state)
{
	if (state->mouse_state.left_button)
		drag_lb(x, y, state);
	if (state->mouse_state.scroll_button)
		drag_mb(x, y, state);
	if (state->mouse_state.right_button)
		drag_rb(x, y, state);
	return (1);
}

static void	drag_lb(int x, int y, t_state *state)
{
	t_coord_2d	*last;
	double		factor;

	factor = 30 * state->camera.scale;
	auto_rotate_stop(state);
	last = &state->actions.drag_lb.last;
	if (!state->actions.drag_lb.drag_start)
	{
		state->actions.drag_lb.drag_start = 1;
		state->actions.drag_lb.result.x = 0;
		state->actions.drag_lb.result.y = 0;
	}
	else
	{
		state->actions.drag_lb.result.x = (double)(last->x - x) / factor;
		state->actions.drag_lb.result.y = (double)(last->y - y) / factor;
	}
	state->camera.angle.x += state->actions.drag_lb.result.y;
	state->camera.angle.y -= state->actions.drag_lb.result.x;
	update_angle(state);
	update_drag(x, y, state, last);
}

static void	drag_mb(int x, int y, t_state *state)
{
	t_coord_2d	*last;
	double		factor;

	factor = 3 * state->camera.scale;
	last = &state->actions.drag_mb.last;
	if (!state->actions.drag_mb.drag_start)
	{
		state->actions.drag_mb.drag_start = 1;
		state->actions.drag_mb.result.x = 0;
		state->actions.drag_mb.result.y = 0;
	}
	else
	{
		state->actions.drag_mb.result.x = (double)(last->x - x) / factor;
		state->actions.drag_mb.result.y = (double)(last->y - y) / factor;
	}
	state->camera.offset.x -= state->actions.drag_mb.result.x;
	state->camera.offset.y -= state->actions.drag_mb.result.y;
	update_drag(x, y, state, last);
}

static void	drag_rb(int x, int y, t_state *state)
{
	t_coord_2d	*last;
	double		factor;

	factor = 30 * state->camera.scale;
	auto_rotate_stop(state);
	last = &state->actions.drag_rb.last;
	if (!state->actions.drag_rb.drag_start)
	{
		state->actions.drag_rb.drag_start = 1;
		state->actions.drag_rb.result.x = 0;
		state->actions.drag_rb.result.y = 0;
	}
	else
	{
		state->actions.drag_rb.result.x = (double)(last->x - x) / factor;
		state->actions.drag_rb.result.y = (double)(last->y - y) / factor;
	}
	state->camera.angle.z -= state->actions.drag_rb.result.y;
	state->camera.angle.z += state->actions.drag_rb.result.x;
	update_angle(state);
	update_drag(x, y, state, last);
}

static void	update_drag(int x, int y, t_state *state, t_coord_2d *last)
{
	if (x - last->x > 10 * state->camera.scale
		|| x - last->x < -10 * state->camera.scale
		|| y - last->y > 10 * state->camera.scale
		|| y - last->y < -10 * state->camera.scale)
	{
		last->x = x;
		last->y = y;
		render_frame(state);
	}
}
