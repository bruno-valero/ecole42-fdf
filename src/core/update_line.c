/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:59:29 by valero            #+#    #+#             */
/*   Updated: 2025/10/05 21:30:42 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_line.h"

static void	update_scale(t_frame_context frame, t_line *curr_line);
static void	update_offset(t_frame_context frame, t_line *curr_line);

void	update_line(t_frame_context frame, t_line *curr_line)
{
	t_line	newer_line;

	newer_line = *curr_line;
	update_scale(frame, &newer_line);
	update_rotation(frame, &newer_line);
	update_offset(frame, &newer_line);
	*curr_line = new_line(newer_line.initial_point, newer_line.final_point);
}

static void	update_scale(t_frame_context frame, t_line *curr_line)
{
	double	scale_width;
	double	scale_height;

	scale_width = frame.camera->scale_width;
	scale_height = frame.camera->scale_height;
	curr_line->initial_point.x *= scale_width * frame.camera->scale;
	curr_line->initial_point.y *= scale_height * frame.camera->scale;
	curr_line->final_point.x *= scale_width * frame.camera->scale;
	curr_line->final_point.y *= scale_height * frame.camera->scale;
}

static void	update_offset(t_frame_context frame, t_line *curr_line)
{
	curr_line->initial_point.x += frame.camera->offset.x;
	curr_line->initial_point.y += frame.camera->offset.y;
	curr_line->final_point.x += frame.camera->offset.x;
	curr_line->final_point.y += frame.camera->offset.y;
}
