/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:24:50 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/24 11:58:27 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	new_line(t_coord_2d initial_point,
			t_coord_2d final_point, t_minilib_layer layer)
{
	t_line	line;

	line.initial_point = initial_point;
	line.final_point = final_point;
	line.layer = layer;
	return (line);
}

void	draw_line(t_line line, t_minilib_window window,
		void (*algorithm)(t_line line, t_minilib_window window))
{
	algorithm(line, window);
}
