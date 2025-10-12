/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/12 12:01:52 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "coordinates.h"

typedef struct s_rgb	t_rgb;

struct s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;

};

typedef union u_color
{
	int		value;
	t_rgb	parts;
}	t_color;

typedef struct s_point	t_point;

struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
};

t_point	new_point(t_coord_3d coord, int color);
t_color	new_color(int color);
int		interpolate_color(
			t_color initial_color, t_color final_color, double relation);

#endif
