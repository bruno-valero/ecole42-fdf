/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:24:50 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/07 20:32:45 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	new_point(t_coord_3d coord, int color)
{
	t_point	point;

	point.x = coord.x;
	point.y = coord.y;
	point.z = coord.z;
	point.color = new_color(color);
	return (point);
}

t_color	new_color(int color)
{
	t_color	result_color;

	result_color.parts.r = 0;
	result_color.parts.g = 0;
	result_color.parts.b = 0;
	result_color.parts.a = 0;
	result_color.value = color;
	return (result_color);
}

int	interpolate_color(
		t_color initial_color, t_color final_color, double relation)
{
	t_color	color;

	color.parts.r = initial_color.parts.r
		+ relation * (final_color.parts.r - initial_color.parts.r);
	color.parts.g = initial_color.parts.g
		+ relation * (final_color.parts.g - initial_color.parts.g);
	color.parts.b = initial_color.parts.b
		+ relation * (final_color.parts.b - initial_color.parts.b);
	color.parts.a = 0;
	return (color.value);
}
