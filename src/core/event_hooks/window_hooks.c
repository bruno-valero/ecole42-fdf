/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:21:01 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 16:34:27 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"

void	window_hooks(t_state *state)
{
	t_minilib_window	window;

	window = state->viewer_context.window;
	on_close_window(window.ref, mlx_loop_end, window.mlx_ref);
}
