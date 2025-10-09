/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:50:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/09 15:24:09 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

static void	bresenham_lower_slope(t_line line, t_viewer_context viwer_context);
static void	bresenham_upper_slope(t_line line, t_viewer_context viwer_context);
static void	upd_pixel(t_pixel *pixel, t_line line, int *pace, char add_coord);

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
	t_coord_2d	coordinate;
	int			decision;
	int			pace;

	pace = 0;
	coordinate = coord_2d(line.initial_point.x, line.initial_point.y);
	pixel = make_pixel(coordinate, line.initial_point.color.value);
	decision = (2 * abs_nbr(line.delta.y)) - abs_nbr(line.delta.x);
	while (loop_condition(
			pixel.coord.x, line.initial_point.x, line.final_point.x))
	{
		put_pixel(pixel, viwer_context, WIREFRAME_LAYER);
		// update_pixel(&pixel.coord.x, line.delta.x);
		upd_pixel(&pixel, line, &pace, 'x');
		if (decision < 0)
			decision = decision + 2 * abs_nbr(line.delta.y);
		else
		{
			decision = decision + 2 * abs_nbr(line.delta.y)
				- 2 * abs_nbr(line.delta.x);
			// update_pixel(&pixel.coord.y, line.delta.y);
			upd_pixel(&pixel, line, &pace, 'y');
		}
	}
}

static void	bresenham_upper_slope(t_line line, t_viewer_context viwer_context)
{
	t_pixel		pixel;
	t_coord_2d	coordinate;
	int			decision;
	int			pace;

	pace = 0;
	coordinate = coord_2d(line.initial_point.x, line.initial_point.y);
	pixel = make_pixel(coordinate, line.initial_point.color.value);
	decision = (2 * abs_nbr(line.delta.x)) - abs_nbr(line.delta.y);
	while (loop_condition(
			pixel.coord.y, line.initial_point.y, line.final_point.y))
	{
		put_pixel(pixel, viwer_context, WIREFRAME_LAYER);
		// update_pixel(&pixel.coord.y, line.delta.y);
		upd_pixel(&pixel, line, &pace, 'y');
		if (decision < 0)
			decision = decision + 2 * abs_nbr(line.delta.x);
		else
		{
			decision = decision + 2 * abs_nbr(line.delta.x)
				- 2 * abs_nbr(line.delta.y);
			// update_pixel(&pixel.coord.x, line.delta.x);
			upd_pixel(&pixel, line, &pace, 'x');
		}
	}
}

static void	got_to_next_pixel(
			t_pixel *pixel, t_line line, char add_coord)
{
	int		*position;
	int		delta_direction;

	if (add_coord == 'x')
	{
		position = &pixel->coord.x;
		delta_direction = line.delta.x;
	}
	else
	{
		position = &pixel->coord.y;
		delta_direction = line.delta.y;
	}
	if (delta_direction > 0)
		(*position)++;
	else
		(*position)--;
}

static void	upd_pixel(t_pixel *pixel, t_line line, int *pace, char add_coord)
{
	if (!(add_coord == 'x' || add_coord == 'y'))
		return ;
	got_to_next_pixel(pixel, line, add_coord);
	update_pixel_color(pixel, line, pace);
}
