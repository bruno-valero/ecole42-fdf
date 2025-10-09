/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:02:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 02:20:40 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int			handle_key(int key, void *mlx);
static void			load_lines(t_lines lines);

void	core(char *file_path)
{
	t_parser_matrix		*parser_matrix;
	t_lines				lines;
	t_state				*state;

	if (!parse_file(file_path, &parser_matrix))
		return ;
	state = get_state();
	if (!state)
		return ;
	state->parsed_data = parser_matrix;
	reset_camera(&state->camera, state->viewer_context, state->parsed_data);
	lines = build_lines(update_line);
	load_lines(lines);
	put_layer(state->viewer_context.window, state->viewer_context.layer);
	mlx_key_hook(state->viewer_context.window.ref, handle_key, state->viewer_context.mlx_ref);
	mlx_hook(state->viewer_context.window.ref, 4, 1L << 2, mouse_press, parser_matrix);
	// mlx_loop_hook()
	mlx_loop(state->viewer_context.mlx_ref);
	free(lines.data);
	destroy_state(state);
}

static void	load_lines(t_lines lines)
{
	int		i;
	t_state	*state;

	state = get_state();
	i = -1;
	while (++i < lines.size)
		draw_line(lines.data[i], state->viewer_context, bresenham);

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

