/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:02:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 23:21:20 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int			handle_key(int key, void *mlx);

void	core(char *file_path)
{
	t_parser_matrix		*parser_matrix;
	t_state				*state;
	t_minilib_window	window;

	if (!parse_file(file_path, &parser_matrix))
		return ;
	state = get_state();
	if (!state)
		return ;
	window = state->viewer_context.window;
	state->parsed_data = parser_matrix;
	reset_camera(&state->camera, state->viewer_context, state->parsed_data);
	lines_init(&state->lines, state);
	if (!state->lines.data)
	{
		destroy_state(state);
		return ;
	}
	render_frame(state);
	mlx_key_hook(window.ref, handle_key, state->viewer_context.mlx_ref);
	mlx_hook(window.ref, BUTTON_PRESS_EVENT, BUTTON_PRESS_MASK, mouse_press, state);
	mlx_hook(window.ref, BUTTON_RELEASE_EVENT, BUTTON_RELEASE_MASK, mouse_release, state);
	mlx_hook(window.ref, MOTION_NOTIFY_EVENT, POINTER_MOTION_MASK, mouse_move, state);
	mlx_loop(state->viewer_context.mlx_ref);
	free(state->lines.data);
	destroy_state(state);
}

static int	handle_key(int key, void *mlx)
{
	char	*char_key;

	char_key = ft_itoa(key);
	ft_putstr_fd(char_key, 1);
	ft_putstr_fd("\n", 1);
	free(char_key);
	if (key == 65307)
		mlx_loop_end(mlx);
	return (1);
}

