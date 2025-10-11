/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:26:19 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 11:58:18 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_callbacks.h"

static void	zoon(double direction, int x, int y, t_state *state);

int	mouse_press(int key, int x, int y, t_state *state)
{
	t_mouse_keys	mouse_key;

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
		zoon(1, x, y, state);
	if (mouse_key == MOUSE_SCROLL_DOWN)
		zoon(-1, x, y, state);
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

static void	zoon(double direction, int x, int y, t_state *state)
{
	t_coord_2d	center;
	t_coord_2d	delta_mouse;

	center.x = state->viewer_context.window.width / 2;
	center.y = state->viewer_context.window.height / 2;
	delta_mouse.x = x - center.x;
	delta_mouse.y = y - center.y;
	state->camera.scale += direction / 10;
	if (direction > 0)
	{
		state->camera.offset.x -= delta_mouse.x * 0.1;
		state->camera.offset.y -= delta_mouse.y * 0.1;
		return ;
	}
	state->camera.offset.x += delta_mouse.x * 0.1;
	state->camera.offset.y += delta_mouse.y * 0.1;
}
