/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:05:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/01 23:07:42 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "coordinates.h"
# include "lines.h"
# include "viewer.h"
# include "parse_file.h"

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

typedef struct s_frame_context			t_frame_context;
struct s_frame_context
{
	t_parser_matrix	*mtx;
	t_coord_2d		curr_coord;
	t_lines			*lines;
	t_camera		*camera;
};

t_camera	create_camera(void);
void		reset_camera(t_frame_context frame);

#endif
