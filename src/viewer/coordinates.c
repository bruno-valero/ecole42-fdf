/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:26:02 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 15:24:10 by brunofer         ###   ########.fr       */
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
