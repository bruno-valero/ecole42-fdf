/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:02:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/01 17:11:59 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <math.h>

static void			draw_line_right(
						t_parser_matrix *parser_matrix, t_coord_2d matrix_coord,
						t_minilib_layer layer, t_minilib_window window);
static void			draw_line_down(
						t_parser_matrix *parser_matrix, t_coord_2d matrix_coord,
						t_minilib_layer layer, t_minilib_window window);
static t_coord_2d	coord_3d_to_2d(t_coord_3d coord);
static void			scale_point(t_coord_2d *coord, int scale);
static void			set_position(t_coord_2d *coord, t_parser_matrix *mtx,
						int scale, t_minilib_window window);
static int			handle_key(int key, void *mlx);
static int			handle_mouse(int key, int x, int y, t_parser_matrix *parser_matrix);

void	core(char *file_path, void *mlx,
			t_minilib_layer layer, t_minilib_window window)
{
	t_parser_matrix	*parser_matrix;
	t_coord_2d		matrix_coord;

	if (!parse_file(file_path, &parser_matrix))
		return ;
	matrix_coord.y = -1;
	while (parser_matrix->data[++matrix_coord.y])
	{
		matrix_coord.x = -1;
		while (++matrix_coord.x < parser_matrix->width)
		{
			draw_line_right(parser_matrix, matrix_coord, layer, window);
			draw_line_down(parser_matrix, matrix_coord, layer, window);
		}
	}
	put_layer(window, layer);
	mlx_key_hook(window.ref, handle_key, mlx);
	mlx_mouse_hook(window.ref, handle_mouse, parser_matrix);
	mlx_loop(mlx);
	parser_matrix->destroy(parser_matrix);
}

static void	draw_line_right(
				t_parser_matrix *mtx, t_coord_2d mtx_coord,
				t_minilib_layer layer, t_minilib_window window)
{
	t_coord_2d		coord1;
	t_coord_2d		coord2;
	int				scale;
	int				x;
	int				y;

	x = mtx_coord.x;
	y = mtx_coord.y;
	scale = 35;
	if (mtx_coord.x + 1 < mtx->width)
	{
		coord1 = coord_3d_to_2d(mtx->data[y][x].coord);
		coord2 = coord_3d_to_2d(mtx->data[y][x + 1].coord);
		scale_point(&coord1, scale);
		scale_point(&coord2, scale);
		set_position(&coord1, mtx, scale, window);
		set_position(&coord2, mtx, scale, window);
		draw_line(new_line(coord1, coord2), window, bresenham);
	}
}

static void	draw_line_down(
				t_parser_matrix *mtx, t_coord_2d current_coord,
				t_minilib_layer layer, t_minilib_window window)
{
	t_coord_2d		coord1;
	t_coord_2d		coord2;
	int				scale;
	int				current_x;
	int				current_y;

	current_x = current_coord.x;
	current_y = current_coord.y;
	scale = 35;
	if (mtx->data[current_coord.y + 1])
	{
		coord1 = coord_3d_to_2d(mtx->data[current_y][current_x].coord);
		coord2 = coord_3d_to_2d(mtx->data[current_y + 1][current_x].coord);
		scale_point(&coord1, scale);
		scale_point(&coord2, scale);
		set_position(&coord1, mtx, scale, window);
		set_position(&coord2, mtx, scale, window);
		draw_line(new_line(coord1, coord2), window, bresenham);
	}
}

static t_coord_2d	coord_3d_to_2d(t_coord_3d coord)
{
	t_coord_2d	new_coord;

	new_coord = coord_2d(coord.x, coord.y);
	return (new_coord);
}

static void	scale_point(t_coord_2d *coord, int scale)
{
	coord->x *= scale;
	coord->y *= scale;
}

static void	set_position(t_coord_2d *coord, t_parser_matrix *mtx, int scale, t_minilib_window window)
{
	t_coord_2d	center_matrix;
	t_coord_2d	center_window;
	t_coord_2d	offset;

	center_matrix.x = (mtx->width - 1) * scale / 2;
	center_matrix.y = (mtx->height - 1) * scale / 2;
	center_window.x = window.width / 2;
	center_window.y = window.height / 2;
	offset.x = center_window.x - center_matrix.x;
	offset.y = center_window.y - center_matrix.y;
	coord->x += offset.x;
	coord->y += offset.y;
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
