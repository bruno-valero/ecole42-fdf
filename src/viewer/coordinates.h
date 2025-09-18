/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:29:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 14:38:17 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_H
# define COORDINATES_H

typedef struct s_coord_2d
{
	int	x;
	int	y;
}	t_coord_2d;

typedef struct s_coord_3d
{
	int	x;
	int	y;
	int	z;
}	t_coord_3d;

t_coord_2d	coord_2d(int x, int y);
t_coord_3d	coord_3d(int x, int y, int z);

#endif
