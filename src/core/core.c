/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:02:12 by valero            #+#    #+#             */
/*   Updated: 2025/09/30 17:33:03 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	core(char *file_path, void *mlx, t_minilib_layer layer, t_minilib_window window)
{
	t_parser_matrix	*parser_matrix;
	t_coord_2d		matrix_coord;
	t_coord_2d		coord1;
	t_coord_2d		coord2;

	if (!read_file(file_path, &parser_matrix))
		return ;
	mlx = mlx_init();
	window = new_window(mlx, 1080, 720, "Fil de Fer -> brunofer");
	layer = new_layer(window, 1080, 720);
	matrix_coord.y = -1;
	while (parser_matrix->data[++matrix_coord.y])
	{
		matrix_coord.x = -1;
		while (++matrix_coord.x < parser_matrix->width)
		{
			if (matrix_coord.x + 1 < parser_matrix->width)
			{
				coord1 = coord_2d(
						parser_matrix->data[matrix_coord.y][matrix_coord.x].coord.x,
						parser_matrix->data[matrix_coord.y][matrix_coord.x].coord.y
						);
				coord2 = coord_2d(
						parser_matrix->data[matrix_coord.y][matrix_coord.x + 1].coord.x,
						parser_matrix->data[matrix_coord.y][matrix_coord.x + 1].coord.y
						);
				draw_line(new_line(coord1, coord2, layer), window, bresenham);
			}
			if (parser_matrix->data[matrix_coord.y + 1])
			{
				coord1 = coord_2d(
						parser_matrix->data[matrix_coord.y][matrix_coord.x].coord.x,
						parser_matrix->data[matrix_coord.y][matrix_coord.x].coord.y
						);
				coord2 = coord_2d(
						parser_matrix->data[matrix_coord.y + 1][matrix_coord.x].coord.x,
						parser_matrix->data[matrix_coord.y + 1][matrix_coord.x].coord.y
						);
				draw_line(new_line(coord1, coord2, layer), window, bresenham);
			}
		}

	}
	put_layer(window, layer);
	mlx_loop(mlx);
}
