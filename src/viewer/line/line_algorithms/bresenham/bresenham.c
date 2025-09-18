/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:50:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 15:53:08 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"
#include "minilibx.h"

static void	bresenham_lower_slope(
				t_coord_2d initial, t_coord_2d final, t_minilib_layer img);
static void	bresenham_upper_slope(
				t_coord_2d initial, t_coord_2d final, t_minilib_layer img);

void	bresenham(t_coord_2d initial, t_coord_2d final, t_minilib_layer img)
{
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;
	float	slope;

	x = initial.x;
	y = initial.y;
	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	slope = delta_y / delta_x;
	if (abs_float(slope) > 1)
		bresenham_upper_slope(initial, final, img);
	else
		bresenham_lower_slope(initial, final, img);
}

static void	bresenham_lower_slope(
				t_coord_2d initial, t_coord_2d final, t_minilib_layer img)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	decision;

	x = initial.x;
	y = initial.y;
	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	decision = (2 * abs_nbr(delta_y)) - abs_nbr(delta_x);
	while (loop_condition(x, initial.x, final.x))
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		add_direction(&x, delta_x);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(delta_y);
		else
		{
			decision = decision + 2 * abs_nbr(delta_y) - 2 * abs_nbr(delta_x);
			add_direction(&y, delta_y);
		}
	}

}

static void	bresenham_upper_slope(
				t_coord_2d initial, t_coord_2d final, t_minilib_layer img)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	decision;

	x = initial.x;
	y = initial.y;
	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	decision = (2 * abs_nbr(delta_x)) - abs_nbr(delta_y);
	while (loop_condition(y, initial.y, final.y))
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		add_direction(&y, delta_y);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(delta_x);
		else
		{
			decision = decision + 2 * abs_nbr(delta_x) - 2 * abs_nbr(delta_y);
			add_direction(&x, delta_x);
		}
	}

}
