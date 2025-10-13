/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:08:31 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/13 20:23:30 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

t_state	*get_state(void)
{
	t_state	*state;

	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	ft_bzero(state, sizeof(t_state));
	state->self_ref = &state;
	state->modes.resolution = 1;
	state->viewer_context = create_viewer_context();
	return (state);
}

void	update_angle(t_state *state)
{
	float	angle;

	angle = state->camera.angle.x * (PI / 180);
	state->camera.angle.cos_x = cos(angle);
	state->camera.angle.sin_x = sin(angle);
	angle = state->camera.angle.y * (PI / 180);
	state->camera.angle.cos_y = cos(angle);
	state->camera.angle.sin_y = sin(angle);
	angle = state->camera.angle.z * (PI / 180);
	state->camera.angle.cos_z = cos(angle);
	state->camera.angle.sin_z = sin(angle);
}

void	*destroy_state(t_state	*state)
{
	t_state	**state_ref;

	if (!state)
		return (NULL);
	if (state->parsed_data)
		state->parsed_data->destroy(state->parsed_data);
	state->viewer_context.window.destroy(state->viewer_context.window);
	state->viewer_context.wireframe.destroy(state->viewer_context.wireframe);
	mlx_destroy_display(state->viewer_context.mlx_ref);
	free(state->viewer_context.mlx_ref);
	state_ref = state->self_ref;
	free(state);
	*state_ref = NULL;
	return (NULL);
}
