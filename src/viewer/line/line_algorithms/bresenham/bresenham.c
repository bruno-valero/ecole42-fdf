/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:50:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 23:41:58 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

static void	bresenham_lower_slope(t_line line, t_viewer_context viwer_context);
static void	bresenham_upper_slope(t_line line, t_viewer_context viwer_context);

void	bresenham(t_line line, t_viewer_context viwer_context)
{
	if (abs_float(line.slope) > 1)
		bresenham_upper_slope(line, viwer_context);
	else
		bresenham_lower_slope(line, viwer_context);
}

static void	bresenham_lower_slope(t_line line, t_viewer_context viwer_context)
{
	t_pixel		pixel;
	int			decision;
	t_coord_2d	coordinate;

	coordinate = coord_2d(line.initial_point.x, line.initial_point.y);
	pixel = make_pixel(coordinate, 0x00FF0000);
	decision = (2 * abs_nbr(line.delta.y)) - abs_nbr(line.delta.x);
	while (loop_condition(
			pixel.coord.x, line.initial_point.x, line.final_point.x))
	{
		put_pixel(pixel, viwer_context);
		go_to_next_pixel(&pixel.coord.x, line.delta.x);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(line.delta.y);
		else
		{
			decision = decision + 2 * abs_nbr(line.delta.y)
				- 2 * abs_nbr(line.delta.x);
			go_to_next_pixel(&pixel.coord.y, line.delta.y);
		}
	}
}

static void	bresenham_upper_slope(t_line line, t_viewer_context viwer_context)
{
	t_pixel		pixel;
	int			decision;
	t_coord_2d	coordinate;

	coordinate = coord_2d(line.initial_point.x, line.initial_point.y);
	pixel = make_pixel(coordinate, 0x00FF0000);
	decision = (2 * abs_nbr(line.delta.x)) - abs_nbr(line.delta.y);
	while (loop_condition(
			pixel.coord.y, line.initial_point.y, line.final_point.y))
	{
		put_pixel(pixel, viwer_context);
		go_to_next_pixel(&pixel.coord.y, line.delta.y);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(line.delta.x);
		else
		{
			decision = decision + 2 * abs_nbr(line.delta.x)
				- 2 * abs_nbr(line.delta.y);
			go_to_next_pixel(&pixel.coord.x, line.delta.x);
		}
	}
}
