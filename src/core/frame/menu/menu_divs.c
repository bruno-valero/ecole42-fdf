/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_divs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:12:35 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/13 20:25:43 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

void	render_menu_title(t_state *state, int ajust_y)
{
	viewer_put_str(state, coord_2d(90, 60 + ajust_y), 0x999999,
		"Press 'M' to close menu...");
	viewer_put_str(state, coord_2d(25, 80 + ajust_y), 0x999999,
		"--------------------------------------------------");
	viewer_put_str(state, coord_2d(35, 100 + ajust_y), 0x999999,
		"FDF -> Bruno Fernandes Valero Nunes (brunofer)");
	viewer_put_str(state, coord_2d(25, 120 + ajust_y), 0x999999,
		"--------------------------------------------------");
}

void	render_menu_actions(t_state *state, int ajust_y)
{
	viewer_put_str(state, coord_2d(35, 160 + ajust_y),
		0x999999, "          Actions                 ");
	viewer_put_str(state, coord_2d(35, 170 + ajust_y),
		0x999999, "    ----------------------------");
	viewer_put_str(state, coord_2d(55, 190 + ajust_y),
		0x999999, "Increase z_factor: Press '+'");
	viewer_put_str(state, coord_2d(55, 210 + ajust_y),
		0x999999, "Decrease z_factor: Press '-'");
	viewer_put_str(state, coord_2d(55, 230 + ajust_y),
		0x999999, "Auto Rotate x:     Press 'x'");
	viewer_put_str(state, coord_2d(55, 250 + ajust_y),
		0x999999, "Auto Rotate y:     Press 'y'");
	viewer_put_str(state, coord_2d(55, 270 + ajust_y),
		0x999999, "Auto Rotate z:     Press 'z'");
}

void	render_menu_projections(t_state *state, int ajust_y)
{
	viewer_put_str(state, coord_2d(35, 310 + ajust_y),
		0x999999, "          Projections                 ");
	viewer_put_str(state, coord_2d(35, 320 + ajust_y),
		0x999999, "    ----------------------------");
	viewer_put_str(state, coord_2d(55, 340 + ajust_y),
		0x999999, "Isometric:         Press '1'");
	viewer_put_str(state, coord_2d(55, 360 + ajust_y),
		0x999999, "Top-Down:          Press '2'");
	viewer_put_str(state, coord_2d(55, 380 + ajust_y),
		0x999999, "Left Side:         Press '3'");
	viewer_put_str(state, coord_2d(55, 400 + ajust_y),
		0x999999, "Front:             Press '4'");
}

void	render_menu_modes(t_state *state, int ajust_y)
{
	viewer_put_str(state, coord_2d(35, 440 + ajust_y),
		0x999999, "          Modes                 ");
	viewer_put_str(state, coord_2d(35, 450 + ajust_y),
		0x999999, "    ----------------------------");
	viewer_put_str(state, coord_2d(55, 470 + ajust_y),
		0x999999, "Shadow:            Press 'S'");
	viewer_put_str(state, coord_2d(55, 490 + ajust_y),
		0x999999, "Low Resolution:    Press 'L'");
	viewer_put_str(state, coord_2d(55, 510 + ajust_y),
		0x999999, "High Resolution:   Press 'H'");
}
