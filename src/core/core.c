/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:02:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/06 20:06:55 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int			handle_key(int key, void *mlx);
static int			handle_mouse(int key, int x, int y,
						t_parser_matrix *parser_matrix);
static void			load_lines(t_lines lines, t_viewer_context context);

void	core(char *file_path)
{
	t_parser_matrix		*parser_matrix;
	t_lines				lines;
	t_viewer_context	viewer_context;
	t_camera			camera;

	if (!parse_file(file_path, &parser_matrix))
		return ;
	viewer_context = create_viewer_context(NULL, NULL, NULL);
	camera = create_camera();
	reset_camera(&camera, viewer_context, parser_matrix);
	lines = build_lines(parser_matrix, viewer_context, &camera, update_line);
	load_lines(lines, viewer_context);
	put_layer(viewer_context.window, viewer_context.layer);
	mlx_key_hook(viewer_context.window.ref, handle_key, viewer_context.mlx_ref);
	mlx_mouse_hook(viewer_context.window.ref, handle_mouse, parser_matrix);
	mlx_loop(viewer_context.mlx_ref);
	parser_matrix->destroy(parser_matrix);
	viewer_context.window.destroy(viewer_context.window);
	viewer_context.layer.destroy(viewer_context.layer);
	mlx_destroy_display(viewer_context.mlx_ref);
	free(viewer_context.mlx_ref);
}

static void	load_lines(t_lines lines, t_viewer_context context)
{
	int	i;

	i = -1;
	while (++i < lines.size)
		draw_line(lines.data[i], context, bresenham);

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


static int	handle_mouse(int key, int x, int y, t_parser_matrix *parser_matrix)
{
	char	*char_key;

	char_key = ft_itoa(key);
	ft_putstr_fd(char_key, 1);
	ft_putstr_fd("\n", 1);
	free(char_key);
	char_key = ft_itoa(parser_matrix->width);
	ft_putstr_fd(char_key, 1);
	ft_putstr_fd("\n", 1);
	free(char_key);
	char_key = ft_itoa(x);
	ft_putstr_fd(char_key, 1);
	ft_putstr_fd("\n", 1);
	free(char_key);
	char_key = ft_itoa(y);
	ft_putstr_fd(char_key, 1);
	ft_putstr_fd("\n", 1);
	free(char_key);
	return (1);
}
