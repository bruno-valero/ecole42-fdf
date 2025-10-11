/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:43:18 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 07:27:14 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"

void	keyboard_hooks(t_state *state)
{
	t_minilib_window	window;

	window = state->viewer_context.window;
	on_key_press(window.ref, key_press, state);
	on_key_release(window.ref, key_release, state);
}
