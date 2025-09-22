/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:54:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/22 20:05:44 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_UTILS_H
# define BRESENHAM_UTILS_H

float			abs_float(float nbr);
unsigned int	abs_nbr(int nbr);
void			add_direction(int *curr_position, int delta_direction);
int				loop_condition(int x, int x_start, int x_end);

#endif
