/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:31:29 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/22 19:58:58 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "coordinates.h"
# include "bresenham_utils.h"
# include "minilibx.h"

void	bresenham(t_coord_2d initial, t_coord_2d final,
			t_minilib_layer layer, t_minilib_window window);

#endif
