/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:56:16 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 20:31:47 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	auto_rotate_x(t_state *state)
{
	if (!state->camera.auto_rotate.x)
		state->camera.auto_rotate.x = 1;
	else if (state->camera.auto_rotate.x == 1)
		state->camera.auto_rotate.x = -1;
	else
		state->camera.auto_rotate.x = 0;
}

void	auto_rotate_y(t_state *state)
{
	if (!state->camera.auto_rotate.y)
		state->camera.auto_rotate.y = 1;
	else if (state->camera.auto_rotate.y == 1)
		state->camera.auto_rotate.y = -1;
	else
		state->camera.auto_rotate.y = 0;
}

void	auto_rotate_z(t_state *state)
{
	if (!state->camera.auto_rotate.z)
		state->camera.auto_rotate.z = 1;
	else if (state->camera.auto_rotate.z == 1)
		state->camera.auto_rotate.z = -1;
	else
		state->camera.auto_rotate.z = 0;
}

void	auto_rotate_stop(t_state *state)
{
	state->camera.auto_rotate.x = 0;
	state->camera.auto_rotate.y = 0;
	state->camera.auto_rotate.z = 0;
}
