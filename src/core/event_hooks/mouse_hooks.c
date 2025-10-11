/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:43:18 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 07:27:10 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"

void	mouse_hooks(t_state *state)
{
	t_minilib_window	window;

	window = state->viewer_context.window;
	on_mouse_button_press(window.ref, mouse_press, state);
	on_mouse_button_release(window.ref, mouse_release, state);
	on_mouse_move(window.ref, mouse_move, state);
}
