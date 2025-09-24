/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:31:29 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/24 11:43:31 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "coordinates.h"
# include "bresenham_utils.h"
# include "line_interface.h"
# include "minilibx.h"

typedef struct s_line	t_line;

void	bresenham(t_line line, t_minilib_window window);

#endif
