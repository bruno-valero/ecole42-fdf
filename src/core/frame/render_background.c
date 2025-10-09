/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:24:50 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 15:58:41 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_background.h"

void	render_background(t_state	*state)
{
	t_minilib_window	window;
	int					width;
	int					height;
	t_pixel				pixel;

	window = state->viewer_context.window;
	height = -1;
	while (++height < window.height)
	{
		width = -1;
		while (++width < window.width)
		{
			pixel = make_pixel(coord_2d(width, height), BG_COLOR);
			put_pixel(pixel, state->viewer_context, WIREFRAME_LAYER);
		}
	}

}
