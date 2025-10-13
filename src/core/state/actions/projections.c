/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:23:22 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/12 00:17:06 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	projection_isometric(t_state *state)
{
	state->camera.angle.x = 60;
	state->camera.angle.y = 0;
	state->camera.angle.z = 30;
	update_angle(state);
}

void	projection_top_down(t_state *state)
{
	state->camera.angle.x = 0;
	state->camera.angle.y = 0;
	state->camera.angle.z = 0;
	update_angle(state);
}

void	projection_side_view(t_state *state)
{
	state->camera.angle.x = 90;
	state->camera.angle.y = 90;
	state->camera.angle.z = 0;
	update_angle(state);
}

void	projection_front_view(t_state *state)
{
	state->camera.angle.x = 90;
	state->camera.angle.y = 0;
	state->camera.angle.z = 0;
	update_angle(state);
}
