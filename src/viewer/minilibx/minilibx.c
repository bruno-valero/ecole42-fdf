/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:26:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 16:21:22 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

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
	dst = pixel.layer->addr + (pixel.coord.y * pixel.layer->line_length + pixel.coord.x * (pixel.layer->bits_per_pixel / 8));
	*(unsigned int *)dst = pixel.color;
}

t_minilib_window	new_window(void *mlx_ref, int width, int height, char *name)
{
	void				*ref;
	t_minilib_window	window;

	window.ref = mlx_new_window(mlx_ref, width, height, name);
	window.height = height;
	window.width = width;
	window.name = name;
}
