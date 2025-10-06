/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_context.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/05 20:00:55 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_CONTEXT_H
# define FRAME_CONTEXT_H

# include "coordinates.h"
# include "camera.h"
# include "parse_file.h"

typedef struct s_camera					t_camera;

typedef struct s_lines					t_lines;

typedef struct s_frame_context			t_frame_context;

struct s_frame_context
{
	t_parser_matrix	*mtx;
	t_coord_2d		curr_coord;
	t_lines			*lines;
	t_camera		*camera;
};

t_frame_context	frame_context(
					t_parser_matrix *mtx, t_coord_2d curr_coord,
					t_lines *lines, t_camera *camera);

#endif
