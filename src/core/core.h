/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/09/30 16:24:37 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "coordinates.h"
# include "viewer.h"
# include "parse_file.h"

typedef struct s_camera	t_camera;

struct s_camera
{
	int		x_offset;
	int		y_offset;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	double	z_factor;
	double	scale;
	double	scale_width;
	double	scale_height;
	int		line_tracer;
	int		projection;
	int		auto_rotate_x;
	int		auto_rotate_y;
	int		auto_rotate_z;
};

#endif
