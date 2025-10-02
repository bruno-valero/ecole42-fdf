/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:41:12 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 15:07:30 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_minilib_layer *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void				*mlx;
	t_minilib_layer		layer;
	t_minilib_window	window;
	t_line				line1;
	t_line				line2;

	mlx = mlx_init();
	window = new_window(mlx, 1080, 720, "Fil de Fer -> brunofer");
	layer = new_layer(window, 1080, 720);
	line1 = new_line(coord_2d(50, 200), coord_2d(10, 10));
	line2 = new_line(coord_2d(500, 500), coord_2d(900, 700));
	draw_line(line1, window, bresenham);
	draw_line(line2, window, bresenham);
	put_layer(window, layer);
	mlx_loop(mlx);
	window.destroy(window);
	layer.destroy(layer);
	mlx_destroy_display(mlx);
	return (0);
}


/*

matrix [
	{
		next: pointer(matrix),
		list: list[
		{
		next: pointer(list),
		str:string
		}
		]
	},
	{
		next: pointer(matrix),
		list: list[
		{
		next: pointer(list),
		str:string
		}
		]
	}
]

 */
