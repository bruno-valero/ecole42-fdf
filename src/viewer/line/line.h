/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/29 15:33:36 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "coordinates.h"
# include "bresenham.h"
# include "line_interface.h"

t_line	new_line(t_coord_2d initial_point,
			t_coord_2d final_point, t_minilib_layer layer);
void	draw_line(t_line line, t_minilib_window window,
			void (*algorithm)(t_line line, t_minilib_window window));

#endif
