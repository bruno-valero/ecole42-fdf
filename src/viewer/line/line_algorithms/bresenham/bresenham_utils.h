/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:54:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/08 16:26:36 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_UTILS_H
# define BRESENHAM_UTILS_H

# include "point.h"
# include "line.h"
# include "minilibx.h"
# include <math.h>

float			abs_float(float nbr);
unsigned int	abs_nbr(int nbr);
void			update_pixel(int *curr_position, int delta_direction);
int				loop_condition(int x, int x_start, int x_end);
void			update_pixel_color(t_pixel *pixel, t_line line, int *pace);

#endif
