/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:05:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 20:21:45 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "coordinates.h"
# include "lines.h"
# include "viewer.h"
# include "parse_file.h"
# include <math.h>

typedef struct s_angle					t_angle;
struct s_angle
{
	double	x;
	double	cos_x;
	double	sin_x;
	double	y;
	double	cos_y;
	double	sin_y;
	double	z;
	double	cos_z;
	double	sin_z;
};

typedef struct s_camera					t_camera;
struct s_camera
{
	t_coord_2d_double	offset;
	t_angle				angle;
	t_coord_3d			auto_rotate;
	double				z_factor;
	double				scale;
	double				scale_width;
	double				scale_height;
	int					line_tracer;
	int					projection;
};

t_camera	create_camera(void);

#endif
