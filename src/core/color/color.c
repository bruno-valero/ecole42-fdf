/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:55:51 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/06 19:29:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_point	new_colorized_point(void)
{
	t_point	new_point;

	new_point.color.value = 0xffffff;
	new_point.x = 0;
	new_point.y = 0;
	new_point.z = 0;
	return (new_point);
}

t_point	colorize_point(t_input_point point)
{
	t_point	new_point;

	if (point.has_color)
		new_point.color.value = point.color;
	else
		new_point.color.value = 0xffffff;
	new_point.x = point.coord.x;
	new_point.y = point.coord.y;
	new_point.z = point.coord.z;
	return (new_point);
}
