/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:41:12 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 15:55:35 by brunofer         ###   ########.fr       */
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
	void			*mlx;
	void			*mlx_win;
	t_minilib_layer	layer;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 720, "Hello world!");
	layer.img = mlx_new_image(mlx, 1080, 720);
	layer.addr = mlx_get_minilib_layer_addr(layer.img, &layer.bits_per_pixel, \
		&layer.line_length, &layer.endian);
	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j < 10; j++)
	// 		my_mlx_pixel_put(&img, i + 50, j + 50, 0x00FF0000);
	// }
	t_coord_2d initial = {50, 200};
	t_coord_2d final = {10, 10};

	t_coord_2d initial2 = {500, 500};
	t_coord_2d final2 = {900, 700};
	// bresenham_lower_slope(initial, final, img);
	// bresenham_upper_slope(initial, final, img);
	bresenham(initial, final, layer);
	bresenham(initial2, final2, layer);
	mlx_put_image_to_window(mlx, mlx_win, layer.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
