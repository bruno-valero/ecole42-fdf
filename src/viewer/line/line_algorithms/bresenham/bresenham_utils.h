/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:54:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 14:59:12 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_UTILS_H
# define BRESENHAM_UTILS_H

inline float			abs_float(float nbr);
inline unsigned int	abs_nbr(int nbr);
inline void			add_direction(int *curr_position, int delta_direction);
inline int			loop_condition(int x, int x_start, int x_end);

#endif
