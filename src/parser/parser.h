/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/27 18:09:02 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "reader.h"
# include "coordinates.h"

typedef struct s_input_point
{
	t_coord_3d	coord;
	int			has_color;
	int			color;
}	t_input_point;


typedef struct s_matrix
{
	int				height;
	int				width;
	t_input_point	***data;
}	t_matrix;

#endif
