/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_callback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:19:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/13 13:53:47 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_callback.h"

static void	auto_rotate(t_state *state);

int	handle_loop(t_state *state)
{
	t_coord_3d	rotate;
	static int	pace = 0;

	pace++;
	rotate = state->camera.auto_rotate;
	if (pace > 80 && (rotate.x || rotate.y || rotate.z))
	{
		auto_rotate(state);
		render_frame(state);
		pace = 0;
	}
	return (1);
}

static void	auto_rotate(t_state *state)
{
	int	factor;

	factor = 10;
	if (state->camera.auto_rotate.x > 0)
		state->camera.angle.x += 1.0 / factor;
	if (state->camera.auto_rotate.x < 0)
		state->camera.angle.x -= 1.0 / factor;
	if (state->camera.auto_rotate.y > 0)
		state->camera.angle.y += 1.0 / factor;
	if (state->camera.auto_rotate.y < 0)
		state->camera.angle.y -= 1.0 / factor;
	if (state->camera.auto_rotate.z > 0)
		state->camera.angle.z += 1.0 / factor;
	if (state->camera.auto_rotate.z < 0)
		state->camera.angle.z -= 1.0 / factor;
	update_angle(state);
}
