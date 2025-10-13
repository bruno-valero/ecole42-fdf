/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_callback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:19:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 21:16:43 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_callback.h"

static void	auto_rotate(t_state *state);

int	handle_loop(t_state *state)
{
	t_coord_3d	rotate;


	rotate = state->camera.auto_rotate;
	if (rotate.x || rotate.y || rotate.z)
	{
		auto_rotate(state);
		render_frame(state);
	}
	return (1);
}

static void	auto_rotate(t_state *state)
{
	int	matrix_size;
	int	factor;

	matrix_size = state->parsed_data->width
		* state->parsed_data->height;
	factor = pow(matrix_size, 0.2);
	if (factor < 50)
		factor = 50;
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
