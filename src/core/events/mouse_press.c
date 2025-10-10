/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:26:19 by valero            #+#    #+#             */
/*   Updated: 2025/10/10 20:08:00 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_press.h"

static void	zoon(double direction, t_state *state);

int	mouse_press(int key, int x, int y, t_state *state)
{
	t_mouse_keys	mouse_key;
	int				fd;

	fd = 1;
	(void)x;
	(void)y;
	mouse_key = (t_mouse_keys)key;
	if (mouse_key == MOUSE_LEFT_BUTTON)
		state->mouse_state.left_button = 1;
	if (mouse_key == MOUSE_RIGHT_BUTTON)
		state->mouse_state.right_button = 1;
	if (mouse_key == MOUSE_MIDDLE_BUTTON)
		state->mouse_state.scroll_button = 1;
	if (mouse_key == MOUSE_SCROLL_UP)
		zoon(1, state);
	if (mouse_key == MOUSE_SCROLL_DOWN)
		zoon(-1, state);
	if (mouse_key == MOUSE_SCROLL_UP || mouse_key == MOUSE_SCROLL_DOWN)
		render_frame(state);
	return (1);
}

int	mouse_release(int key, int x, int y, t_state *state)
{
	t_mouse_keys	mouse_key;

	(void)x;
	(void)y;
	mouse_key = (t_mouse_keys)key;
	if (mouse_key == MOUSE_LEFT_BUTTON)
	{
		state->mouse_state.left_button = 0;
		state->actions.drag_lb.drag_start = 0;
	}
	if (mouse_key == MOUSE_RIGHT_BUTTON)
	{
		state->mouse_state.right_button = 0;
		state->actions.drag_rb.drag_start = 0;
	}
	if (mouse_key == MOUSE_MIDDLE_BUTTON)
	{
		state->mouse_state.scroll_button = 0;
		state->actions.drag_mb.drag_start = 0;
	}
	return (1);
}

static void	drag_lb(int x, int y, t_state *state);
static void	drag_mb(int x, int y, t_state *state);
static void	drag_rb(int x, int y, t_state *state);

int	mouse_move(int x, int y, t_state *state)
{
	if (state->mouse_state.left_button)
		drag_lb(x, y, state);
	if (state->mouse_state.scroll_button)
		drag_mb(x, y, state);
	if (state->mouse_state.right_button)
		drag_rb(x, y, state);
	if (state->mouse_state.left_button || state->mouse_state.scroll_button)
		render_frame(state);
	return (1);
}

#include <stdio.h>

static void	drag_lb(int x, int y, t_state *state)
{
	if (!state->actions.drag_lb.drag_start)
	{
		state->actions.drag_lb.drag_start = 1;
		state->actions.drag_lb.last.x = x;
		state->actions.drag_lb.last.y = y;
		state->actions.drag_lb.result.x = 0;
		state->actions.drag_lb.result.y = 0;
	}
	else
	{
		state->actions.drag_lb.result.x = state->actions.drag_lb.last.x - x;
		state->actions.drag_lb.result.y = state->actions.drag_lb.last.y - y;
		state->actions.drag_lb.last.x = x;
		state->actions.drag_lb.last.y = y;
	}
	state->camera.angle.x += state->actions.drag_lb.result.y;
	state->camera.angle.y -= state->actions.drag_lb.result.x;
	printf("dragged_lb(x: %f, y: %f)\n",
		state->actions.drag_lb.result.x, state->actions.drag_lb.result.y);
}

static void	drag_mb(int x, int y, t_state *state)
{
	if (!state->actions.drag_mb.drag_start)
	{
		state->actions.drag_mb.drag_start = 1;
		state->actions.drag_mb.last.x = x;
		state->actions.drag_mb.last.y = y;
		state->actions.drag_mb.result.x = 0;
		state->actions.drag_mb.result.y = 0;
	}
	else
	{
		state->actions.drag_mb.result.x = state->actions.drag_mb.last.x - x;
		state->actions.drag_mb.result.y = state->actions.drag_mb.last.y - y;
		state->actions.drag_mb.last.x = x;
		state->actions.drag_mb.last.y = y;
	}
	state->camera.offset.x -= state->actions.drag_mb.result.x;
	state->camera.offset.y -= state->actions.drag_mb.result.y;
	printf("dragged_mb(x: %f, y: %f)\n",
		state->actions.drag_mb.result.x, state->actions.drag_mb.result.y);
}

static void	drag_rb(int x, int y, t_state *state)
{
	if (!state->actions.drag_rb.drag_start)
	{
		state->actions.drag_rb.drag_start = 1;
		state->actions.drag_rb.last.x = x;
		state->actions.drag_rb.last.y = y;
		state->actions.drag_rb.result.x = 0;
		state->actions.drag_rb.result.y = 0;
	}
	else
	{
		state->actions.drag_rb.result.x = state->actions.drag_rb.last.x - x;
		state->actions.drag_rb.result.y = state->actions.drag_rb.last.y - y;
		state->actions.drag_rb.last.x = x;
		state->actions.drag_rb.last.y = y;
	}
	printf("dragged_rb(x: %f, y: %f)\n",
		state->actions.drag_rb.result.x, state->actions.drag_rb.result.y);
}

static void	zoon(double direction, t_state *state)
{
	state->camera.scale += direction / 10;
}
