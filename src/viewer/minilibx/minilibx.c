/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:26:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 04:36:16 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"
#include "viewer_context.h"

static void	destroy_window(t_minilib_window self);

t_pixel	make_pixel(t_coord_2d coord, int color)
{
	t_pixel	pixel;

	pixel.coord = coord;
	pixel.color.parts.r = 0;
	pixel.color.parts.g = 0;
	pixel.color.parts.b = 0;
	pixel.color.parts.a = 0;
	pixel.color.value = color;
	return (pixel);
}

void	put_pixel(
		t_pixel pixel, t_viewer_context viwer_context)
{
	char			*dst;
	t_minilib_layer	layer;

	layer = viwer_context.wireframe;
	if (pixel.coord.y < 0 || pixel.coord.y > viwer_context.window.height)
		return ;
	if (pixel.coord.x < 0 || pixel.coord.x > viwer_context.window.width)
		return ;
	dst = layer.addr + (
			pixel.coord.y * layer.line_length
			+ pixel.coord.x * (layer.bits_per_pixel / 8)
			);
	*(unsigned int *)dst = pixel.color.value;
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
	// free(self.ref);
}
