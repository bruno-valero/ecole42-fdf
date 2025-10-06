/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:24:50 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/06 19:40:09 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	new_point(t_coord_3d coord, int color)
{
	t_point	point;

	point.x = coord.x;
	point.y = coord.y;
	point.z = coord.z;
	point.color.value = color;
	return (point);
}
