/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 23:22:52 by valero            #+#    #+#             */
/*   Updated: 2025/09/29 00:30:14 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	(*pmatrix)->data[rmatrix->height] = NULL;
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

static t_parse_point_response	parse_point(const char *str,
									t_coord_2d matrix_coord);

static int	handle_parse_point(t_parser_matrix *parser_matrix,
		t_reader_list_node *matrix_point, t_coord_2d matrix_coord)
{
	t_parse_point_response	parse_point_response;

	parse_point_response = parse_point(matrix_point->str, matrix_coord);
	if (!parse_point_response.parser_succeeded)
		return (!!parser_matrix->destroy(parser_matrix));
	parser_matrix->data[matrix_coord.y][matrix_coord.x]
		= parse_point_response.point;
	parser_matrix->height = matrix_coord.y + 1;
	parser_matrix->width = matrix_coord.x + 1;
	return (1);
}

static t_parse_point_response	parse_point_response_init(void);
static void						fill_point(t_input_point *point,
									char ***splitted, t_coord_2d matrix_coord,
									int *result);

static t_parse_point_response	parse_point(const char *str,
									t_coord_2d matrix_coord)
{
	t_parse_point_response	response;
	char					**splitted;
	int						result;

	response = parse_point_response_init();
	if (!str || !*str)
		return (response);
	splitted = ft_split(str, ',');
	if (!ft_str_isdigit(splitted[0]))
		result = 0;
	else if (splitted[1] && !ft_str_ishexa(splitted[1], "0x"))
		result = 0;
	else
		fill_point(&response.point, &splitted, matrix_coord, &result);
	response.parser_succeeded = result;
	return (response);
}

static t_parse_point_response	parse_point_response_init(void)
{
	t_parse_point_response	response;

	response.parser_succeeded = 0;
	response.point.color = 0;
	response.point.has_color = 0;
	response.point.coord = coord_3d(0, 0, 0);
	return (response);
}

static void	fill_point(t_input_point *point, char ***splitted,
				t_coord_2d matrix_coord, int *result)
{
	char	*color_hexa;

	color_hexa = NULL;
	point->coord = coord_3d(
			matrix_coord.x, matrix_coord.y, ft_atoi((*splitted)[0]));
	if ((*splitted)[1])
	{
		point->has_color = 1;
		color_hexa = ft_str_tolower(&(*splitted)[1][2]);
		point->color = ft_atoi_base(color_hexa, "0123456789abcdef");
		free(color_hexa);
	}
	ft_destroy_char_matrix(splitted);
	*result = 1;
}
