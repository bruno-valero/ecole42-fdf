/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 15:04:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LINE_H
# define LINE_H

# include "coordinates.h"
# include "bresenham.h"

typedef struct s_line
{
	t_coord_2d	initial_point;
	t_coord_2d	final_point;
}	t_line;


#endif
