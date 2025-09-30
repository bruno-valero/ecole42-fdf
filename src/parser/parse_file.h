/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/29 15:27:09 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_H
# define PARSE_FILE_H

# include <fcntl.h>
# include "reader.h"
# include "coordinates.h"

typedef struct s_input_point
{
	t_coord_3d	coord;
	int			has_color;
	int			color;
}	t_input_point;

typedef struct s_matrix	t_parser_matrix;

struct s_matrix
{
	int				height;
	int				width;
	t_parser_matrix	**self_ref;
	t_input_point	**data;
	void			(*print)(t_parser_matrix *self);
	void			*(*destroy)(t_parser_matrix *self);
};

typedef struct s_parse_point_response
{
	int				parser_succeeded;
	t_input_point	point;
}	t_parse_point_response;

t_parse_point_response	parse_point(const char *str,
							t_coord_2d matrix_coord);
t_parser_matrix			*parse_matrix(t_reader_matrix *rmatrix,
							t_parser_matrix **pmatrix);
t_parser_matrix			*parse_file(char *file_path,
							t_parser_matrix **parser_matrix);
t_parser_matrix			*new_parser_matrix(t_parser_matrix **matrix_ref);

#endif
