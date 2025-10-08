/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:55:51 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/07 20:53:02 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int	get_color(t_input_point point);

t_point	new_colorized_point(void)
{
	t_point	new_point;

	new_point.x = 0;
	new_point.y = 0;
	new_point.z = 0;
	new_point.color.value = LINE_COLOR;
	return (new_point);
}

t_point	colorize_point(t_input_point point)
{
	t_point	new_point;

	if (point.has_color)
		new_point.color.value = point.color;
	else
	{
		// if (point.coord.z <= 0)
		// 	new_point.color.value = BG_COLOR;
		// else
		// 	new_point.color.value = LINE_COLOR;
		new_point.color.value = get_color(point);
	}
	new_point.x = point.coord.x;
	new_point.y = point.coord.y;
	new_point.z = point.coord.z;
	return (new_point);
}

static int	get_color(t_input_point point)
{
	t_state	*state;
	int		z_range;
	int		diff_from_lower_z;
	double	relation;

	state = get_state();
	z_range = state->parsed_data->bigger_z
		- state->parsed_data->lower_z;
	diff_from_lower_z = point.coord.z
		- state->parsed_data->lower_z;
	relation = (double)diff_from_lower_z / (double)z_range;
	if (relation > 1.0)
		relation = 1.0;
	else if (relation < 0.0)
		relation = 0.0;
	return (interpolate_color(
			new_color(BG_COLOR), new_color(LINE_COLOR), relation));
}
