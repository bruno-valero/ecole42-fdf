/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:36:54 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 19:41:59 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"

void	loop_hook(t_state *state)
{
	t_minilib_window	window;

	window = state->viewer_context.window;
	on_loop(window.mlx_ref, handle_loop, state);
}
