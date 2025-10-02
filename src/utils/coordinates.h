/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:29:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 17:26:47 by valero           ###   ########.fr       */
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

typedef struct s_coord_2d_double
{
	double	x;
	double	y;
}	t_coord_2d_double;

typedef struct s_coord_3d_double
{
	double	x;
	double	y;
	double	z;
}	t_coord_3d_double;

t_coord_2d			coord_2d(int x, int y);
t_coord_3d			coord_3d(int x, int y, int z);
t_coord_2d_double	coord_2d_double(double x, double y);
t_coord_3d_double	coord_3d_double(double x, double y, double z);

#endif
