/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:26:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 15:09:29 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"
#include "viewer_context.h"

static void	destroy_window(t_minilib_window self);

t_pixel	make_pixel(t_coord_2d coord, int color)
{
	t_pixel	pixel;

	pixel.coord = coord;
	pixel.color = color;
	return (pixel);
}

void	put_pixel(t_pixel pixel, t_viewer_context viwer_context)
{
	char	*dst;

	if (pixel.coord.y < 0 || pixel.coord.y > viwer_context.window.height)
		return ;
	if (pixel.coord.x < 0 || pixel.coord.x > viwer_context.window.height)
		return ;
	dst = viwer_context.layer.addr + (
			pixel.coord.y * viwer_context.layer.line_length
			+ pixel.coord.x * (viwer_context.layer.bits_per_pixel / 8)
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
	// free(self.ref);
}
