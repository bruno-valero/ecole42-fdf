/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:59:29 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 16:31:12 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_line.h"

static void	update_scale(t_line *curr_line);
static void	update_offset(t_line *curr_line);

void	update_line(t_line *curr_line)
{
	t_line	newer_line;

	newer_line = *curr_line;
	update_scale(&newer_line);
	update_rotation(&newer_line);
	update_offset(&newer_line);
	*curr_line = new_line(newer_line.initial_point, newer_line.final_point);
}

static void	update_scale(t_line *curr_line)
{
	double	scale_width;
	double	scale_height;
	t_state	*state;

	state = get_state();
	scale_width = state->camera.scale_width;
	scale_height = state->camera.scale_height;
	curr_line->initial_point.x *= scale_width * state->camera.scale;
	curr_line->initial_point.y *= scale_height * state->camera.scale;
	curr_line->final_point.x *= scale_width * state->camera.scale;
	curr_line->final_point.y *= scale_height * state->camera.scale;
}

static void	update_offset(t_line *curr_line)
{
	t_state	*state;

	state = get_state();
	curr_line->initial_point.x += state->camera.offset.x;
	curr_line->initial_point.y += state->camera.offset.y;
	curr_line->final_point.x += state->camera.offset.x;
	curr_line->final_point.y += state->camera.offset.y;
}
