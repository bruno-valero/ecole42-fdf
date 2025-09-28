/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:53:45 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/28 19:38:13 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_parse_point_response	parse_point(const char *str,
									t_coord_2d matrix_coord);
static t_matrix					*reader_matrix_to_parser_matrix(
									t_reader_matrix *reader_matrix,
									t_matrix **parser_matrix);
static int						handle_parse_point(t_matrix *parser_matrix,
									t_reader_list_node *matrix_point,
									t_coord_2d matrix_coord);

t_matrix	*parser(char *file_path, t_matrix **parser_matrix)
{
	t_reader_matrix	*reader_matrix;

	reader_matrix = read_file(file_path, &reader_matrix);
	if (!reader_matrix)
		return (NULL);
}

static t_matrix	*reader_matrix_to_parser_matrix(
					t_reader_matrix *reader_matrix, t_matrix **parser_matrix)
{
	t_reader_matrix_node	*matrix_line;
	t_reader_list_node		*matrix_point;
	t_coord_2d				matrix_coord;
	t_parse_point_response	parse_point_response;

	*parser_matrix = new_parser_matrix(parser_matrix);
	matrix_line = reader_matrix->top;
	matrix_coord.y = -1;
	while (matrix_coord.y++, matrix_line)
	{
		matrix_point = matrix_line->list->top;
		matrix_coord.x = -1;
		(*parser_matrix)->data[matrix_coord.y] = malloc(
				(reader_matrix->height + 1) * sizeof(t_input_point *));
		while (matrix_coord.x++, matrix_point)
		{
			if (!handle_parse_point(parser_matrix, matrix_point, matrix_coord))
				return (NULL);
			matrix_point = matrix_point->next;
		}
		matrix_line = matrix_line->next;
	}
}

static void	fill_point(t_input_point *point, char **splitted,
				t_coord_2d matrix_coord, int *result)
{
	char	*color_hexa;

	point->coord = coord_3d(
			matrix_coord.x, matrix_coord.y, ft_atoi(splitted[0]));
	point->has_color = 1;
	color_hexa = ft_str_tolower(&splitted[1][2]);
	point->color = ft_atoi_base(color_hexa, "0123456789abcdef");
	*result = 1;
	free(color_hexa);
	ft_destroy_char_matrix(splitted);
}

static	t_parse_point_response	parse_point_response_init(void)
{
	t_parse_point_response	response;

	response.parser_succeeded = 0;
	response.point.color = 0;
	response.point.has_color = 0;
	response.point.coord = coord_3d(0, 0, 0);
	return (response);
}

static t_parse_point_response	parse_point(
		const char *str, t_coord_2d matrix_coord)
{
	t_parse_point_response	response;
	char					**splitted;
	int						result;
	char					*hex;

	response = parse_point_response_init();
	if (!str || !*str)
		return (response);
	splitted = ft_split(str, ',');
	if (!ft_str_isdigit(splitted[0]))
		result = 0;
	else if (!splitted[1])
		response.point.has_color = 0;
	else if (!ft_str_ishexa(splitted[1], "0x"))
		result = 0;
	else
		fill_point(&response.point, splitted, matrix_coord, &result);
	if (result)
		response.parser_succeeded = 1;
	return (response);
}

static int	handle_parse_point(t_matrix *parser_matrix,
	t_reader_list_node *matrix_point, t_coord_2d matrix_coord)
{
	t_parse_point_response	parse_point_response;

	parse_point_response = parse_point(matrix_point->str, matrix_coord);
	if (!parse_point_response.parser_succeeded)
	{
		// TODO: destroy(parser_matrix);
		return (0);
	}
	parser_matrix->data[matrix_coord.y][matrix_coord.x]
		= parse_point_response.point;
}
