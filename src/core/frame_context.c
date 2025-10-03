/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_context.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:00:52 by valero            #+#    #+#             */
/*   Updated: 2025/10/02 13:40:04 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame_context.h"

t_frame_context	frame_context(
		t_parser_matrix *mtx, t_coord_2d curr_coord,
		t_lines *lines, t_camera *camera)
{
	t_frame_context	frame;

	frame.camera = camera;
	frame.curr_coord = curr_coord;
	frame.lines = lines;
	frame.mtx = mtx;
	return (frame);
}
