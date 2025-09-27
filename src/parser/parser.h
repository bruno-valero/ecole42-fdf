/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/26 20:08:03 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "reader.h"

typedef struct s_input_point
{
	int	x;
	int	y;
	int	z;
	int	has_color;
	int	color;
}	t_input_point;


typedef struct s_array
{
	int				length;
	t_input_point	*data;
}	t_array;


typedef struct s_matrix
{
	int				height;
	int				width;
	t_input_point	**array;
}	t_matrix;

#endif
