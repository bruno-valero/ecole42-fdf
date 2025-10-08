/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:54:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/07 21:07:28 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham_utils.h"

static int	get_bigger(int first, int second)
{
	if (first > second)
		return (first);
	return (second);
}

void	update_pixel_color(t_pixel *pixel, t_line line, int *pace)
{
	double	color_relation;
	int		bigger_delta;

	bigger_delta = get_bigger(line.delta.x, line.delta.y);
	color_relation = (double)(*pace) / (double)bigger_delta;
	pixel->color.value = interpolate_color(
			line.initial_point.color, line.final_point.color, color_relation);
	(*pace)++;
}
