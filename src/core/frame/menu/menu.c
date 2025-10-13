/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:09:33 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/13 20:48:38 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

void	render_menu_info(t_state *state)
{
	viewer_put_str(state, coord_2d(50, 150),
		0xffffff, "Press 'M' to open menu...");
}

void	render_menu_text(t_state *state)
{
	int	ajust_y;

	ajust_y = 50;
	render_menu_title(state, ajust_y);
	render_menu_actions(state, ajust_y);
	render_menu_projections(state, ajust_y);
	render_menu_modes(state, ajust_y);
}

void	render_menu_bg(t_state *state)
{
	t_minilib_window	window;
	int					menu_width;
	int					menu_height;
	t_pixel				pixel;

	window = state->viewer_context.window;
	menu_width = 400;
	menu_height = window.height;
	pixel = make_pixel(coord_2d(0, 0), 0x444444);
	while (pixel.coord.y <= menu_height)
	{
		pixel.coord.x = 0;
		while (pixel.coord.x <= menu_width)
		{
			put_pixel(pixel, state->viewer_context);
			pixel.coord.x += 2;
		}
		pixel.coord.y += 2;
	}
}

void	viewer_put_str(t_state *state, t_coord_2d coord, int color, char *str)
{
	t_minilib_window	window;

	window = state->viewer_context.window;
	mlx_string_put(
		window.mlx_ref,
		window.ref,
		coord.x,
		coord.y,
		color,
		str);
}
