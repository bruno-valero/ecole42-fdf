/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:02:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 14:49:47 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	core(char *file_path)
{
	t_parser_matrix		*parser_matrix;
	t_state				*state;

	if (!parse_file(file_path, &parser_matrix))
		return ;
	state = get_state();
	if (!state)
		return ;
	state->parsed_data = parser_matrix;
	reset_camera(state);
	lines_init(&state->lines, state);
	if (!state->lines.data)
	{
		destroy_state(state);
		return ;
	}
	render_frame(state);
	mouse_hooks(state);
	keyboard_hooks(state);
	mlx_loop(state->viewer_context.mlx_ref);
	free(state->lines.data);
	destroy_state(state);
}
