/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/01 22:52:53 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_LINES_H
# define BUILD_LINES_H

# include "coordinates.h"
# include "lines.h"
# include "viewer.h"
# include "parse_file.h"
# include "camera.h"

t_lines	build_lines(
			char *file_path, t_viewer_context viwer_context, t_camera *camera,
			void (*update_line)(t_frame_context frame)
			);


#endif
