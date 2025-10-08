/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 23:22:52 by valero            #+#    #+#             */
/*   Updated: 2025/10/07 20:59:46 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_file.h"

static void						init_matrix_data(
									t_input_point **matrix_data,
									int matrix_height);
static int						handle_parse_point(
									t_parser_matrix *parser_matrix,
									t_reader_list_node *matrix_point,
									t_coord_2d matrix_coord);

t_parser_matrix	*parse_matrix(t_reader_matrix *rmatrix,
					t_parser_matrix **pmatrix)
{
	t_reader_matrix_node	*matrix_line;
	t_reader_list_node		*matrix_point;
	t_coord_2d				matrix_coord;

	*pmatrix = new_parser_matrix(pmatrix);
	(*pmatrix)->data = malloc((rmatrix->height + 1) * sizeof(t_input_point *));
	init_matrix_data((*pmatrix)->data, rmatrix->height);
	matrix_line = rmatrix->top;
	matrix_coord.y = -1;
	while (matrix_coord.y++, matrix_line)
	{
		matrix_point = matrix_line->list->top;
		(*pmatrix)->data[matrix_coord.y] = malloc(
				rmatrix->width * sizeof(t_input_point));
		matrix_coord.x = -1;
		while (matrix_coord.x++, matrix_point)
		{
			if (!handle_parse_point(*pmatrix, matrix_point, matrix_coord))
				return (NULL);
			matrix_point = matrix_point->next;
		}
		matrix_line = matrix_line->next;
	}
	return (*pmatrix);
}

static int	handle_parse_point(t_parser_matrix *parser_matrix,
		t_reader_list_node *matrix_point, t_coord_2d matrix_coord)
{
	t_parse_point_response	parse_point_response;
	int						x;
	int						y;

	x = matrix_coord.x;
	y = matrix_coord.y;
	parse_point_response = parse_point(matrix_point->str, matrix_coord);
	if (!parse_point_response.parser_succeeded)
		return (!!parser_matrix->destroy(parser_matrix));
	parser_matrix->data[y][x] = parse_point_response.point;
	if (parser_matrix->bigger_z < parser_matrix->data[y][x].coord.z)
		parser_matrix->bigger_z = parser_matrix->data[y][x].coord.z;
	if (parser_matrix->lower_z > parser_matrix->data[y][x].coord.z)
		parser_matrix->lower_z = parser_matrix->data[y][x].coord.z;
	parser_matrix->height = y + 1;
	parser_matrix->width = x + 1;
	return (1);
}

static void	init_matrix_data(t_input_point **matrix_data, int matrix_height)
{
	while (matrix_height)
	{
		matrix_data[matrix_height] = NULL;
		matrix_height--;
	}
}
