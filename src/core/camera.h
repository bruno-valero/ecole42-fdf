/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:05:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/05 19:22:34 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "coordinates.h"
# include "lines.h"
# include "viewer.h"
# include "parse_file.h"
# include "frame_context.h"
# include <math.h>

typedef struct s_camera					t_camera;

struct s_camera
{
	t_coord_2d			offset;
	t_coord_3d_double	angle;
	double				z_factor;
	double				scale;
	double				scale_width;
	double				scale_height;
	int					line_tracer;
	int					projection;
	t_coord_3d			auto_rotate;
};

t_camera	create_camera(void);
void		reset_camera(t_camera *camera, t_viewer_context context,
				t_parser_matrix *mtx);

#endif
