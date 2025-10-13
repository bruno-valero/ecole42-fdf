/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:55:51 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/12 21:28:49 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int	get_color(t_state *state, t_point point);

t_point	new_colorized_point(void)
{
	t_point	new_point;

	new_point.x = 0;
	new_point.y = 0;
	new_point.z = 0;
	new_point.color.value = LINE_COLOR;
	return (new_point);
}

t_point	colorize_point(t_state *state, t_point *point)
{
	point->color.value = get_color(state, *point);
	return (*point);
}

static int	get_color(t_state *state, t_point point)
{
	int		z_range;
	int		diff_from_lower_z;
	double	relation;

	z_range = state->parsed_data->bigger_z
		- state->parsed_data->lower_z;
	diff_from_lower_z = point.z
		- state->parsed_data->lower_z;
	relation = (double)diff_from_lower_z / (double)z_range;
	if (relation > 1.0)
		relation = 1.0;
	else if (relation < 0.0)
		relation = 0.0;
	return (interpolate_color(
			new_color(FAINT_COLOR), new_color(LINE_COLOR), relation));
}
