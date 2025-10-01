/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_layer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:26:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 02:16:27 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

static void	destroy_layer(t_minilib_layer self);

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
	// free(self.img);
}

void	put_layer(t_minilib_window window, t_minilib_layer layer)
{
	mlx_put_image_to_window(layer.mlx_ref, window.ref, layer.img, 0, 0);
}
