/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_context.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/01 21:33:13 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_CONTEXT_H
# define FRAME_CONTEXT_H

# include "coordinates.h"
# include "viewer.h"
# include "parse_file.h"
# include "camera.h"


typedef struct s_lines					t_lines;

typedef struct s_frame_context			t_frame_context;

struct s_frame_context
{
	t_parser_matrix	*mtx;
	t_coord_2d		curr_coord;
	t_lines			*lines;
	t_camera		*camera;
};

t_lines	build_lines(
			char *file_path, t_viewer_context viwer_context, t_camera *camera,
			void (*update_line)(t_frame_context dependency)
			);


#endif
