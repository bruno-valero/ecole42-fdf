/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:26:19 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 05:11:30 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_callbacks.h"

static void	zoon(double direction, t_state *state);

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

static void	zoon(double direction, t_state *state)
{
	state->camera.scale += direction / 10;
}
