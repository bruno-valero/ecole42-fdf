/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:26:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/22 21:50:38 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

static void	destroy_window(t_minilib_window self);
static void	destroy_layer(t_minilib_layer self);

t_pixel	make_pixel(t_minilib_layer *layer, t_coord_2d coord, int color)
{
	t_pixel	pixel;

	pixel.layer = layer;
	pixel.coord = coord;
	pixel.color = color;
	return (pixel);
}

void	put_pixel(t_pixel pixel, t_minilib_window window)
{
	char	*dst;

	if (pixel.coord.y < 0 || pixel.coord.y > window.height)
		return ;
	if (pixel.coord.x < 0 || pixel.coord.x > window.height)
		return ;
	dst = pixel.layer->addr + (
			pixel.coord.y * pixel.layer->line_length
			+ pixel.coord.x * (pixel.layer->bits_per_pixel / 8)
			);
	*(unsigned int *)dst = pixel.color;
}

t_minilib_window	new_window(void *mlx_ref, int width, int height, char *name)
{
	t_minilib_window	window;

	window.destroy = destroy_window;
	window.mlx_ref = mlx_ref;
	window.ref = mlx_new_window(mlx_ref, width, height, name);
	window.height = height;
	window.width = width;
	window.name = name;
	return (window);
}

static void	destroy_window(t_minilib_window self)
{
	mlx_destroy_window(self.mlx_ref, self.ref);
	free(self.ref);
}

t_minilib_layer	new_layer(t_minilib_window window, int width, int height)
{
	t_minilib_layer	layer;

	layer.destroy = destroy_layer;
	layer.mlx_ref = window.mlx_ref;
	layer.img = mlx_new_image(layer.mlx_ref, width, height);
	layer.addr = mlx_get_minilib_layer_addr(layer.img, &layer.bits_per_pixel,
			&layer.line_length, &layer.endian);
	return (layer);
}

static void	destroy_layer(t_minilib_layer self)
{
	mlx_destroy_image(self.mlx_ref, self.img);
	free(self.img);
}
