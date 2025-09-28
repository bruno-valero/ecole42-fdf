/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/28 19:38:21 by valero           ###   ########.fr       */
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

typedef struct s_matrix	t_matrix;

struct s_matrix
{
	int				height;
	int				width;
	t_matrix		**self_ref;
	t_input_point	**data;
	void			*(*destroy)(t_matrix *self);
};

typedef struct s_parse_point_response
{
	int				parser_succeeded;
	t_input_point	point;
}	t_parse_point_response;

t_matrix	*parser(char *file_path, t_matrix **parser_matrix);
t_matrix	*new_parser_matrix(t_matrix **matrix_ref);

#endif
