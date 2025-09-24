/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/24 11:49:16 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LINE_INTERFACE_H
# define LINE_INTERFACE_H

# include "coordinates.h"
# include "minilibx.h"

typedef struct s_line	t_line;

struct s_line
{
	t_coord_2d		initial_point;
	t_coord_2d		final_point;
	t_minilib_layer	layer;
};


#endif
