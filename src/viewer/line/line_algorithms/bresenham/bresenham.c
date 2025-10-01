/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:50:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/30 22:26:13 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"
#include "minilibx.h"

static void	bresenham_lower_slope(t_line line, t_minilib_window window);
static void	bresenham_upper_slope(t_line line, t_minilib_window window);

void	bresenham(t_line line, t_minilib_window window)
{
	int		delta_x;
	int		delta_y;
	float	slope;

	delta_x = line.final_point.x - line.initial_point.x;
	delta_y = line.final_point.y - line.initial_point.y;
	if (!delta_x)
		slope = 2;
	else
		slope = delta_y / delta_x;
	if (abs_float(slope) > 1)
		bresenham_upper_slope(line, window);
	else
		bresenham_lower_slope(line, window);
}

static void	bresenham_lower_slope(t_line line, t_minilib_window window)
{
	t_pixel		pixel;
	int			delta_x;
	int			delta_y;
	int			decision;
	t_coord_2d	coordinate;

	coordinate = coord_2d(line.initial_point.x, line.initial_point.y);
	pixel = make_pixel(&line.layer, coordinate, 0x00FF0000);
	delta_x = line.final_point.x - line.initial_point.x;
	delta_y = line.final_point.y - line.initial_point.y;
	decision = (2 * abs_nbr(delta_y)) - abs_nbr(delta_x);
	while (loop_condition(
			pixel.coord.x, line.initial_point.x, line.final_point.x))
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

static void	bresenham_upper_slope(t_line line, t_minilib_window window)
{
	t_pixel		pixel;
	int			delta_x;
	int			delta_y;
	int			decision;
	t_coord_2d	coordinate;

	coordinate = coord_2d(line.initial_point.x, line.initial_point.y);
	pixel = make_pixel(&line.layer, coordinate, 0x00FF0000);
	delta_x = line.final_point.x - line.initial_point.x;
	delta_y = line.final_point.y - line.initial_point.y;
	decision = (2 * abs_nbr(delta_x)) - abs_nbr(delta_y);
	while (loop_condition(
			pixel.coord.y, line.initial_point.y, line.final_point.y))
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
