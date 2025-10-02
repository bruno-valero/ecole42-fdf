/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:26:02 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 17:26:13 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinates.h"

t_coord_2d	coord_2d(int x, int y)
{
	t_coord_2d	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

t_coord_3d	coord_3d(int x, int y, int z)
{
	t_coord_3d	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}

t_coord_2d_double	coord_2d_double(double x, double y)
{
	t_coord_2d_double	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

t_coord_3d_double	coord_3d_double(double x, double y, double z)
{
	t_coord_3d_double	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}
