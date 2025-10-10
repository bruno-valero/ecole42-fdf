/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:08:31 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/09 22:23:15 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

t_state	*get_state(void)
{
	static t_state	*state;

	if (state)
		return (state);
	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	ft_bzero(state, sizeof(t_state));
	state->self_ref = &state;
	state->viewer_context = create_viewer_context();
	return (state);
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
