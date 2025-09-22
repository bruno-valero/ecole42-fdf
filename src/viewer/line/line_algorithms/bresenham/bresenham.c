/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:50:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/22 19:57:25 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"
#include "minilibx.h"

static void	bresenham_lower_slope(
				t_coord_2d initial, t_coord_2d final,
				t_minilib_layer layer, t_minilib_window window);
static void	bresenham_upper_slope(
				t_coord_2d initial, t_coord_2d final,
				t_minilib_layer layer, t_minilib_window window);

void	bresenham(t_coord_2d initial, t_coord_2d final,
				t_minilib_layer layer, t_minilib_window window)
{
	int		delta_x;
	int		delta_y;
	float	slope;

	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	slope = delta_y / delta_x;
	if (abs_float(slope) > 1)
		bresenham_upper_slope(initial, final, layer, window);
	else
		bresenham_lower_slope(initial, final, layer, window);
}

static void	bresenham_lower_slope(
				t_coord_2d initial, t_coord_2d final,
				t_minilib_layer layer, t_minilib_window window)
{
	t_pixel	pixel;
	int		delta_x;
	int		delta_y;
	int		decision;

	pixel = make_pixel(&layer, coord_2d(initial.x, initial.y), 0x00FF0000);
	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	decision = (2 * abs_nbr(delta_y)) - abs_nbr(delta_x);
	while (loop_condition(pixel.coord.x, initial.x, final.x))
	{
		put_pixel(pixel, window);
		add_direction(&pixel.coord.x, delta_x);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(delta_y);
		else
		{
			decision = decision + 2 * abs_nbr(delta_y) - 2 * abs_nbr(delta_x);
			add_direction(&pixel.coord.y, delta_y);
		}
	}

}

static void	bresenham_upper_slope(
				t_coord_2d initial, t_coord_2d final,
				t_minilib_layer layer, t_minilib_window window)
{
	t_pixel	pixel;
	int		delta_x;
	int		delta_y;
	int		decision;

	pixel = make_pixel(&layer, coord_2d(initial.x, initial.y), 0x00FF0000);
	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	decision = (2 * abs_nbr(delta_x)) - abs_nbr(delta_y);
	while (loop_condition(pixel.coord.y, initial.y, final.y))
	{
		put_pixel(pixel, window);
		add_direction(&pixel.coord.y, delta_y);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(delta_x);
		else
		{
			decision = decision + 2 * abs_nbr(delta_x) - 2 * abs_nbr(delta_y);
			add_direction(&pixel.coord.x, delta_x);
		}
	}

}
