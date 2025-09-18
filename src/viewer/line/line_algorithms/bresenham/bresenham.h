/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:31:29 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 15:53:08 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "coordinates.h"
# include "bresenham_utils.h"

void	bresenham(t_coord_2d initial, t_coord_2d final, t_minilib_layer img);

#endif
