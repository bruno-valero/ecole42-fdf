/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:54:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 14:48:30 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham_utils.h"

int	get_bigger(int first, int second)
{
	if (abs_nbr(first) > abs_nbr(second))
		return (abs_nbr(first));
	return (abs_nbr(second));
}

void	update_pixel_color(t_pixel *pixel, t_line line, int *pace)
{
	double	color_relation;
	double	bigger_delta;

	bigger_delta = abs_nbr(line.delta.x) + abs_nbr(line.delta.y);
	color_relation = (double)(*pace) / bigger_delta;
	pixel->color.value = interpolate_color(
			line.initial_point.color, line.final_point.color, color_relation);
	(*pace)++;
}
